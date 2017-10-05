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

const int N = 1e4 + 7;
string t;
int n;
struct suffix {
	int index;
	int rank[2];
};

bool cmp(suffix a, suffix b) {
	return a.rank[0] == b.rank[0] ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0]) ? 1 : 0;
}
void SA() {
	suffix sa[N];
	for (int i = 0; i < n; i++) {
		sa[i].index = i;
		sa[i].rank[0] = t[i] - 'a';
		sa[i].rank[1] = (i + 1) < n ? t[i + 1] - 'a' : -1;
	}
	sort(sa, sa + n, cmp);
	int ind[N];
	for (int k = 4; k < 2 * n; k = k * 2) {
		int rank = 0;
		int prev_rank = sa[0].rank[0];
		sa[0].rank[0] = rank;
		ind[sa[0].index] = 0;
		for (int i = 1; i < n; i++) {
			if (sa[i].rank[0] == prev_rank and sa[i].rank[1] == sa[i - 1].rank[1]) {
				prev_rank = sa[i].rank[0];
				sa[i].rank[0] = rank;
			}
			else {
				prev_rank = sa[i].rank[0];
				sa[i].rank[0] = ++rank;
			}
			ind[sa[i].index] = i;
		}
		for (int i = 0; i < n; i++) {
			int nextindex = sa[i].index + k / 2;
			sa[i].rank[1]=nextindex<n?sa[ind[nextindex]].rank[0]:-1;
		}
		sort(sa, sa+n, cmp);
	}

	for(int i=0;i<n;i++)
		cout<<sa[i].index<<" ";
}

void solve(){
	cin>>t;
	n=sz(t);
	cout<<n<<endl;
	SA();
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
