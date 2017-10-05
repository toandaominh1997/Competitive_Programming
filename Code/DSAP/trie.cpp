#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <=(b); ++i)
#define FORD(i, a, b) for (int i = (a); i >=(b); --i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); --i)
#define db(X) { cerr << #X << " = " << (X) << endl; }
#define pr(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define pr0(A, n) { cerr << #A << " = "; rep(_, n) cerr << A[_] << ' '; cerr << endl; }
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

struct Node {
	Node *trie[26];
	bool isleaf;
};
Node* getNode() {
	Node *node = new Node;
	for (int i = 0; i < 26; i++)
		node->trie[i] = NULL;
	node->isleaf = false;
	return node;
}
void insert(Node *root, string key) {
	Node *temp = root;
	for (int i = 0; i < sz(key); i++) {
		int idx = key[i] - 'a';
		if (!temp->trie[idx])
			temp->trie[idx] = getNode();
		temp = temp->trie[idx];
	}
	temp->isleaf=true;
}
bool search(Node *root, string key) {
	Node *temp=root;
	for (int i = 0; i < sz(key); i++) {
		int idx=key[i]-'a';
		if(!temp->trie[idx])
			return false;
		temp=temp->trie[idx];
	}
	return temp->isleaf==true and temp!=NULL;
}
void solve(){
	Node *root=getNode();
	insert(root, "toan");
	insert(root, "ba");
	insert(root, "me");
	insert(root, "google");
	printf("%s", search(root,"toan")?"true":"false");
}

int32_t main() {
	int JUDGE_ONLINE = 1;
	if (fopen("in.txt", "r")) {
		JUDGE_ONLINE = 0;
		assert(freopen("in.txt", "r", stdin));
		//assert(freopen("out.txt", "w", stdout));
	}
	else {
		ios_base::sync_with_stdio(0), cin.tie(0);
	}
	solve();
	if (!JUDGE_ONLINE) {
		//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	}
	return 0;
}
