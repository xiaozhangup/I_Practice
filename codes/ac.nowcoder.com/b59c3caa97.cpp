// 链接: https://ac.nowcoder.com/acm/contest/120562/H
// 日期: 2026年02月05日

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
    map<int, int> lp;
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        int cc = i - lp[a];
        int len = n - i + 1;
        
        sum += cc * (len * (len + 1) / 2);
        lp[a] = i;
    }
    
    cout << sum << "\n";
}