#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const ll INF = 1e18;
const int MAXN = 2 * 1e5 + 100;
vector<ll> tree(4 * MAXN + 100); 
vector<ll> v(MAXN + 1);

void build(int idx, int l, int r){
    if(l == r)
        tree[idx] = v[l];
    else{
        int mid = (l + r)/2;
        build(idx * 2, l, mid);
        build(idx*2 + 1, mid+1, r);

        tree[idx] = min(tree[idx*2], tree[idx*2 + 1]);
    }
}


void update(int idx, int l, int r, int pos, ll value){
    if(l == r)
        tree[idx] = value;
    else{
        int mid = (l + r)/2;
        if(pos <= mid) update(idx * 2, l, mid, pos, value);
        else update(idx * 2 + 1, mid + 1, r, pos, value);
        tree[idx] = min(tree[idx*2], tree[idx*2 + 1]);    
    }
}

ll query(int idx, int l, int r, int e, int d){
    if(e > r || d < l)
        return INF;

    if(e <= l && d >= r)
        return tree[idx];

    int mid =(l + r)/2;
    return min(query(idx*2, l, mid, e, d), query(idx*2+1, mid+1, r, e, d));
}
int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    
    build(1, 1, n);

    while(q--){
        int op, x, y; cin >> op >> x >> y;
        if(op == 2) cout << query(1, 1, n, x, y) << "\n";
        else update(1, 1, n, x, y); 
    }
    return 0;
}