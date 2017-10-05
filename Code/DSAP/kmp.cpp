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
#define next _next
const int N=1e5+7;
string s;
string p;
int next[N];
void kmp(string s, string p){
	int j;
	j = next[1]=0;
	for(int i=2;s[i];i++){
		while(j>0 and p[j]!=p[i])
			j=next[j];
		if(s[j+1]==s[i])
			j++;
		next[i]=j;
	}
	j=0;
	for(int i=1;s[i];i++){
		while(j>0 and s[i]!=p[j])
			j=next[j];
		if(p[j+1]==s[i])
			j++;
		if(p[j+1]==0){
			printf("%d", i-j+1);
			j=next[j];
		}
	}
}
void solve(){
	//getline(cin, s);
	//getline(cin, p);
	s=" aaaaa";
	p=" aa";
	kmp(s, p);
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
