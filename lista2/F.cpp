#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef vector<ll> vii;

const int MAXN = 100000;
vii arr(MAXN + 5);
ll tree[4 * MAXN][40];
vii lazy(4 * MAXN);

void propagation(int idx, int left, int right) {
    if (lazy[idx] == 0) return;

    ll x = lazy[idx];
    int len = right - left + 1;

    for (int i = 0; i < 40; i++) {
        if (x & (1LL << i)) {
            tree[idx][i] = len - tree[idx][i];
        }
    }

    if (left != right) {
        lazy[idx * 2] ^= x;
        lazy[idx * 2 + 1] ^= x;
    }

    lazy[idx] = 0;
}

void build(int idx, int l, int r) {
    if (l == r) {
        for (int i = 0; i < 40; i++) {
            tree[idx][i] = (arr[l] & (1LL << i)) ? 1 : 0;
        }
        return;
    }

    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    for (int i = 0; i < 40; i++)
        tree[idx][i] = tree[idx * 2][i] + tree[idx * 2 + 1][i];
}

void update(int idx, int l, int r, int ql, int qr, ll x) {
    propagation(idx, l, r);

    if (qr < l || ql > r) return;
    if (ql <= l && r <= qr) {
        lazy[idx] ^= x;
        propagation(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, ql, qr, x);
    update(idx * 2 + 1, mid + 1, r, ql, qr, x);

    for (int i = 0; i < 40; i++)
        tree[idx][i] = tree[idx * 2][i] + tree[idx * 2 + 1][i];
}

ll query(int idx, int l, int r, int lq, int rq) {
    propagation(idx, l, r);

    if (r < lq || l > rq)
        return 0;

    if (lq <= l && r <= rq) {
        ll out = 0;
        for (int i = 0; i < 40; i++)
            out += tree[idx][i] * (1LL << i);
        return out;
    }

    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, lq, rq)
         + query(idx * 2 + 1, mid + 1, r, lq, rq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n;
    rep(i, 1, n + 1) cin >> arr[i];
    cin >> m;

    build(1, 1, n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        } else {
            int l, r; ll x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }

    return 0;
}
