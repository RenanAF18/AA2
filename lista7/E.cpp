#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
struct Node {
    Node* next[26];
    ll min_len;

    Node() : min_len(LLONG_MAX) {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};
struct Trie{
	Node* root;
	int sz;
	Trie(): root(new Node()), sz(0){}
	
	void add(string s){
		Node* naux = root;
		root->min_len = min(root->min_len, (ll)s.length());

		for (auto c : s){
			int id = c - 'a';
			if (!naux->next[id])
				naux->next[id] = new Node();
			naux = naux->next[id];
			naux->min_len = min(naux->min_len, (ll)s.length());
		}
	}
	ll query(string s){
		Node* naux = root;
		ll depth = 0;
		ll ans = s.length();

		for (auto c : s){
			int id = c - 'a';
			if (!naux->next[id]) break;

			naux = naux->next[id];
			depth++;
			ans = min(ans, (ll)s.length() + naux->min_len - 2 * depth);
		}
		return ans;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int aux = n;
	Trie tr;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		if (i == 0) {
			cout << str.length() << '\n';
		} else {
			cout << tr.query(str) << '\n';
		}
		tr.add(str);
	}
	return 0;
}