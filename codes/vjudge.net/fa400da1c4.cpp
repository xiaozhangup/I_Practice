// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1036
// 日期: 2026年01月31日

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
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

vector<int> primes;
void get_primes(int up = 10000) {
    vector<bool> is(up + 1, true);
    for (int i = 2; i <= up; ++i) {
        if (is[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p > up) break;
            is[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

unordered_map<int, bool> memo;
bool isPrime(int x) {
    if (x < 2) return false;
    if (memo.count(x)) return memo[x];
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) return memo[x] = false;
    }
    return memo[x] = true;
}

int n, k;
int sum = 0;
vector<int> arr(30);
vector<int> prefs(30);

void dfs(int step, int stri) {
    if (step == k + 1) {
        int s = prefs[k];
        if (isPrime(s)) sum++;
        return;
    }

    for (int i = stri; i <= n; i++) {
        int nu = arr[i];
        prefs[step] = prefs[step - 1] + nu;
        dfs(step + 1, i + 1);
        prefs[step] = 0;
    }
}

void slove() {
    get_primes();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] = x;
    }

    dfs(1, 1);
    cout << sum;
}