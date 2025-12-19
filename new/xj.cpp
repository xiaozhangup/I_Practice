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

using namespace std;

void slove();

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.sync_with_stdio(false);
    cout.tie(NULL);

    slove();
}

#define ll long long

vector<int> topo_sort(int n, const vector<vector<int>>& g) {
    vector<int> indeg(n+1, 0), res;
    for (int u = 1; u <= n; u++)
        for (int v : g[u]) indeg[v]++;
    
    priority_queue<int> q; 
    for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.top(); q.pop();
        res.push_back(u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    return res; 
}

void slove() {
    int T; 
    if (!(cin >> T)) return;
    while (T--)
    {
        int N, M; cin >> N >> M;
        vector<vector<int>> g(N + 1);
        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            g[b].push_back(a); 
        }

        vector<int> res = topo_sort(N, g);
        
        for (int i = N - 1; i >= 0; i--) {
            cout << res[i] << (i == 0 ? "" : " ");
        }
        cout << "\n";
    }
}