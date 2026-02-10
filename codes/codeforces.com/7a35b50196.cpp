// 链接: https://codeforces.com/gym/106290/problem/C
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

long long qmul(long long a, long long b, long long mod) {
    long long r = 0;
    while (b) {
        if (b & 1) r = (r + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return r;
}

long long qpow_mod(long long a, long long b, long long mod) {
    long long r = 1 % mod;
    while (b) {
        if (b & 1) r = qmul(r, a, mod);
        a = qmul(a, a, mod);
        b >>= 1;
    }
    return r;
}

bool miller_rabin(long long n) {
    if (n < 2) return false;
    for (long long p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    long long d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    for (long long a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (a % n == 0) continue;
        long long x = qpow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int r = 1; r < s; r++) {
            x = qmul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

map<int, int> mem;
int way2go(int num) {
    if (mem.find(num) != mem.end()) {
        return mem[num];
    }

    if (num == 1) return 0;
    if (miller_rabin(num)) {
        mem[num] = 1;
        return 1;
    }

    int ways = 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            ways = max(ways, way2go(num / i) + 1);
        }
    }

    mem[num] = ways;
    return mem[num];
}

void slove() {
    int times = 0;
    int a, b; cin >> a >> b;

    int wa = way2go(a);
    int wb = way2go(b);

    // cout << wa << ":" << wb << "\n";
    if ((wa ^ wb) != 0) cout << "Yes\n";
    else cout << "No\n";
}