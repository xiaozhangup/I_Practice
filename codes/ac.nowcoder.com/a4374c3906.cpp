// 链接: https://ac.nowcoder.com/acm/contest/128675/C
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
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    map<int, int> cot;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] ^= i;
        cot[arr[i]]++;
    }

    int max = 0;
    for (auto p : cot) {
        if (p.second > max) {
            max = p.second;
        }
    }

    cout << n - max;

}