#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){
    ll r, x, d, n; cin >> r >> x >> d >> n;
    string s; cin >> s;
    int count = 0;
    int atual = r;
    bool mudou = false;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            count++;
            if(atual >= x){
                if(abs(r - x + 1) <= d)
                    atual -= abs(atual - x + 1);
                else
                    atual -= d;
            }
        }
        else
            if( atual < x) count++;

    }
    
    cout << count << "\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}