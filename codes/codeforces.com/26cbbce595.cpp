// 链接: https://codeforces.com/contest/2200/problem/E
// 日期: 2026年02月28日

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

const int N = 1000000;
int spf[N];

void linear_sieve() {
    iota(spf, spf + N, 0);
    for (int i = 2; i * i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int getMinP(int n) {
    if (n == 1) return 1;
    return spf[n];
}

int getMaxP(int n) {
    if (n == 1) return 1;
    int p = 1;
    while (n > 1) {
        p = spf[n];
        n /= p;
    }
    return p;
}

bool isPrimePower(int n) {
    if (n == 1) return true;
    int p = spf[n];
    while (n % p == 0) {
        n /= p;
    }
    return n == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    linear_sieve();
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

    bool srd = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (i > 0 && arr[i] < arr[i - 1]) {
            srd = false;
        }
    }

    if (srd) {
        cout << "Bob\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (getMaxP(arr[i]) > getMinP(arr[i + 1])) {
            cout << "Alice\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!isPrimePower(arr[i])) {
            cout << "Alice\n";
            return;
        }
    }

    cout << "Bob\n";
}