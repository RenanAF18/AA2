#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){

    string s; cin >> s;
    int resp = 0;
    int count = 0;
    vector<int> somas = vector<int>();

    for(char c : s){
        if(c == '1')
            count++;
        else{
            somas.push_back(count);
            count = 0;
        }
    }
    if (count > 0) somas.push_back(count);
    bool ela = true;
    sort(somas.begin(), somas.end(), greater<int>());
    for(int i = 0; i < (int)somas.size(); i++){
        if(ela){
            resp += somas[i];
            ela = false;
        }
        else
            ela = true;
    }
    cout << resp << "\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}