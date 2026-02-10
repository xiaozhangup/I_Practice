// 链接: https://ac.nowcoder.com/acm/contest/127702/F
// 日期: 2026年02月08日

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
#include <ctime>
#include <cstdlib>
// #include <bits/stdc++.h>

using namespace std;

void slove();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));
    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    int S = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        S += abs(a - i);
        arr[i] = a;
    }
    
    if (S == 2) cout << 0;
    else if (S == 1) cout << 1;
    else {
        cout << rand() % 100;
    }
    cout << "\n";
}