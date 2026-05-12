#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

struct lca{
    vector<vi> adj, anc;
    vi dep, in, out;
    int n, lg, t = 0;

    lca(int n): n(n), adj(n+1), dep(n+1), in(n+1), out(n+1){
        lg = 32 -__builtin_clz(n);
        anc = vector<vi>(n + 1, vi(lg));
    }

    void add_edge(int u, int v){
        adj[u].pb(v);
        adj[v].pb(u);
    }

    void dfs(int v, int p = -1, int d = 1){
        dep[v] = d;
        in[v] = t++;
        rep(i, 1, lg) anc[v][i] = anc[anc[v][i-1]][i-1];

        for(int ch : adj[v]) if (ch != p) {
            anc[ch][0] = v;
            dfs(ch, v, d + 1);
        }
        out[v] = t++;
    }

    bool is_anc(int a, int b){
        return (in[a] <= in[b]) && (out[a] >= out[b]);
    }
    int get_lca(int a, int b) {
        if(is_anc(a, b)) return a;
        if(is_anc(b, a)) return b;
        for (int i = lg - 1; i >= 0; i--) {
            if (!is_anc(anc[a][i], b) && in[anc[a][i]] != out[anc[a][i]]){
                a = anc[a][i];
            }
        }
        return anc[a][0];
    }
    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[get_lca(a, b)];
    }
    int jump(int v, int k) {
        for (int i = lg - 1; i >= 0; i--) {
            if ((1 << i) <= k) {
                v = anc[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }

};

void solve_tc(){
    int n, q; cin >> n >> q;
    
    lca tree(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;

        tree.add_edge(a,b);
    }

    tree.dfs(1);

    while(q--){
        int a, b; cin >> a >> b;

        cout << tree.dist(a,b) << endl;
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1;
    while(tc--) solve_tc();
    
    return 0;
}