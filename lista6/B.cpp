#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;
typedef tuple<ll, ll, ll> tii;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 2 * 1e5;
const int MAXK = 10;

vector<pii> graph [MAXN];
ll dist[MAXN][MAXK];

int atualizar(int v, ll newDist, int k){
    for(int i = 0; i <= k; i++){
        if(dist[v][i] == INF){
            dist[v][i] = newDist;
            return 1;
        }
    }
    return -1;
}

void dijkstra(int start, int n, int k){
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 10; j++)
            dist[i][j] = INF;
    }
    
    
    pq.push({0, start});

    
    while(!pq.empty()){
        ll d, u;
        d = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if (atualizar(u, d, k-1) == -1) continue;
        
        for(auto edge : graph[u]){
            int v = edge.first;
            ll w = edge.second;

            ll newDist = w + d;
            pq.push({newDist, v});
        }
    }    
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, k; cin >> n >> m >> k;
    while(m--){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra(1, n, k);

    for(int i = 0; i < k; i++)
        cout << dist[n][i] << " ";
    
    return 0;
}