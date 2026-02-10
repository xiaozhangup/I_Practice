// 链接: https://ac.nowcoder.com/acm/contest/127702/D
// 日期: 2026年02月08日

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
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int a, b; cin >> a >> b;
    switch (b) {
        case 0:
            if (a & 1) cout << "1 11";
            else cout << "10 11";
            break;
        case 1:
            cout << "1 9";
            break;
        case 2:
            cout << "2 9";
            break;
        case 3:
            cout << "1 3";
            break;
        case 4:
            cout << "4 9";
            break;
        case 5:
            cout << "5 9";
            break;
        case 6:
            cout << "2 3";
            break;
        case 7:
            cout << "7 9";
            break;
        case 8:
            cout << "8 9";
            break;
        case 9:
            if (a & 1) cout << "10 11";
            else cout << "1 11";
            break;
    }
    cout << "\n";
}