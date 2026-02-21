// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1160
// 日期: 2026年02月21日

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
    int N; cin >> N;

    vector<int> L(N+1, 0), R(N+1, 0);
    vector<char> inQueue(N+1, 0);
    int head = 0, tail = 0;

    head = tail = 1;
    L[1] = R[1] = 0;
    inQueue[1] = 1;
    for (int i = 2; i <= N; i++) {
        int k, p; cin >> k >> p;
        inQueue[i] = 1;
        if (p == 0) {
            L[i] = L[k];
            R[i] = k;
            L[k] = i;
            if (L[i] != 0) R[L[i]] = i;
            else head = i;
        } else {
            L[i] = k;
            R[i] = R[k];
            R[k] = i;
            if (R[i] != 0) L[R[i]] = i;
            else tail = i;
        }
    }
    
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        if (x < 1 || x > N) continue;
        if (!inQueue[x]) continue;
        if (L[x] != 0) R[L[x]] = R[x];
        else head = R[x];
        if (R[x] != 0) L[R[x]] = L[x];
        else tail = L[x];
        inQueue[x] = 0;
        L[x] = R[x] = 0;
    }

    bool first = true;
    for (int cur = head; cur != 0; cur = R[cur]) {
        if (!first) cout << ' ';
        cout << cur;
        first = false;
    }
    cout << '\n';
}