// 链接: https://ac.nowcoder.com/acm/contest/128675/D
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

#define int long long

void slove() {
    int m, c, q; cin >> m >> c >> q;
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        
        vector<int> vis(m, -1);
        bool succes = false;
        while (true) {
            if (x == c) {
                succes = true;
                break;
            }
            if (x > c) {
                succes = false;
                break;
            }

            int rem = x % m;
            if (vis[rem] == -1) {
                vis[rem] = x;
                x += arr[rem];
            } else {
                int ring = x - vis[rem];
                if (ring == 0) {
                    succes = false;
                    break;
                }

                int xx = vis[rem];
                int rrem = rem;
                bool foun = false;
                do {
                    if (c >= xx && (c - xx) % ring == 0) {
                        foun = true;
                        break;
                    }

                    xx += arr[rrem];
                    rrem = xx % m;
                } while (rrem != rem);

                succes = foun;
                break;
            }
        }
        
        if (succes) cout << "Yes\n";
        else cout << "No\n";
    }
}