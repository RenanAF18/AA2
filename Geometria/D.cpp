#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

ll dist(pii A, pii B){
    return (A.first - B.first) * (A.first - B.first) +
            (A.second - B.second) * (A.second - B.second);
}

void solve_tc(){

    int n; cin >> n;
    vector<pii> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        cin >> v[i].second;
    }

    pii s, e;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    ll aux = dist(s, e);
    bool possible = true;
    for(auto p : v){
        if(dist(p, e) <= aux){
            possible = false;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << "\n";

}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}