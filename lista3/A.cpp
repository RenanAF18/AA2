#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<vector<ll>> pulos(1001,vector<ll>(20, 0));
vector<ll> dist(1001, -1);
vector<vector<ll>> graph(1001,vector<ll>(1000, 0));

void dfs(int i, int father){
    if(father == -1)
        dist[i] = 0;
    else
        dist[i] = dist[father] + 1;
    
    for(ll x : graph[i]){
        if(x != father)
            pulos[x][0] = i;
            dfs(x, i);
    }
}

void solve_tc(){
    int n;
    cin >> n;
    
    int m;
    for(int i = 1; i <= n; n++){
        cin >> m;
        int aux;
        while(m--){
            cin >> aux;
            graph[i].push_back(aux);
        }
    }
    dfs(1,-1);
    for(int i = 19; i > 0; i--){
        for(int j = 1; j <= n; i++){
            pulos[j][i] = pulos[pulos[j][i-1]][i-1];
        }
    }

    int q; cin >> q;


}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}