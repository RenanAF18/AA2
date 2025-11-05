#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 17 + 10;
vector<ll> tree(4 * MAXN);
vector<ll> a(MAXN);


typedef long long ll;
typedef pair<ll,ll> pii;

ll build(int idx, int l, int r, bool orr){
    if(l == r){
        tree[idx] = a[l];
        return tree[idx];
    }
    else{
        int mid = (l + r)/2;
        if(orr)
            tree[idx] = build(2*idx,l, mid, false) | build(2*idx + 1, mid + 1, r, false);
        else
            tree[idx] = build(2*idx,l, mid, true) ^ build(2*idx + 1, mid + 1, r, true);
        return tree[idx];
    }
}

ll update(int idx, int l, int r, int pos, ll val, bool orr){
    if(l == r)
        tree[idx] = val;
    else{
        int mid = (l + r)/2;
        
        if(pos < mid)
            update(idx*2, l, mid, pos, val, !orr);
        else
            update(idx*2 + 1, mid + 1, r, pos, val, !orr);
    }     

}

ll query(int idx, int l, int r, int lq, int rq){
    if( l > rq || r < rq)
        return 0;
    
    if(lq >= l && r <= rq)
        return tree[idx];
    
    int mid = (l + r)/2;


}
 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n,q;
    for(ll &x : a) cin >> x;
    

    
    
    return 0;
}