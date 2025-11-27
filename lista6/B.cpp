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

void dijkstra(int start, int n){
    priority_queue<tii, vector<tii>, greater<tii>> pq;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 10; j++)
            dist[i][j] = INF;
    }
    for(int i = 0; i < 10; i++){
        dist[start][i] = 0;
        pq.push({0, start, i});
    }
    
    while(!pq.empty()){


    }
    
    
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, k; cin >> n >> m >> k;
    
    return 0;
}