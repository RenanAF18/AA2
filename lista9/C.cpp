#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

vii lps(string s){
    vii lps = vii(s.size(), 0);
    int i, len;
    i = 1;
    len = 0;

    while(i < s.size()){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }

    return lps;
}

vii counts(string s, string ss){
    vii aux = lps(s);
    int i, j;
    i = 0;
    j = 0;
    
    int n, m;
    n = ss.size();
    m = s.size();
    
    vii resp = vii();

    while(i < (int)ss.size()){
        // If characters match, move both pointers forward
        if (ss[i] == s[j]) {
            i++;
            j++;

            // If the entire pattern is matched
            // store the start index in result
            if (j == m) {
                resp.push_back(i - j);

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = aux[j - 1];
            }
        }

        // If there is a mismatch
        else {

            // Use lps value of previous index
            // to avoid redundant comparisons
            if (j != 0)
                j = aux[j - 1];
            else
                i++;
        }
    }
    return resp;
}

void solve_tc(){
    string s, ss;
    int n; cin >> n;
    cin >> s >> ss;
    if((int)s.size() > (int)ss.size()){
        cout << "0" << "\n";
        return;
    }

    vii resp = counts(s, ss);
    for(ll v : resp) cout << v << "\n";



}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--){ 
        solve_tc();
        cout << "\n";
    }
    return 0;
}