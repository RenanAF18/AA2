#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

struct SegTree {
    vector<int> tree;
    int n;
    
    SegTree(int size) : n(size) {
        tree.assign(4 * n, 0);
    }
    
    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2*node, l, mid, pos, val);
        else
            update(2*node+1, mid+1, r, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
    }
    
    int kth(int node, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left_count = tree[2*node];
        if (k <= left_count)
            return kth(2*node, l, mid, k);
        return kth(2*node+1, mid+1, r, k - left_count);
    }
    
    void insert(int pos) {
        update(1, 0, n-1, pos, 1);
    }
    
    void remove(int pos) {
        update(1, 0, n-1, pos, -1);
    }
    
    int count_less(int pos) {
        if (pos <= 0) return 0;
        return query(1, 0, n-1, 0, pos-1);
    }
    
    int find_kth(int k) {
        return kth(1, 0, n-1, k);
    }
    
    int total() {
        return tree[1];
    }
};

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int Q;
    cin >> Q;
    
    vector<char> ops;
    vector<ll> vals;
    set<ll> all_vals;
    
    rep(i, 0, Q) {
        char op;
        ll x;
        cin >> op >> x;
        ops.push_back(op);
        vals.push_back(x);
        all_vals.insert(x);
    }
    
    // Compressão de coordenadas
    vector<ll> sorted_vals(all_vals.begin(), all_vals.end());
    map<ll, int> compress;
    rep(i, 0, sorted_vals.size()) {
        compress[sorted_vals[i]] = i;
    }
    
    SegTree seg(sorted_vals.size());
    set<ll> current;
    
    rep(i, 0, Q) {
        char op = ops[i];
        ll x = vals[i];
        
        if (op == 'I') {
            if (current.count(x) == 0) {
                seg.insert(compress[x]);
                current.insert(x);
            }
        }
        else if (op == 'D') {
            if (current.count(x) > 0) {
                seg.remove(compress[x]);
                current.erase(x);
            }
        }
        else if (op == 'K') {
            int k = x;
            if (k > seg.total()) {
                cout << "invalid" << endl;
            } else {
                int pos = seg.find_kth(k);
                cout << sorted_vals[pos] << endl;
            }
        }
        else if (op == 'C') {
            int pos = lower_bound(sorted_vals.begin(), sorted_vals.end(), x) - sorted_vals.begin();
            cout << seg.count_less(pos) << endl;
        }
    }
    
    return 0;
}