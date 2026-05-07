#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
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

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, q; cin >> n >> q;
    bit<ll> a(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.add(i+1, x);
    }

    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op)
            cout << a.query(x+1, y) << "\n";
        else
            a.add(x+1, y);
    }
    
    return 0;
}