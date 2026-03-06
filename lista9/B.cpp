#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main(){

    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    
    vector<pii> v = vector<pii>(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    
    pii minus = v[0];
    for(auto p : v){
        if(p.second < minus.second)
            minus = p;
        else if(p.second == minus.second && p.first < minus.first)
            minus = p;
    }

    for(auto p : v){
        p = {p.first - minus.first, p.second - minus.second};
    }

    
    return 0;
}