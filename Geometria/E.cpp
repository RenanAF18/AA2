#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve_tc(){

    ll r;
    cin >> r;

    ll ans = 0;

    for(ll x = r; x >= 0; x--){

        ll yMin = ceil(sqrt((long double)(r*r - x*x)));
        ll yMax = ceil(sqrt((long double)((r+1)*(r+1) - x*x))) - 1;

        if(yMin <= yMax)
            ans += yMax - yMin + 1;
    }

    cout << ans*4 - 4 << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc;
    cin >> tc;

    while(tc--)
        solve_tc();
}