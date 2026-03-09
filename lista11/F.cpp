#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll,ll> lii;

void solve_tc(){

    string s; cin >> s;
    int zero = 0, um = 0;
    for(char c: s){
        if(c == '0')
            zero++;
        else um++;
    }

    if(zero == 0 || um == 0)
        cout << "NET" << "\n";

    else if(um >= zero){
        if(zero % 2 == 0)
            cout << "NET" << "\n";
        else cout << "DA" << "\n";
    }
    else{
        if(um % 2 == 0)
            cout << "NET" << "\n";
        else cout << "DA" << "\n";
    }
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}