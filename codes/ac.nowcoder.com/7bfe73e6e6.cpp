// 链接: https://ac.nowcoder.com/acm/contest/128672/E
// 日期: 2026年02月22日

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

int reverse(int n) {
    int r = 0;
    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

vector<int> vis(1000005);
vector<int> dep(1000005);
int index = 0;

void slove() {
    int a, b, k; cin >> a >> b >> k;
    index++;

    if (a == b) {
        cout << "0\n";
        return;
    }

    int maxx = 1;
    while (maxx <= b) {
        maxx *= 10;
    }
    maxx -= 1;

    if (a > maxx) {
        cout << "-1\n";
        return;
    }

    queue<int> que;
    que.push(a);
    vis[a] = index;
    dep[a] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        int k1 = cur + k;
        if (k1 < maxx && vis[k1] != index) {
            vis[k1] = index;
            dep[k1] = dep[cur] + 1;
            if (k1 == b) {
                cout << dep[cur] + 1 << "\n";
                return;
            }
            que.push(k1);
        }

        if (cur % 10 != 0) {
            int k2 = reverse(cur);
            if (k2 < maxx && vis[k2] != index) {
                vis[k2] = index;
                dep[k2] = dep[cur] + 1;
                if (k2 == b) {
                    cout << dep[k2] << "\n";
                    return;
                }
                que.push(k2);
            }
        }
    }

    cout << "-1\n";
}