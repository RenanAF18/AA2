#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

vector<bool> dp;
vii rm;
int n, k;

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> k;

    rm = vii(k);
    for(int i = 0; i < k; i++) 
        cin >> rm[i];

    dp = vector<bool>(n+1);
    dp[0] = false;

    for(int i = 0; i <= n; i++){
        for (int j = 0; j < k; j++){
            if(!dp[i] && (i + rm[j] <= n))
                dp[i + rm[j]] = true;
        }
    }

    for(int i = 1; i <= n; i++){
        if(dp[i])
            cout << "W";
        else cout << "L";
    }
}