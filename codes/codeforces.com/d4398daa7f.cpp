// 链接: https://codeforces.com/contest/2193/problem/C
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
    int n, q;
    cin >> n >> q;

    vector<int> arra(n + 2, 0), arrb(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arra[i] = a;
    }
    for (int i = 1; i <= n; i++) {
        int b; cin >> b;
        arra[i] = max(b, arra[i]);
    }

    int gmax = 0;
    for (int i = n; i >= 1; i--) {
        gmax = max(arra[i], gmax);
        arrb[i] = gmax;
    }

    for (int i = 1; i <= n; i++) {
        arrb[i] = arrb[i] + arrb[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if (i != 0) cout << " ";
        cout << arrb[r] - arrb[l - 1];
    }

    cout << "\n";
}