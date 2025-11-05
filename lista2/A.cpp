#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<ll> lazy(10e6 + 10);
vector<ll> tree(10e6 + 10);

void prop(int id, int l, int r, int e, int d){
    if(lazy[id] == 0)
        return;
    tree[id] += (r - l + 1) * lazy[id];
    if(l != r){
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
}


void update(int idx, int l, int r, int e, int d, ll val){
    prop(idx, l, r, e, d);
    if(l > d || r < e)
        return;
    if(l >= e && r <=d){
        tree[idx] += val * (r - l + 1);
        if(l != r){
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
        return;
    }
    int mid = (l + r)/2;
    update(idx * 2, l, mid, e, d, val);
    update(idx * 2 + 1, mid + 1, r, e, d, val);
    tree[idx] = tree[idx*2] + tree[idx*2 + 1];
}

ll query(int id, int l, int r, int lq, int rq){
    prop(id, l, r, lq, rq);
    if(l > rq || r < lq)
        return 0;
    if(l >= lq && r <= rq){
        return tree[id];
    }
    int mid = (l + r)/2;
    return(query(id * 2, l , mid, lq, rq) + query(id * 2 + 1, mid + 1, r, lq, rq));
}

void solve_tc(){
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < 4 * n + 10; i++){
        lazy[i] = 0;
        tree[i] = 0;
    }
    while(c--){
    int qq, p, q, v; cin >> qq >> p >> q;
    if (qq == 0){
        cin >> v;
        update(1, 1, n, p, q, v);
        
    }
    else{
        cout << query(1, 1, n, p, q) << endl;
    }
    }
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}