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
vector<pii> graph [MAXN];
ll dist[MAXN][MAXN];

void typedef vector<pii> vpii;
typedef pair<ll,ll> pii;

void dijkstra(int start, int n){
    
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    for(ll i=0;i<m;i++) dis[s[i]] = 0, q.insert({0, s[i]});
    while(!q.empty()){
        auto& [d, v] = *q.begin();
        for(auto& [u, w]: g[v]){
            if(d + w >= dis[u]) continue;
            q.erase({dis[u], u});
            dis[u] = d + w;
            q.insert({dis[u], u});
        }
        q.erase(q.begin());
    }
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, k; cin >> n >> m >> k;
    
    return 0;
}