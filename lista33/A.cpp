#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

ll MAXN = 2 * 1e5;
vii sz(MAXN +1, 0);
vii s(MAXN + 1, 0);
vii sums(MAXN + 1, 0);
vector<vii> adj(MAXN + 1);

void dfs1(ll p, ll v){
    sz[v] = 1;
    s[v] = 0;
    for (ll u : adj[v]) {
        if (u == p) continue;
        dfs1(v, u);
        sz[v] += sz[u];
        s[v] += s[u] + sz[u];

    }
}

void dfs2(ll p, ll v, ll n){
    if(v != 1)
        s[v] = s[p] + n -2 * sz[v];
    
     for (ll u : adj[v]) {
        if (u == p) continue;
        dfs2(v, u, n);
    } 
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        ll v, u; cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
   }

   dfs1(0, 1);
   dfs2(0, 1, n);

    for(int i = 1; i <= n; i++){
        cout << s[i] << " ";
    }

    
    return 0;
}