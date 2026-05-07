#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){

    int n; cin >> n;
    vector<int> v = vector<int>(n);
    
    for(int &x : v) cin >> x;
    int xorr = 0;
    for(int x : v) xorr ^= x;

    if(xorr % 4 > 0) cout << "first" << "\n";
    else cout << "second" << "\n"; 

}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}