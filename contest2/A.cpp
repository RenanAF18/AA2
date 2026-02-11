#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

void solve_tc(){
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> v = vector<int>(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[i] = x;
        sum = sum + x;
    }
    int resp = s - sum;
    if(resp == 0){
        cout << "YES" << "\n";
    }else if((resp % x == 0) && (sum < s))
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}