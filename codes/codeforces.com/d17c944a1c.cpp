// 链接: https://codeforces.com/contest/2205/problem/D
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

vector<int> prev_greater(vector<int>& a) {
    int n = a.size();
    vector<int> r(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            r[i] = st.top();
        }
        st.push(i);
    }
    return r;
}

vector<int> next_greater(vector<int>& a) {
    int n = a.size();
    vector<int> r(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return r;
}

void slove() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto l = prev_greater(arr);
    vector<int> dpL(n, 1);
    for (int i = 0; i < n; i++) {
        if (l[i] != -1) dpL[i] = dpL[l[i]] + 1;
    }

    auto r = next_greater(arr);
    vector<int> dpR(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        if (r[i] != -1) dpR[i] = dpR[r[i]] + 1;
    }

    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, dpL[i] + dpR[i] - 1);
    }
    
    // 7 4 10 12 9 14 5 3 8 11 1 15 2 13 6
    //        --   --       --   --   --
    // 7 4 10 12   14            15

    // 6 5 1 7 4 2 3
    //       -
    // 6 5 1 7

    cout << n - maxx;
    cout << "\n";
}