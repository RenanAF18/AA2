#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;


struct Node{
    ll sufix;
    ll prefix;
    ll total;
    ll max_sum;
    
    Node(): sufix(0), prefix(0), total(0), max_sum(0){}
    Node(ll s, ll p, ll t, ll ms): sufix(s), prefix(p), total(t), max_sum(ms){}
};

const ll MAXN = 50000;
vector<Node> tree(4 * MAXN);
vii a(MAXN);

Node merge(Node left, Node right){
    Node result;
    
    result.total = left.total + right.total;
    result.prefix = max(left.prefix, left.total + right.prefix);
    result.sufix = max(right.sufix, right.total + left.sufix);
    result.max_sum = max({left.max_sum, right.max_sum, left.sufix + right.prefix});
    return result;
}

void build(ll idx, ll l, ll r){
    if(l == r){
        tree[idx].max_sum = a[l];
        tree[idx].prefix = a[l];
        tree[idx].sufix = a[l];
        tree[idx].total = a[l];
        return;
    }
    ll mid = (l + r)/2;

    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    tree[idx] = merge(tree[idx*2], tree[idx*2+1]);
}


void update(ll idx, ll l, ll r, ll pos, ll value){
    if(l == r){
        tree[idx].max_sum = value;
        tree[idx].prefix = value;
        tree[idx].sufix = value;
        tree[idx].total = value;
        return;
    }

    ll mid = (l + r)/2;
    if(pos <= mid)
        update(idx * 2, l, mid, pos, value);
    else
        update(idx * 2 + 1, mid + 1, r, pos, value);

    tree[idx] = merge(tree[idx*2], tree[idx*2+1]);
}

Node query(ll idx, ll l, ll r, ll lq, ll rq){
    if(r < lq || l > rq){
        return Node(LLONG_MIN/2, LLONG_MIN/2, 0, LLONG_MIN/2);
    }
    if (lq <= l && r <= rq){
        return tree[idx];
    }
    ll mid = (l + r)/2;
    Node result = merge(query(idx*2, l, mid, lq, rq), query(idx*2+1, mid+1,r,lq,rq));
    return result;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, c;
    cin >> n;

    for(ll i = 1; i < n + 1; i++)
        cin >> a[i];    
    
    build(1, 1, n);

    cin >> c;
    while(c--){
        ll op, x, y;
        cin >> op >> x >> y;
        if(op == 0)
            update(1, 1, n, x, y);
        else
            cout << query(1, 1, n, x, y).max_sum << "\n";
    }   
    

    return 0;
}