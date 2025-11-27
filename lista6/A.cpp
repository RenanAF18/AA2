#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 2 * 1e5;
vector<pii> graph[MAXN];
ll dist [MAXN][2];

void dijkstra(int start, int n){
    for(int i = 0; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[start][0] = 0;
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    pq.push({0, {start, 0}});

    while(!pq.empty()){
        ll d = pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();
    
        if(d > dist[u][used]) continue;
        
        for(auto edge : graph[u]){
            int v = edge.first;
            ll w = edge.second;
            
            if(dist[v][used] > dist[u][used] + w){
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], {v, used}});
            }
            
            if(used == 0){
                ll new_dist = dist[u][0] + w / 2;
                if(dist[v][1] > new_dist){
                    dist[v][1] = new_dist;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
    }
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(1, n); 
    ll answer = min(dist[n][0], dist[n][1]);
    cout << answer << endl;
    return 0;
}