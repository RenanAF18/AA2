#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
struct Node{
	Node* conex[26];
	ll f;

	Node(): f(-1){
		for(int i = 0; i < 26; i++)
			conex[i] = nullptr;
	}
	Node(ll v): f(v){
		for(int i = 0; i < 26; i++)
			conex[i] = nullptr;
	}
};
struct Trie{
	Node* root;
	int sz;
	Trie(): root(new Node()), sz(0){}
	
	void add(string s){
		Node* naux = root;
		ll aux = s.size();

		for(auto c : s){
			int id = c -'a';
			if(naux->conex[id] == nullptr)
				naux->conex[id] = new Node(aux);
			naux = naux->conex[id];
			aux--;
		}
	}
	ll query(string s){
		ll aux = s.size();
		Node* naux = root;

		for(auto c : s){
			int id = c - 'a';
			if(naux->conex[id] == nullptr){
				if(aux == s.size()) return aux;
				if(aux == 1 && naux->f != 1){
					if(naux->f >= s.size()) return s.size();
					else return naux->f;
				}
			}
			aux--;
		}



		return aux;
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