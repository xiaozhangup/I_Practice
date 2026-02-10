// 链接: https://ac.nowcoder.com/acm/contest/120563/G
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

#define int long long

bool comp(int a, int b) {
    return a > b;
}

void slove() {
    int n, m; cin >> n >> m;

    vector<int> arra(n);
    int suma = 0;
    for (int i = 0; i < n; i++) {
        cin >> arra[i];
        suma += arra[i];
    }
    sort(arra.begin(), arra.end(), comp);

    vector<int> arrb(m);
    int sumb = 0;
    for (int i = 0; i < m; i++) {
        cin >> arrb[i];
        sumb += arrb[i];
    }
    sort(arrb.begin(), arrb.end(), comp);

    int cs = abs(suma - sumb);
    if (suma == sumb) {
        cout << "1\n";
    } else if (suma > sumb) {
        int sa = 0;
        int i = 0;
        while (sa < cs)
        {
            sa += arra[i++];
        }
        cout << i << "\n";
        
    } else if (suma < sumb) {
        int sb = 0;
        int i = 0;
        while (sb < cs)
        {
            sb += arrb[i++];
        }
        cout << i << "\n";
    }

}