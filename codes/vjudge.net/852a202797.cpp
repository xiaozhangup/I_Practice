// 链接: https://vjudge.net/problem/HDU-1260
// 日期: 2026年02月18日

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
    int k; cin >> k;
    vector<int> arrs(k);
    for (int i = 0; i < k; i++) {
        cin >> arrs[i];
    }

    vector<int> arrb(k - 1);
    for (int i = 0; i < k - 1; i++) {
        cin >> arrb[i];
    }

    vector<int> dp(k + 1, 0);
    dp[1] = arrs[0];
    for (int i = 2; i <= k; i++) {
        dp[i] = dp[i - 1] + arrs[i - 1];
        dp[i] = min(dp[i], dp[i - 2] + arrb[i - 2]);
    }

    int fin = dp[k];

    int hour = fin / 60 / 60 + 8;
    int min = (fin / 60) % 60;
    int sec = fin % 60;

    string ind = "";
    if (hour >= 12) {
        ind += "pm";
        hour -= 12;
    }
    else ind += "am";

    printf("%.2d:%.2d:%.2d %s\n", hour, min, sec, ind.c_str());

}