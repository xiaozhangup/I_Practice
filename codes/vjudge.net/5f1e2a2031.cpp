// 链接: https://vjudge.net/problem/HDU-5358
// 日期: 2026年02月15日

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

#define int long long

void slove() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = arr[i];
        pref[i] += pref[i - 1];
    }
    int res = 0;
    
    for (int j = 1; j <= n; j++) {
        int term = j * j + j * (j + 1) / 2;
        res += term;
    }

    for (int k = 1; k <= 60; k++) {
        int limit = 1LL << k;
        if (limit > pref[n]) break;

        int ptr = -1;
        for (int j = 1; j <= n; j++) {
            int target = pref[j] - limit;
            while (ptr + 1 < j && pref[ptr + 1] <= target)
            {
                ptr++;
            }

            if (ptr >= 0) {
                int count = ptr + 1;
                int sumx = (int)ptr * (ptr + 1) / 2;

                int ctr = sumx + count * (j + 1);
                res += ctr;
            }
        }
    }


    cout << res;
    cout << "\n";
}