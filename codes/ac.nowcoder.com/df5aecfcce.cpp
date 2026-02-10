// 链接: https://ac.nowcoder.com/acm/contest/120563/B
// 日期: 2026年02月07日

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
#include <numeric>
// #include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
vector<int> primes;
bool vis[N + 1];

void slove();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i <= 1e6; i++) {
        if (!vis[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * p * i > N) break;
            vis[p * i] = true;
            if (i % p == 0) break;
        }
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

vector<int> factorize(int x) {
    vector<int> res;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) {
            res.push_back(p);
            while (x % p == 0) x/= p;
        }
    }

    if (x > 1) {
        res.push_back(x);
    }

    return res;
}

void slove() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    map<int, int> mapping;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arr[i] = a;
    }

    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        for (int b : factorize(num)) {
            if (mapping.find(b) != mapping.end() && mapping[b] != i) {
                cout << arr[mapping[b]] << " " << num << "\n";
                return;
            }

            mapping[b] = i;
        }
    }

    cout << "-1\n";
}