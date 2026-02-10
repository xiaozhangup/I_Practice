// 链接: https://codeforces.com/contest/2193/problem/B
// 日期: 2026年01月25日

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

bool sortss(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void slove() {
    int n; cin >> n;
    int arr[n];
    vector<pair<int, int>> indx(n);

    int max_nu = 0;
    int max_ind = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        arr[i] = p;

        if (max_nu < p) {
            if (max_ind + 1 != i) {
                max_nu = p;
                max_ind = i;
            }
        }
        indx[i] = {p, i};
    }
    sort(indx.begin(), indx.end(), sortss);

    int index = 0;
    int begin = 0;
    int end = 0;

    for (auto aw : indx) {
        if (aw.second == index++) continue;

        end = aw.second;
        for (int v = 0; v <= end; v++) {
            if (arr[v] > indx[index].first) continue;
            else {
                begin = v;
                break;
            }
        }
        break;
    }

    // if (begin != 0 && end != 0) {
        // cout << begin << " " << end << "|";
        reverse(arr + begin, arr + 1 + end);
    // }
    for (int ar : arr) {
        cout << ar << " ";
    }
    cout << "\n";
}