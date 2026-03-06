#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());



const int NN = 2e6 + 1, K = 2, P = uniform_int_distribution<int>(256, 1e9)(rng);
const ll MOD[] = {1000893493, 1013782387};
ll ph[NN][K], hh[NN][K], IT;
void pre() { rep(i, 0, NN) rep(j, 0, K) ph[i][j] = i ? ph[i - 1][j] * P % MOD[j] : 1; }

int left(int i) {return i * 2;}
int right(int i) {return i * 2 + 1;}

struct Node{
    array<long long, K> h;
    int len;
    Node() {
        for(int i = 0; i < K; i++) h[i] = 0; 
        len = 0;
    }
    Node(char c){
        for(int i = 0; i < K; i++) h[i] = c;
        len = 1;
    }
};

Node merge(Node a, Node b){
        Node r;
        r.len = a.len + b.len;
        for(int j = 0; j  < K; j++)
            r.h[j] = (a.h[j] * ph[b.len][j] + b.h[j]) % MOD[j];
        return r;
}

struct Tree {
    vector<Node> tree;
    Tree(int n) : tree(4 * n + 5) {}

    void build(int node, int l, int r, string &s){
        if(l == r){
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r)/2;
        build(left(node), l, mid, s);
        build(right(node), mid + 1, r, s);

        tree[node] = merge(tree[left(node)], tree[right(node)]);
    }

    Node query(int id, int l, int r, int lq, int rq){
        if(rq < l || lq > r)
            return Node();
        
        if(lq <= l && r <= rq){
            return tree[id];
        }

        int mid =(l + r)/2;
        Node leftt = query(left(id), l, mid, lq, rq);
        Node rightt = query(right(id), mid+1, r, lq, rq);
        return merge(leftt, rightt);
    }

    void update(int id, int l, int r, int x, char c){
        if(l == r){
            tree[id] = Node(c);
            return;
        }
        int mid = (l + r)/2;
        if(x > mid) update(right(id), mid + 1, r, x, c);
        else update(left(id), l, mid, x, c);

        tree[id] = merge(tree[left(id)], tree[right(id)]);
    }
};

struct hsh {
    int L;
    hsh() {}
    hsh(const string &s) {
        L = IT, IT += sz(s);
        rep(i, 0, sz(s)) rep(j, 0, K) {
            hh[L + i][j] = ((i > 0 ? hh[L + i - 1][j] * P : 0) + s[i]) % MOD[j];
        }
    }
    array<ll, K> operator()(int l, int r) {
        array<ll, K> ans;
        rep(j, 0, K) {
            ans[j] = hh[L + r][j] - (l > 0 ? hh[L + l - 1][j] * ph[r - l + 1][j] % MOD[j] : 0);
            if (ans[j] < 0) ans[j] += MOD[j];
        }
        return ans;
    }
};

int main(){
    pre();

    cin.tie(0)->sync_with_stdio(0);
    
    ll n, q; cin >> n >> q;
    string s; cin >> s;

    string rev(s.rbegin(), s.rend());

    s = " " + s;
    rev = " " + rev;

    Tree ts(n), tr(n);
    ts.build(1, 1, n, s);
    tr.build(1, 1, n, rev);
    
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            char c; cin >> c;
            ts.update(1, 1, n, x, c);
            tr.update(1, 1, n, n - x + 1, c);
        }
        else{
            int l, r; cin >> l >> r;
            Node a = ts.query(1, 1, n, l, r);
            Node b = tr.query(1, 1, n, n-r+1, n-l+1);
            cout << (a.h == b.h ? "Yes" : "No") << endl;
        }
    }

    return 0;
}