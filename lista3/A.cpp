#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> pulos(1001, vector<ll>(20, 0));
vector<ll> dist(1001, -1);
vector<vector<ll>> graph(1001);

void dfs(int i, int father) {
    if (father == -1)
        dist[i] = 0;
    else
        dist[i] = dist[father] + 1;

    for (ll x : graph[i]) {
        pulos[x][0] = i;
        dfs(x, i);
    }
}

ll lca(ll x, ll y) {
    if (dist[x] < dist[y])
        swap(x, y);

    ll dif = dist[x] - dist[y];

    for (int i = 19; i >= 0; i--) {
        if (dif & (1 << i))
            x = pulos[x][i];
    }

    if (x == y)
        return x;

    for (int i = 19; i >= 0; i--) {
        if (pulos[x][i] != pulos[y][i]) {
            x = pulos[x][i];
            y = pulos[y][i];
        }
    }
    return pulos[x][0];
}

void solve_tc(int t) {
    int n;
    cin >> n;

    vector<bool> has_parent(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int aux;
            cin >> aux;
            graph[i].push_back(aux);
            has_parent[aux] = true;
        }
    }

    int root = 1;
    for (int i = 1; i <= n; i++)
        if (!has_parent[i]) root = i;

    dfs(root, -1);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (pulos[j][i - 1] != 0)
                pulos[j][i] = pulos[pulos[j][i - 1]][i - 1];
        }
    }

    int q;
    cin >> q;
    cout << "Case " << t << ":\n";
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }

    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        dist[i] = -1;
        for (int j = 0; j < 20; j++) pulos[i][j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
        solve_tc(i);
}
