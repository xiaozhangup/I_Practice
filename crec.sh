#!/usr/bin/env bash
set -euo pipefail
IFS=$'\n\t'

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
TEMPLATE_FILE="$SCRIPT_DIR/temple.cpp"
BASE_DIR="$SCRIPT_DIR/codes"

if [[ ! -f "$TEMPLATE_FILE" ]]; then
  echo "模板不存在: $TEMPLATE_FILE" >&2
  exit 1
fi

if ! command -v code >/dev/null 2>&1; then
  echo "未找到 'code' 命令（VS Code CLI）。请先确保已安装并在 PATH 中。" >&2
  exit 1
fi

url="${1-}"
if [[ -z "$url" ]]; then
  read -r -p "请输入URL: " url
fi

if [[ -z "$url" ]]; then
  echo "URL 不能为空" >&2
  exit 1
fi

normalize_url() {
  local u="$1"
  # 去掉首尾空白
  u="${u#${u%%[![:space:]]*}}"
  u="${u%${u##*[![:space:]]}}"
  printf '%s' "$u"
}

extract_host() {
  local u="$1"

  if command -v python3 >/dev/null 2>&1; then
    python3 - "$u" <<'PY'
import sys
from urllib.parse import urlparse
u = sys.argv[1].strip()
if '://' not in u:
    u = 'https://' + u
p = urlparse(u)
host = p.hostname or ''
print(host)
PY
    return 0
  fi

  # 纯 bash 兜底解析：支持有/无 scheme
  u="${u#*://}"
  u="${u%%/*}"
  u="${u%%\?*}"
  u="${u%%#*}"
  u="${u%%:*}"  # 去端口
  printf '%s' "$u"
}

hash_url() {
  local u="$1"
  if command -v sha256sum >/dev/null 2>&1; then
    printf '%s' "$u" | sha256sum | awk '{print $1}'
    return 0
  fi
  if command -v shasum >/dev/null 2>&1; then
    printf '%s' "$u" | shasum -a 256 | awk '{print $1}'
    return 0
  fi
  # 最低限度兜底（非加密强度，仅用于命名稳定性）
  python3 - "$u" <<'PY'
import hashlib,sys
print(hashlib.sha256(sys.argv[1].encode('utf-8')).hexdigest())
PY
}

url="$(normalize_url "$url")"
host="$(extract_host "$url")"

if [[ -z "$host" ]]; then
  echo "无法从 URL 提取域名/主机名: $url" >&2
  exit 1
fi

hex="$(hash_url "$url")"
short="${hex:0:10}"

dir="$BASE_DIR/$host"
mkdir -p "$dir"

target="$dir/$short.cpp"

if [[ ! -f "$target" ]]; then
  today="$(date '+%Y年%m月%d日')"
  tmp="$target.tmp.$$"
  {
    printf '// 链接: %s\n' "$url"
    printf '// 日期: %s\n\n' "$today"
    cat "$TEMPLATE_FILE"
  } > "$tmp"
  mv "$tmp" "$target"
fi

code -g "$target"
