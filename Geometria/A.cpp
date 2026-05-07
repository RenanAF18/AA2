#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

int prod(pii a, pii b){
    return  a.first * b.first +
            a.second * b.second;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    pii a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    pii ab, ac;
    pii ba, bc;
    pii ca, cb;

    ab.first = b.first - a.first;
    ab.second = b.second - a.second;
    ac.first = c.first - a.first;
    ac.second = c.second - a.second;

    ba.first = a.first - b.first;
    ba.second = a.second - b.second;
    bc.first = c.first - b.first;
    bc.second = c.second - b.second;

    ca.first = a.first - c.first;
    ca.second = a.second - c.second;
    cb.first = b.first - c.first;
    cb.second = b.second - c.second;

    if(prod(ab, ac) == 0 || prod(ba, bc) == 0 || prod(ca, cb) == 0)
        cout << "Yes";

    else cout << "No";


    
    return 0;
}