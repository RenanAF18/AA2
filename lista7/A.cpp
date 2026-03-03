#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vii;

struct Node{
    Node* bit0;
    Node* bit1;

    Node(): bit0(nullptr), bit1(nullptr){}

    void connect0(Node* no){
        bit0 = no;
    }
    void connect1(Node* no){
        bit1 = no;
    }
};

struct Trie{
    Node* root;

    Trie(): root(new Node){}

    void update(ll x){
        ll aux;
        Node* u = root;

        for(int i = 40; i >= 0; i --){
            aux = 1 << i;
            if(x >= aux){
                if(!u->bit1)
                    u->connect1(new Node());
                u = u->bit1;
                x -= aux;
            }else{
                if(!u->bit0)
                    u->connect0(new Node());
                u = u->bit0;
            }
        }
    }

    ll xorr(ll x){
        Node* u = root;
        ll ans = 0;

        for(int i = 40; i >= 0; i--){
            int bit = (x >> i) & 1;

            if(bit){
                if(u->bit0){
                    ans |= (1LL << i);
                    u = u->bit0;
                }else if(u->bit1){
                    u = u->bit1;
                }else break;
            }else{
                if(u->bit1){
                    ans |= (1LL << i);
                    u = u->bit1;
                }else if(u->bit0){
                    u = u->bit0;
                }else break;
            }
        }

        return ans;
    }


    ll maxSum(){
        ll sum = 0;
        Node* aux = root;
        ll is;

        for(int i = 40; i >= 0; i--){
            is = 1 << i;    

            if(aux->bit1){
                sum += is;
                aux = aux->bit1;
            }else if(aux->bit0) 
                aux = aux->bit0;

            else
                break;
        }

        return sum;
    }
};

int main(){
    Trie tr;
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        ll v; cin >> v;
        if(n == 1)
            tr.update(v);
        else
        tr.update(tr.xorr(v));
    }
    cout << tr.maxSum();
    return 0;
}