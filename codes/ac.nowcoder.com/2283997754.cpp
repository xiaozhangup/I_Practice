// 链接: https://ac.nowcoder.com/acm/contest/120562/I
// 日期: 2026年02月05日

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
// #include <bits/stdc++.h>

using namespace std;

void slove();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

int offx[] = {0, 0, 1, -1};
int offy[] = {1, -1, 0, 0};

void slove() {
    int n, m; cin >> n >> m;

    int cum0 = 0, cum1 = 0;
    vector<vector<char>> mapping(n + 2, vector<char>(m + 2, ' ')); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            mapping[i][j] = c;

            if (c == '0') cum0++;
            else cum1++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mapping[i][j] == '0') {
                if (cum0 > 1) cout << 'Y';
                else cout << 'N';
            } else {
                if (cum1 > 1) cout << 'Y';
                else cout << 'N';
            }
        }
        cout << "\n";
    }
}