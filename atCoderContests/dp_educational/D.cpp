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
const ll NMAX = 1e2+10;
const ll WMAX = 1e5+10;

ll dp[NMAX][WMAX];
ll va[NMAX];
ll wi[NMAX];

int main(){FIN;
    ll N, W; cin >> N >> W;
    fore(i,1,N+1) cin >> wi[i] >> va[i];
    fore(i,0,W+1)dp[0][i] = 0;
    fore(i,1,N+1)fore(j,0,W+1){
        if(j>=wi[i])dp[i][j] = max(dp[i-1][j],va[i]+dp[i-1][j-wi[i]]);
        else dp[i][j] = dp[i-1][j];
    }
    cout << dp[N][W] << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/