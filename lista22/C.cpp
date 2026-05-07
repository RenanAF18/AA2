#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

template<typename T> struct bit {
    int n;
    vector<T> a;
    bit(int n) : n(n), a(n + 1) {}

    void add(int pos, T x) {
        for (; pos <= n; pos += (pos & -pos)) a[pos] += x;
    }
    T query(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= (pos & -pos)) ans += a[pos];
        return ans;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve_tc(){

    int n; cin >> n;
    ll ans = 0;
    vii a(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    vii b = a;
    sort(b.begin(), b.end());
    map<ll, ll> comp;
    for(int i = 0; i < n; i++)
        comp[b[i]] = i+1;

    bit<ll> tree(n);
    for(int i = n-1; i >= 0; i--){
        ans += tree.query(0, comp[a[i]]-1);
        tree.add(comp[a[i]], 1);
    }
    cout << ans << endl;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}