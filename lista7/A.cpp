#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

struct Node{
    Node* bit1;
    Node* bit2;

    Node(): bit1(nullptr), bit2(nullptr){}

    void connect1(Node* no){
        bit1 = no;
    }
    void connect2(Node* no){
        bit2 = no;
    }
};

struct Trie{
    Node root


}

int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    ll n, q; cin >> n >> q;
    
    return 0;
}