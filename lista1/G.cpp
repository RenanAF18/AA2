#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

const int MAXN = 5 * 100000 + 10;

vii tree(MAXN * 4);
vii a(MAXN);

void build(int idx, int l, int r){
    if(l == r)
        tree[idx] = a[l];
    else{
        int mid = (l + r)/2;

        build(idx*2, l, mid);
        build(idx*2+1, mid+1, r);

        tree[idx] = __gcd(tree[idx*2], tree[idx*2+1]);
    }
}

void update(int idx, int l, int r, int pos, ll val){
    if(l == r){
        tree[idx] = val;
        return;
    }
    int mid = (l + r)/2;

    if(pos <= mid)
            update(idx*2, l, mid, pos, val);
    else
        update(idx*2+1, mid+1, r, pos, val);

    tree[idx] = __gcd(tree[idx*2], tree[idx*2+1]);
}

ll query(int idx, int l, int r, int lq, int rq, ll x) {
    if (r < lq || l > rq)
        return 0;

    if (lq <= l && r <= rq) {
        if (tree[idx] % x == 0)
            return 0;
        if (l == r)
            return 1;
    }

    int mid = (l + r) / 2;
    ll left = query(idx * 2, l, mid, lq, rq, x);
    if (left > 1)
        return left;
    ll right = query(idx * 2 + 1, mid + 1, r, lq, rq, x);
    return left + right;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    cin >> q;
    while (q--) {
        int op, l, r;
        ll x;
        cin >> op >> l >> r;

        if (op == 1) {
            cin >> x;
            ll result = query(1, 1, n, l, r, x);
            cout << (result <= 1 ? "YES\n" : "NO\n");
        } else {
            update(1, 1, n, l, r);
            a[l] = r;
        }
    }

    return 0;
}