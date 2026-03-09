#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll,ll> lii;

void solve_tc(){

    string s; cin >> s;
    string out = "";
    bool ela = true;

    for(int i = 0; i < (int)s.size(); i++){
        if(ela){
            if(s[i] == 'a')
                out += 'b';
            else out += 'a';
            ela = false;
        }
        else{
            if(s[i] == 'z')
                out += 'y';
            else out += 'z';
            ela = true;
        }
    }

    cout << out << "\n";

}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}