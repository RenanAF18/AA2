#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    ll a, b, x, y; cin >> a >> b >> x >> y;
    
    ll aux = __gcd(x,y);
    x = x/aux;
    y = y/aux;
    
    ll resp = 0;
 
    ll aux2 = a/x;
    ll aux3 = b/y;

    resp = min(aux2, aux3);
    cout << resp << "\n";
    

    
    return 0;
}
