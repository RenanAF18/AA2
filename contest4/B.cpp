#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    ll k, n; cin >> k >> n;
    string out = "";
    
    if(n%2 != 0){
        ll div = n/2;
        if( k == 1 && n > 3) out = "*";
        else if((div + 1) == k){
            for(ll i = 0; i < n; i++){
                if(i%2 == 0) out += "X";
                else out += "-";
            }
        } 
        else if (div == k){
            for(ll i = 0; i < n; i++){
                if(i%2 != 0) out += "X";
                else out += "-";
            }
        }
        else if(div-1 == k ){
            int count = 1;
            for(ll i = 0; i < n; i++){
                if(count == 0){
                    out += "X";
                    count = 2;
                }
                else{
                    out += "-";
                    count--;
                }
            }
        }
        else out = "*";
    }
    else{
        ll div = n/2;
        if( k == 1 && n > 2) out = "*";
        else if(div == k){
            for(ll i = 0; i < n; i++){
                if(i%2 == 0) out += "X";
                else out += "-";
            }
        }

        else if((div -1) == k){
            int count = 0;
            for(ll i = 0; i < n; i++){
                if(count == 0){
                    out += "X";
                    count = 2;
                }
                else{
                    out += "-";
                    count--;
                }
            }
        }
        else if((div -2) == k){
            int count = 1;
            for(ll i = 0; i < n; i++){
                if(count == 0){
                    out += "X";
                    count = 2;
                }
                else{
                    out += "-";
                    count--;
                }
            }
        }
        else if((div -3) == k){
            int count = 1;
            for(ll i = 0; i < n; i++){
                if(count == 0){
                    out += "X";
                    count = 2;
                }
                else{
                    out += "-";
                    count--;
                }
            }
        }
        else out = "*";
    }
    cout << out << "\n";
    
    
    return 0;
}