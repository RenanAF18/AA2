#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = (1 << 17) + 10;
vector<ll> tree(4 * MAXN);
vector<ll> a(MAXN);

ll build(int idx, int l, int r, bool orr) {
    if (l == r)
        return tree[idx] = a[l];

    int mid = (l + r) / 2;
    ll left = build(2 * idx, l, mid, !orr);
    ll right = build(2 * idx + 1, mid + 1, r, !orr);

    if (orr) tree[idx] = left | right;
    else tree[idx] = left ^ right;

    return tree[idx];
}


void update(int idx, int l, int r, int pos, ll val, bool orr) {
    if (l == r) {
        tree[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, val, !orr);
    else
        update(2 * idx + 1, mid + 1, r, pos, val, !orr);

    if (orr) tree[idx] = tree[2 * idx] | tree[2 * idx + 1];
    else tree[idx] = tree[2 * idx] ^ tree[2 * idx + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int size = 1 << n;
    for (int i = 0; i < size; i++) cin >> a[i];

    bool start_or = (n % 2 == 1);
    build(1, 0, size - 1, start_or);

    while (q--) {
        int pos; ll val;
        cin >> pos >> val;
        
        pos--;
        update(1, 1-1, size - 1, pos, val, start_or);
        cout << tree[1] << "\n";
    }
}
