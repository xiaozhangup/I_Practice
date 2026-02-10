// 链接: https://ac.nowcoder.com/acm/contest/120562/F
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

void slove() {
    int n; cin >> n;
    
    int bo = 0;
    int minx = 1LL << 62;
    int rx, ry;
    while (true)
    {
        int x = n << bo;
        int y = x + n;
        if (y < 0) break;
        bo++;
        if (gcd(x, y) != n) continue;
        if (minx > (x ^ y)) {
            minx = (x ^ y);
            rx = x;
            ry = y;
        }
    }


    cout << rx << " " << ry << "\n";
}