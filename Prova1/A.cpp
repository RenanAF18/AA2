#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;


const int LOG = 20;
const int MAXN = 2 * 1e5 + 100;
int up[MAXN][LOG];
int prof[MAXN];

vector<int> adj[MAXN];

void dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i < LOG; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(auto u : adj[v]){
        if(u == p) continue;

        prof[u] = prof[v] + 1;
        dfs(u,v);
    }
}

int lca(int a, int b){
    if(prof[a] < prof[b]) swap(a, b);
    int k = prof[a] - prof[b];

    for(int i = LOG - 1; i >= 0; i--){
        if(k & (1 << i))
            a = up[a][i];
    }
        
    if(a == b) return a;

    for(int i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];

}


int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }

    dfs(1,1);
    while(q--){
        int a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}