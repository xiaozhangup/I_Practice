// 链接: https://codeforces.com/contest/2200/problem/D
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> middle(arr.begin() + x, arr.begin() + y);
    int min = 1e9;
    int min_ind = 0;
    for (int i = 0; i < middle.size(); i++) {
        if (min > middle[i]) {
            min_ind = i;
            min = middle[i];
        }
    }

    vector<int> outer;

    outer.insert(outer.end(), arr.begin(), arr.begin() + x);
    outer.insert(outer.end(), arr.begin() + y, arr.end());
    
    int latest_ind = -1;
    for (int i = 0; i < outer.size(); i++) {
        // cout << outer[i] << " ";
        if (outer[i] < min) latest_ind = i;
        else break;
    }
    latest_ind += 1;

    // 2
    // 3 1

    // 3 1 4 2 
    // 2 
    // 3 5 
    // 1
    
    // 1 | 3 5 | 2 4


    // HEADER
    // cout << min <<  " " << latest_ind << "|";
    for (int i = 0; i < latest_ind; i++) {
        cout << outer[i] << " ";
    }

    // MIDDLE
    for (int i = 0; i < middle.size(); i++) {
        cout << middle[(min_ind + i) % middle.size()] << " ";
    }

    // END
    for (int i = max(0, latest_ind); i < outer.size(); i++) {
        cout << outer[i] << " ";
    }

    cout << "\n";
}