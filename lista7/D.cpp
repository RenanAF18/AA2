#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

struct Node{
    char c;
    Node* conex[3];
    
    Node(): c('0'){
        for (int i = 0; i < 3; i++)
            conex[i] = nullptr;
    }
    Node(char c): c(c){
        for (int i = 0; i < 3; i++)
            conex[i] = nullptr;
    }
};


struct Trie{
    Node* root;
    
    Trie(): root(new Node()){};

    void update(string str){
        Node* aux = root;
        for(char c: str){
            if(aux->conex[c-'a'] == nullptr)
                aux->conex[c-'a'] = new Node(c);

            aux = aux->conex[c-'a'];
        }
    }
    string search2(string str, int v){
        if (root->conex[(str[0] - 'a' + v) % 3] == nullptr) return "No";
        Node* aux = root->conex[(str[0] - 'a' + v) % 3];

        for(char c : str){
            int id = c - 'a';
            if (aux->conex[id] == nullptr) return "No";
            aux = aux->conex[id];
        }
        return "Yes";
    }

    string search(string str){
        Node* aux = root;
        int errado = 0;
        string auxS = str;

        string um = search2(auxS.erase(0,1),1);
        auxS = str;
        string dois = search2(auxS.erase(0,1),2);
        if(um == "Yes") return um;
        if(dois == "Yes") return dois;

        Node* a = nullptr;
        Node* b = nullptr;

        for(auto c : str){
            int id = c - 'a';
            
            if (aux->conex[c - 'a'] == nullptr && a != nullptr && b != nullptr){
                if(errado == 1) return "No";
                if(aux->conex[(c - 'a' + 1) % 3] != nullptr)
                    a =  aux->conex[(c - 'a' + 1) % 3];
                if(aux->conex[(c - 'a' + 2) % 3] != nullptr)
                    b = aux->conex[(c - 'a' + 1) % 3];
                errado++;
            }
            if (aux->conex[c - 'a'] != nullptr) aux = aux->conex[c - 'a'];

            if(a != nullptr){
                
            }
        }
        return "Yes";
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