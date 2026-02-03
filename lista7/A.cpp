#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<ll> vii;

struct Node{
    Node* bit0;
    Node* bit1;
    Node(): bit0(nullptr), bit1(nullptr){}
};

struct Trie{
    Node* root;
    Trie(): root(new Node()){}
    
    void update(ll x){
        Node* aux = root;
        for(int i = 40; i >= 0; i--){
            if(x & (1LL << i)){
                if(!aux->bit1)
                    aux->bit1 = new Node();
                aux = aux->bit1;
            }
            else{
                if(!aux->bit0)
                    aux->bit0 = new Node();
                aux = aux->bit0;
            }
        }
    }
    
    ll max1(ll v){
        Node* aux = root;
        ll sum = 0;
        for(int i = 40; i >= 0; i--){
            if(v & (1LL << i)){
                if(aux->bit0){
                    sum += 1LL << i;
                    aux = aux->bit0;
                }
                else if(aux->bit1){
                    aux = aux->bit1;
                }
                else return sum;
            }
            else{
                if(aux->bit1){
                    sum += 1LL << i;
                    aux = aux->bit1;
                }
                else if(aux->bit0){
                    aux = aux->bit0;
                }
                else return sum;
            }
        }
        return sum;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vii v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    Trie tr;
    tr.update(0);
    ll xorr = 0;
    ll ans = 0;
    for(int j = 0; j < n; j++){
        xorr ^= v[j];
        ans = max(ans, tr.max1(xorr));
        tr.update(xorr);
    }
    
    cout << ans << endl;
    return 0;
}