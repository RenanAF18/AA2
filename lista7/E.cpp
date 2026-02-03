#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
struct Node{
	Node* conex[26];
	Node(){
		for(int i = 0; i < 26; i++)
			conex[i] = nullptr;
	}
	Node(int v){
		for(int i = 0; i < 26; i++)
			conex[i] = nullptr;
	}
};
struct Trie{
	Node* root;
	int sz;
	Trie(): root(new Node()), sz(0){}
	
	void add(string s){
		Node* aux = root;
		for(auto c : s){
			int id = c -'a';
			if(aux->conex[id] == nullptr)
				aux->conex[id] = new Node();
			aux = aux->conex[id];
		}
	}
	ll query(string s){
		ll aux = s.size();
		Node* naux = root;

		for(auto c : s){
			int id = c - 'a';
			if(naux->conex[id] == nullptr){
				if(aux == s.size()) return aux;

				
			}
		}



		return 1;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	Trie tr;
	while(n--){
		string str; cin >> str;
		cout << tr.query(str) << "\n";
	}
	return 0;
}