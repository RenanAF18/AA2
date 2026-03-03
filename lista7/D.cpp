#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool end;
    Node* conex[3];

    Node(): end(false){
        for(int i=0;i<3;i++) conex[i] = nullptr;
    }
};

struct Trie{
    Node* root;

    Trie(){ root = new Node(); }

    void update(const string& s){
        Node* cur = root;
        for(char c : s){
            int id = c - 'a';
            if(!cur->conex[id])
                cur->conex[id] = new Node();
            cur = cur->conex[id];
        }
        cur->end = true;
    }

    bool dfs(Node* node, const string& s, int pos, bool used){
        if(!node) return false;

        if(pos == (int)s.size())
            return node->end && used;

        int id = s[pos] - 'a';

        for(int i=0;i<3;i++){
            if(node->conex[i]){
                if(i == id){
                    if(dfs(node->conex[i], s, pos+1, used))
                        return true;
                } else if(!used){
                    if(dfs(node->conex[i], s, pos+1, true))
                        return true;
                }
            }
        }
        return false;
    }

    string search(const string& s){
        return dfs(root, s, 0, false) ? "YES" : "NO";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Trie tr;

    while(n--){
        string s;
        cin >> s;
        tr.update(s);
    }

    while(q--){
        string s;
        cin >> s;
        cout << tr.search(s) << '\n';
    }
}
