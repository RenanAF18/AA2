#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

void solve_tc(){
    ll a, h, n; cin >> a >> h >> n;
    vector<ll> am(n), hm(n);

    for(int i = 0; i < n; i++) cin >> am[i];
    for(int i = 0; i < n; i++) cin >> hm[i];
    
    int last = 0;
    ll max = 0;
    for(int i = 0; i < n; i++){
        if(am[i] > max){
            max = am[i];
            last = i;
        }
    }

    for(int i = 0; i < n; i++){
        if(i == last) continue;
        ll k = (hm[i] + a - 1) / a;
        h -= am[i] * k;
        if(h <= 0){ cout << "NO\n"; return; }
    }

    ll k = (hm[last] + a - 1) / a;
    h -= am[last] * k;
    cout << (h > -am[last] ? "YES" : "NO") << "\n";

}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}