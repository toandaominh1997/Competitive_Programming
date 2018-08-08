#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<=n;i++)
#define ROF(i,a,b) for(int i=n;i>=a;i--)
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
#define ONLINE_JUDGE 0
/*
Author: Bigkizd(Toan Dao Minh)
END OF TEMPLATE - ACTUAL SOLUTION COMES HERE
*/

int bigkizd(){

}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    if(ONLINE_JUDGE==0){
        freopen("in.txt", "r", stdin);
    }
    bigizd();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}