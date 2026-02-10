// 链接: https://codeforces.com/contest/2193/problem/0
// 日期: 2026年01月25日

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

void slove() {
    int n, s, x; cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
    }

    int sr = s - sum;
    int sa = sr % x;
    if (sa == 0 && sum <= s) cout << "YES\n";
    else cout << "NO\n";


}