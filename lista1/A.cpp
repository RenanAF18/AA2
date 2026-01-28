#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5; // ajuste conforme necessário
vector<long long> seg;
vector<long long> a;

int left(int i)  { return i << 1; }
int right(int i) { return (i << 1) | 1; }

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
    } else {
        int mid = (l + r) >> 1;
        build(left(id), l, mid);
        build(right(id), mid + 1, r);
        seg[id] = seg[left(id)] + seg[right(id)];
    }
}

void muda(int id, int l, int r, int posi, long long value) {
    if (l == r) {
        seg[id] = value;
    } else {
        int mid = (l + r) >> 1;
        if (posi <= mid)
            muda(left(id), l, mid, posi, value);
        else
            muda(right(id), mid + 1, r, posi, value);
        seg[id] = seg[left(id)] + seg[right(id)];
    } 
}

long long query(int id, int l, int r, int lq, int rq) {
    if (rq < l || lq > r) return 0;
    if (lq <= l && r <= rq) return seg[id];
    int mid = (l + r) >> 1;
    return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    seg.assign(4 * n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    while (q--) {
        int qu;
        long long aa, b;
        cin >> qu >> aa >> b;
        if (qu == 1) {
            muda(1, 0, n - 1, aa - 1, b);
        } else {
            cout << query(1, 0, n - 1, aa - 1, b - 1) << '\n';
        }
    }

    return 0;
}
