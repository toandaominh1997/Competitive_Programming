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

typedef long long ll;
const ll mod=1e9+3;
const ll maxn=1000111;

ll pow[maxn];
hashT[maxn];
ll getHashT(int i, int j){
	return (hashT[j]-hashT[i-1]*pow[j-1+1]+MOD*MOD)%MOD;
}

void solve(){
	string T, P;
	cin>>T>>P;
	int m=sz(T), n=sz(P);
	T=" "+T;
	P=" "+P;
	pow[0]=1;
	for(int i=1;i<=m;i++){
		pow[i]=(pow[i-1]*26)%mod;
	}
	for(int i=1;i<=m;i++){
		hashT[i]=(hashT[i-1]*26 +T[i]-'a')%mod;
	}
	ll hashP=0;
	for(int i=1;i<=n;i++)
		hashP=(hashP*26+P[i]-'a')%mod;
	for(int i=1;i<=m-n+1;i++)
		if(hashP==getHashT(i,i+n-1))
			printf("%d ", i);
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

    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}
