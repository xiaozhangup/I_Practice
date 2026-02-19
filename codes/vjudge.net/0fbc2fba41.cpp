// 链接: https://vjudge.net/problem/HDU-1069
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

void slove(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    int n;
    while (cin >> n) {
        if (n == 0) break;;
        slove(n);
    }
}

#define ll long long

struct Cube {
    int x, y, z;
};

int index = 0;
void slove(int n) {
    index++;
    cout << "Case " << index << ": maximum height = ";
    vector<Cube> cubes(3 * n);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        
        cubes[i * 3 + 2] = {max(y, z), min(y, z), x};
        cubes[i * 3 + 1] = {max(x, z), min(x, z), y};
        cubes[i * 3 + 0] = {max(x, y), min(x, y), z};
    }
    
    int res = 0;
    sort(cubes.begin(), cubes.end(), [](const Cube& a, const Cube& b) {
        int s1 = a.x * a.y;
        int s2 = b.x * b.y;
        return s1 > s2;
    });

    int m = n * 3;
    vector<int> dp(m);

    for (int i = 0; i < m; i++) {
        dp[i] = cubes[i].z;

        for (int k = 0; k < i; k++) {
            if (cubes[i].x < cubes[k].x && cubes[i].y < cubes[k].y) {
                dp[i] = max(dp[i], dp[k] + cubes[i].z);
            }
        }

        res = max(res, dp[i]);
    }

    cout << res << "\n";
}