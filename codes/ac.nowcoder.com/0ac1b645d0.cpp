// 链接: https://ac.nowcoder.com/acm/contest/120564/A
// 日期: 2026年02月09日

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
    int n; cin >> n;
    map<int, int> counter;
    int ggsum = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        counter[a]++;
        ggsum += a;
    }

    int suma = 0;
    int sumb = 0;

    int index = 0;
    for (auto pa : counter) {
        int amo = pa.second;
        int iner = pa.first;
        index += amo;

        if (((double) (index - 1) / (double) (n - 1)) >= 0.8) {
            suma += iner * amo;
        } else {
            sumb += iner * amo;
        }
    }

    cout << suma;
}