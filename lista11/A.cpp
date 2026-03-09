#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll,ll> lii;

void solve_tc(){

    int n, a, b;
    cin >> n >> a >> b;

    if(abs(a - b) % 2 == 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}