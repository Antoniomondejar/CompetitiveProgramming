#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int NMAX = 1e5+10;
const ll MOD = 1e9+7;

int dp[NMAX][256];
int n;
vector<int> a; int ma;
int f(int x, int res){
    if(x==n)return res;
    int &r = dp[x][res];
    if(r!=-1)return r;
    r = max({res, f(x+1,res^a[x]),f(x+1,a[x])});
    return r;
}


int main(){FIN;
    ll t; cin >> t;
    while(t--){
        cin >> n;
        fore(i,0,n)fore(j,0,257)dp[i][j]=-1;
        a.resize(n);
        ma=-1;
        fore(i,0,n)cin>>a[i],ma=max(ma,a[i]);
        ll res = f(0,0);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/