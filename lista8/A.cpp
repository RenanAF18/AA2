#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int kmp(string s, int nn) {
    int n = (int)s.length();
    vector<int> pi(n);
    int out = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0){
            if(s[i] != s[j]) j = pi[j-1];
            else break;
        }  
        if (s[i] == s[j])
            j++;
        if(j >= nn){
            out++;
            j = 0;
        }
        pi[i] = j;
    }
    return out;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    string s, ss; cin >> s >> ss;
    string aux = ss + "#" + s;

    int sum = 0;
    int v = kmp(aux, ss.length());
    cout << v << '\n';
    return 0;
}