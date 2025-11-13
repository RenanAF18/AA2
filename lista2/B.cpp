#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b)  for(int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

const int MAXN = 2 * 100000;
vii tree(4 * MAXN);
vii v(MAXN + 1), h(MAXN + 1);

void build(int idx, int l, int r){
    if(l == r){
         tree[idx] = h[l];
         return;
    }
    int mid = (l + r)/2;

    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);

    tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

ll query(int idx, int l, int r, ll x) {
    if (l == r) {
        tree[idx] -= x;
        return l;
    }

    int mid = (l + r) / 2;
    ll out;

    if (tree[idx * 2] >= x)
        out = query(idx * 2, l, mid, x);
    else
        out = query(idx * 2 + 1, mid + 1, r, x);

    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    return out;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    

    rep(i, 1, n+1) cin >> h[i];
    //rep(i, 1, m+1) cin >> v[i];
    build(1,1,n);
    int out = 1;

    int q;
    rep(j, 0, m){
        cin >> q;
        if(tree[1] < q)
            cout << 0 << " ";
        else
            cout << query(1, 1, n, q) << " ";
    }
    cout << "\n";

    

    return 0;
}   