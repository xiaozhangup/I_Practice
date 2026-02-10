// 链接: https://codeforces.com/gym/106290/problem/B
// 日期: 2026年01月30日

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

vector<vector<char>> arr(5, vector<char>(5, '0'));

int searchLink(int x, int y) {
    int res = 1;

    bool cont = false;
    int sumv = 0;
    int maxv = 0;
    for (int i = -3; i <= 3; i++) {
        int offx = x + i;
        if (offx >= 0 && offx <= 4) {
            if (arr[offx][y] == '1') {
                if (cont) {
                    sumv++;
                    maxv = max(maxv, sumv);
                }
                else {
                    cont = true;
                    sumv = 1;
                }
            } else {
                cont = false;
            }
        }
    }
    res = max(res, maxv);

    cont = false;
    sumv = 0;
    maxv = 0;
    for (int i = -3; i <= 3; i++) {
        int offx = y + i;
        if (offx >= 0 && offx <= 4) {
            if (arr[x][offx] == '1') {
                if (cont) {
                    sumv++;
                    maxv = max(maxv, sumv);
                }
                else {
                    cont = true;
                    sumv = 1;
                }
            } else {
                cont = false;
            }
        }
    }
    res = max(res, maxv);

    cont = false;
    sumv = 0;
    maxv = 0;
    for (int i = -3; i <= 3; i++) {
        int offx = x + i;
        int offy = y - i;
        if (offx >= 0 && offx <= 4 && offy >= 0 && offy <= 4) {
            if (arr[offx][offy] == '1') {
                if (cont) {
                    sumv++;
                    maxv = max(maxv, sumv);
                }
                else {
                    cont = true;
                    sumv = 1;
                }
            } else {
                cont = false;
            }
        }
    }
    res = max(res, maxv);

    cont = false;
    sumv = 0;
    maxv = 0;
    for (int i = -3; i <= 3; i++) {
        int offx = x + i;
        int offy = y + i;
        if (offx >= 0 && offx <= 4 && offy >= 0 && offy <= 4) {
            if (arr[offx][offy] == '1') {
                if (cont) {
                    sumv++;
                    maxv = max(maxv, sumv);
                }
                else {
                    cont = true;
                    sumv = 1;
                }
            } else {
                cont = false;
            }
        }
    }
    res = max(res, maxv);

    return res;
}

void slove() {
    for (int i = 0; i < 5; i++) {

        bool anyf = false;
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') anyf = true;
        }

        if (!anyf) {
            cout << "Bingo!";
            return;
        }
    }

    for (int i = 0; i < 5; i++) {
        bool anyf = false;
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] == '0') anyf = true;
        }

        if (!anyf) {
            cout << "Bingo!";
            return;
        }
    }

    bool anyfa = false, anyfb = false;
    for (int i = 0; i < 5; i++) {
        if (arr[i][i] == '0') anyfa = true;
        if (arr[i][4 - i] == '0') anyfb = true;
    }
    if (!anyfa || !anyfb) {
        cout << "Bingo!";
        return;
    }

    int soc = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char s = arr[i][j];
            if (s == '0') continue;

            int re = searchLink(i, j);
            // cout << re << "\n"; // debug
            if (re == 4) soc += 3;
            else if (re == 3) soc += 2;
            else soc += 1;
        }
    }
    cout << soc;    
}