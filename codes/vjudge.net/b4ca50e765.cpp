// 链接: https://vjudge.net/problem/OpenJ_Bailian-4001
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

void slove() {
    int n, k;
    cin >> n >> k;
    
    queue<int> viw;
    vector<int> timer(1e6 + 1);
    viw.push(n);

    while (!viw.empty())
    {
        int ni = viw.front(); viw.pop();
        if (ni == k) {
            cout << timer[ni];
            return;
        }

        if (ni + 1 <= 1e6 && !timer[ni + 1]) {
            timer[ni + 1] = timer[ni] + 1;
            viw.push(ni + 1);
        }
        if (ni - 1 <= 1e6 && !timer[ni - 1]) {
            timer[ni - 1] = timer[ni] + 1;
            viw.push(ni - 1);
        }
        if (ni * 2 <= 1e6 && ni > 0 && !timer[ni * 2]) {
            timer[ni * 2] = timer[ni] + 1;
            viw.push(ni * 2);
        }
    }
}