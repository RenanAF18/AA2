#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

ll minLPS(string s, ll c){
    vector<ll> lps = vector<ll>(s.size(), 0);
    int len = 0;
    int i = 1;
    int resp = s.size();
    int aux = 0;
    
    while(i < s.size()){
        if(s[len] == s[i]){
            len++;
            i++;
        }else{
            if(len == 0){
                lps[i] == 0;
                i++;
            }else{
                len = lps[len-1];
            }
            aux = i+1;
            if(s.size() % aux == 0){
                resp = min(aux, resp);
            }
        }
    }
    return resp;
}   


void solve_tc(){
    string s; cin  >> s;
    set<char> aux;
    for (int i = 0; i < s.size(); i++)
        aux.insert(s[i]);

    cout << minLPS(s, aux.size()) << "\n\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}