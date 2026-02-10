// 链接: https://codeforces.com/gym/106290/problem/E
// 日期: 2026年01月30日

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

// 2 1 2
// 1 2 1
// 0 1 2 | 2 1 0
// 1 0 1 | 1 0 1
// 0 1 0 | 0 1 0

// 2 4 2

void slove() {
    int C, S, D; cin >> C >> S >> D;
    
    while(true) {
        if (C == S && S == D) {
            cout << "NO\n";
            return;
        }

        
    }
}