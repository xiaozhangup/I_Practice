// 链接: https://ac.nowcoder.com/acm/contest/120561/L
// 日期: 2026年02月03日

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

void slove() {
    string s; cin >> s;
    char ending = s.back();

    switch (ending)
    {
    case '0':
        cout << "1\n";
        break;
    case '1':
        cout << "10\n";
        break;
    case '2':
        cout << "5\n";
        break;
    case '3':
        cout << "10\n";
        break;
    case '4':
        cout << "5\n";
        break;
    case '5':
        cout << "2\n";
        break;
    case '6':
        cout << "5\n";
        break;
    case '7':
        cout << "10\n";
        break;
    case '8':
        cout << "5\n";
        break;
    case '9':
        cout << "10\n";
        break;
    default:
        break;
    }
}