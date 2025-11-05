#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

    vector<ll> tree;
    vector<ll> lazy;

void update(int idx, int l, int r, int e, int d, ll val){
    if(l > d || r < e)
        return;
    if(l >= e && r <=d){
        tree[idx] += val * (r - l + 1);
        if(l != r){
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
    }
    int mid = (l + r)/2;
    update(idx * 2, l, mid, e, d, val);
    update(idx * 2 + 1, l, mid, e, d, val);
    tree[idx] = tree[idx*2] + tree[idx*2 + 1];
}

void solve_tc(){
    int n, c;
    cin >> n,c;

    vector<ll> tree(4 * n + 10);
    vector<ll> lazy(4 * n + 10);
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}