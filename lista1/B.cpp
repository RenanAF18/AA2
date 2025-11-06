#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int NEG_INF = -INF;

vector<int> a;
vector<int> MAX1, MAX2;

int left(int i) { return i << 1; }
int right(int i) { return (i << 1) | 1; }

void build(int id, int l, int r) {
    if (l == r) {
        MAX1[id] = a[l];
        MAX2[id] = NEG_INF;
    } else {
        int mid = (l + r) >> 1;
        build(left(id), l, mid);
        build(right(id), mid + 1, r);
        vector<int> valores = {MAX1[left(id)], MAX1[right(id)], MAX2[left(id)], MAX2[right(id)]};
        sort(valores.begin(), valores.end(), greater<int>());
        MAX1[id] = valores[0];
        MAX2[id] = valores[1];
    }
}

void mudar(int id, int l, int r, int posi, int value) {
    if (l == r) {
        a[posi] = value;
        MAX1[id] = value;
        MAX2[id] = NEG_INF;
    } else {
        int mid = (l + r) >> 1;
        if (posi <= mid)
            mudar(left(id), l, mid, posi, value);
        else
            mudar(right(id), mid + 1, r, posi, value);

        vector<int> valores = {MAX1[left(id)], MAX1[right(id)], MAX2[left(id)], MAX2[right(id)]};
        sort(valores.begin(), valores.end(), greater<int>());
        MAX1[id] = valores[0];
        MAX2[id] = valores[1];
    }
}

pair<int, int> query(int id, int l, int r, int lq, int rq) {
    if (rq < l || r < lq)
        return {NEG_INF, NEG_INF};
    if (lq <= l && r <= rq)
        return {MAX1[id], MAX2[id]};

    int mid = (l + r) >> 1;
    auto leftRes = query(left(id), l, mid, lq, rq);
    auto rightRes = query(right(id), mid + 1, r, lq, rq);

    vector<int> valores = {leftRes.first, leftRes.second, rightRes.first, rightRes.second};
    sort(valores.begin(), valores.end(), greater<int>());
    return {valores[0], valores[1]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int q;
    cin >> q;

    MAX1.assign(4 * (n + 1), NEG_INF);
    MAX2.assign(4 * (n + 1), NEG_INF);

    build(1, 1, n);

    while (q--) {
        char qu;
        int x, y;
        cin >> qu >> x >> y;
        if (qu == 'U') {
            mudar(1, 1, n, x, y);
        } else {
            auto resu = query(1, 1, n, x, y);
            if (resu.second == NEG_INF)
                cout << resu.first << "\n";
            else
                cout << resu.first + resu.second << "\n";
        }
    }

    return 0;
}
