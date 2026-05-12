#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

struct seg_tree {
    struct node {
        vector<ll> x = vector<ll>(30, 0);

        node() : x(30, 0) {}

        node(ll v) : x(30, 0) {
            rep(i, 0, 30) if (v & (1LL << i)) x[i] = 1;
        }

        node(const vector<ll>& v) : x(v) {}
            
        node operator+(const node &o) const {
            vector<ll> aux(30);

            rep(i, 0, 30){
                aux[i] = x[i] + o.x[i];
            }

            return node(aux);
        }
    };

    struct lazy_node {
        ll xorr;
        lazy_node() : xorr(0) {}
    };

    int n;
    vector<node> tree;
    vector<lazy_node> lazy;
    
    seg_tree(vector<ll> a) {
        n = a.size();
        tree.resize(n * 4);
        lazy.resize(n * 4);
        build(1, 0, n - 1, a);
    }
    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }
    void build(int id, int l, int r, const vector<ll> &a) {
        if (l == r) tree[id] = node(a[l]);
        else {
            int m = (l + r) >> 1;
            build(left(id), l, m, a);
            build(right(id), m + 1, r, a);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    inline void push(int id, int l, int r) {
        if (lazy[id].xorr) {
            int len = r - l + 1;
            
            rep(i, 0, 30){
                if(lazy[id].xorr & (1LL << i))
                    tree[id].x[i] = len - tree[id].x[i];
            }
            
            if (l != r) {
                lazy[left(id)].xorr ^= lazy[id].xorr;
                lazy[right(id)].xorr ^= lazy[id].xorr;
            }

            lazy[id].xorr = 0;
        }
    }

    void update(int id, int l, int r, int lq, int rq, ll val) {
        push(id, l, r);
        if (l > rq || r < lq) return;
        if (lq <= l && r <= rq) {
            int len = r - l + 1;
            rep(i, 0, 30){
                if(val & (1LL << i))
                    tree[id].x[i] = len - tree[id].x[i];
            }

            if (l != r) {
                lazy[left(id)].xorr ^= val;
                lazy[right(id)].xorr ^= val;
            }
        } else {
            int mid = (l + r) >> 1;
            update(left(id), l, mid, lq, rq, val);
            update(right(id), mid + 1, r, lq, rq, val);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    node query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }

    void update(int l, int r, ll val) { update(1, 0, n - 1, l, r, val); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve_tc(){
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;

    seg_tree tree(a);
    int m; cin >> m;

    while(m--){
        int op; cin >> op;

        if(op == 1){
            int l, r; cin >> l >> r;
            l--;
            r--;
            vector<ll> resp = tree.query(l, r).x;

            ll val = 0;

            rep(i, 0, 30){
                if(resp[i]) val += resp[i] * (1LL << i);
            }

            cout << val << endl;
        }
        else{
            int l, r; cin >> l >> r;
            ll v; cin >> v;
            l--;
            r--;

            tree.update(l, r, v);
        }

    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1;
    while(tc--) solve_tc();
    
    return 0;
}