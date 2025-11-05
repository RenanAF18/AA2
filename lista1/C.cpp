#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;
Node tree[4 * MAXN];
string s;

struct Node {
    ll matched;
    ll open;
    ll close;
    
    Node() : matched(0), open(0), close(0) {}
    
    Node(ll m, ll o, ll c) : matched(m), open(o), close(c) {}
};


Node merge(Node left, Node right) {
    Node result;

    ll new_pairs = min(left.open, right.close);
    
    result.matched = left.matched + right.matched + new_pairs;
    
    result.open = left.open + right.open - new_pairs;
    
    result.close = left.close + right.close - new_pairs;
    
    return result;
}

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = Node();
        
        if (s[l-1] == '(') {
            tree[idx].open = 1;
        } 
        else {
            tree[idx].close = 1;
        }
        return;
    }
    
    int mid = (l + r) / 2;
    
    build(2*idx, l, mid);           
    build(2*idx+1, mid+1, r);
    
    tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) {
        return Node();
    }
    
    if (ql <= l && r <= qr) {
        return tree[idx]; 
    }
    
    int mid = (l + r) / 2;
    
    Node left_result = query(2*idx, l, mid, ql, qr);
    Node right_result = query(2*idx+1, mid+1, r, ql, qr);
    
    return merge(left_result, right_result);
}

int main() {
    cin >> s;
    int n = s.length();
    
    int m;
    cin >> m;
    
    build(1, 1, n);
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
    
        Node result = query(1, 1, n, l, r);
        
        cout << result.matched * 2 << endl;
    }
    
    return 0;
}