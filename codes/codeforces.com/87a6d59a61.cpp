// 链接: https://codeforces.com/contest/2200/problem/A
// 日期: 2026年02月27日

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[i] = a;
    }

    unordered_set<int> res;
    for (int i = 0; i < n; i++) { // start 0
        vector<int> rr = arr;
        int last = i;

        while (true) {
            bool anyNot = false;
            for (int b = 0; b < n; b++) {
                if (rr[b] > 0) {
                    anyNot = true;
                    break;
                }
            }

            if (!anyNot) {
                break;
            }

            if (rr[last] > 0) {
                rr[last]--;
            }

            last = (last + 1) % n;
        }
        
        res.insert(last);
    }

    cout << res.size() << "\n";
}