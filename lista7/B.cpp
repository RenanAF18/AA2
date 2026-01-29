#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

struct Node{
    int passagens;
    char c;
    Node* conex[26];
    
    Node(): c('0'), passagens(0){
        for (int i = 0; i < 26; i++)
            conex[i] = nullptr;
    }
    Node(char c): c(c), passagens(1){
        for (int i = 0; i < 26; i++)
            conex[i] = nullptr;
    }
    void upFreq(){ 
        passagens++;
    }
};


struct Trie{
    Node* root;
    
    Trie(): root(new Node()){};

    void update(string str){
        Node* aux = root;
        for(char c: str){
            if(aux->conex[c-'a'] != nullptr){
                aux->conex[c-'a']->upFreq();
            }else{
                aux->conex[c-'a'] = new Node(c); 
            }
            aux = aux->conex[c-'a'];
        }
    }
    int search(string str){
        Node* aux = root;
        for(auto c : str){
            int id = c - 'a';
            if(aux->conex[c - 'a'] == nullptr) return 0;
            aux = aux->conex[c - 'a'];
        }
        return aux->passagens;
    }
};




int main(){

    cin.tie(0)->sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    Trie tr;
    while(n--){
        string str; cin >> str;
        tr.update(str);
    }
    while(q--){
        string busca; cin >> busca;
        cout << tr.search(busca) << '\n';
    }
    return 0;
}