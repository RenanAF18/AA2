#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    x2 = x2 - x1;
    y2 = y2 - y1;
    x3 = x3 - x1;
    y3 = y3 - y1;

    ll result = (x2 * y3) - (y2 * x3);

    if(result == 0) cout << "TOUCH" << '\n';
    else if(result > 0) cout << "LEFT" << '\n';
    else cout << "RIGHT" << '\n';

}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}