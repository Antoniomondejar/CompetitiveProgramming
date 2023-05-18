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
const ll NMAX = 1e5+10;

ll dp[NMAX];
int main(){FIN;
    ll N; cin >> N;
    ll hi[N]; fore(i,0,N) cin >> hi[i];
    dp[0]=0; dp[1]=abs(hi[1]-hi[0]);
    fore(i,2,N){
        dp[i]=min(abs(hi[i]-hi[i-1])+dp[i-1],abs(hi[i]-hi[i-2])+dp[i-2]);
    }
    cout << dp[N-1] << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/