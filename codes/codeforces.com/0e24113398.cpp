// 链接: https://codeforces.com/contest/2205/problem/A
// 日期: 2026年02月26日

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
    int n; cin >> n;
    vector<int> arrp(n);
    int max = -1;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> arrp[i];
        if (arrp[i] > max) {
            max = arrp[i];
            maxi = i;
        }
    }
    
    if (maxi != 0) {
        swap(arrp[0], arrp[maxi]);
        for (int i : arrp) {
            cout << i << " ";
        }
    } else {
        for (int i : arrp) {
            cout << i << " ";
        }
    }
    cout << "\n";

}