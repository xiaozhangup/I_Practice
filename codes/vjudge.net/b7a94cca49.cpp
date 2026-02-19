// 链接: https://vjudge.net/problem/CodeForces-1765M
// 日期: 2026年02月19日

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
#include <numeric>
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

#define int long long

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void slove() {
    int n; cin >> n;
    
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << "\n";
        return;
    }

    int min = 1e9;
    int res = 0;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            int g = n / i;
            cout << g << " " << n - g << "\n";
            return;
        }
    }

    cout << 1 << " " << n - 1 << "\n";
}