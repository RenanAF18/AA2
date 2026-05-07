#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

void solve_tc(){

    int n, m; cin >> n >> m;
    vii x(n), r(n);

    for(ll &v : x) cin >> v;
    for(ll &v : r) cin >> v;

    map<ll,ll> best;

    for (int i = 0; i < n; i++) {

        for (ll d = -r[i]; d <= r[i]; d++) {

            ll curX = x[i] + d;
            ll inside = r[i]*r[i] - d*d;
            ll yMax = sqrt((long double)inside);

            while ((yMax+1)*(yMax+1) <= inside)
                yMax++;

            while (yMax*yMax > inside)
                yMax--;
        
            best[curX] = max(best[curX], yMax);
        }
    }

    ll ans = 0;

    for (auto [X, y] : best) {
        ans += 2*y + 1;
    }

    cout << ans << '\n';
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}