#include <bits/stdc++.h>
#include <climits>
#include <sstream>
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

template <class T> struct seg_tree {
  struct node {
    T x;
    node() : x(LLONG_MAX) {}
    node(T x) : x(x) {}
    node operator+(const node &o) const { return node(min(x, o.x)); }
  };
  struct lazy_node {
    T add, set;
    lazy_node() : add(0), set(0) {}
  };
  int n;
  vector<node> tree;
  vector<lazy_node> lazy;
  seg_tree(vector<T> a) {
    n = a.size();
    tree.resize(n * 4);
    lazy.resize(n * 4);
    build(1, 0, n - 1, a);
  }
  inline int left(int id) { return (id << 1); }
  inline int right(int id) { return (id << 1) | 1; }
  void build(int id, int l, int r, const vector<T> &a) {
    if (l == r)
      tree[id] = node(a[l]);
    else {
      int m = (l + r) >> 1;
      build(left(id), l, m, a);
      build(right(id), m + 1, r, a);
      tree[id] = tree[left(id)] + tree[right(id)];
    }
  }
  inline void push(int id, int l, int r) {
    if (lazy[id].set) {
      tree[id].x = lazy[id].set;
      if (l != r) {
        lazy[left(id)].add = 0;
        lazy[right(id)].add = 0;
        lazy[left(id)].set = lazy[id].set;
        lazy[right(id)].set = lazy[id].set;
      }
      lazy[id].set = 0;
    }
    if (lazy[id].add) {
      tree[id].x += lazy[id].add;
      if (l != r) {
        lazy[left(id)].add += lazy[id].add;
        lazy[right(id)].add += lazy[id].add;
      }
      lazy[id].add = 0;
    }
  }
  template <bool ADD> void update(int id, int l, int r, int lq, int rq, T val) {
    push(id, l, r);
    if (l > rq || r < lq)
      return;
    if (lq <= l && r <= rq) {
      if (ADD)
        lazy[id].add += val;
      else
        lazy[id].set = val, lazy[id].add = 0;
      push(id, l, r);
    } else {
      int mid = (l + r) >> 1;
      update<ADD>(left(id), l, mid, lq, rq, val);
      update<ADD>(right(id), mid + 1, r, lq, rq, val);
      tree[id] = tree[left(id)] + tree[right(id)];
    }
  }
  node query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq)
      return node();
    if (lq <= l && r <= rq)
      return tree[id];
    int mid = (l + r) >> 1;
    return query(left(id), l, mid, lq, rq) +
           query(right(id), mid + 1, r, lq, rq);
  }
  template <bool ADD> void update(int l, int r, T val) {
    update<ADD>(1, 0, n - 1, l, r, val);
  }
  node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve_tc() {
  int n;
  cin >> n;
  vector<ll> a(n);

  for (ll &x : a)
    cin >> x;

  seg_tree<ll> tree(a);

  int q;
  cin >> q;
  cin.ignore();
  while (q--) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<ll> vals;
    ll x;
    while (ss >> x)
      vals.pb(x);

    if (sz(vals) == 3) {
      if (vals[0] > vals[1]) {
        tree.update<true>(vals[0], n - 1, vals[2]);
        tree.update<true>(0, vals[1], vals[2]);
      } else {
        tree.update<true>(vals[0], vals[1], vals[2]);
      }
    } else {
      if (vals[0] > vals[1])
        cout << min(tree.query(vals[0], n - 1).x, tree.query(0, vals[1]).x)
             << endl;
      else {
        cout << tree.query(vals[0], vals[1]).x << endl;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc = 1;
  while (tc--)
    solve_tc();

  return 0;
}
