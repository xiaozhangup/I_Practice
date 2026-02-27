// 链接: https://codeforces.com/contest/2200/problem/B
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

vector<int> next_smaller(vector<int>& a) {
    int n = a.size();
    vector<int> r(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            r[st.top()] = i;
            st.pop();
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

vector<int> prev_smaller(vector<int>& a) {
    int n = a.size();
    vector<int> r(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            r[i] = st.top();
        }
        st.push(i);
    }
    return r;
}

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

void slove() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool any = false;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            any = true;
            break;
        }
    }

    if (any) cout << "1\n";
    else cout << n << "\n";
}