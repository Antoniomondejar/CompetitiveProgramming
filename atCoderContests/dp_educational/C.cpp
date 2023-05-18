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

ll dp[NMAX][3];
ll a[NMAX],b[NMAX],c[NMAX];

int main(){FIN;
    ll N; cin >> N;
    fore(i,0,N) cin >> a[i], cin >> b[i], cin >> c[i];
    dp[0][0] = max(b[0],c[0]);dp[0][1] = max(a[0],c[0]); dp[0][2] = max(b[0],c[0]);
    fore(i,1,N)fore(j,0,3){
        if(j==0)
            dp[i][j] = max(b[i]+dp[i-1][1],c[i]+dp[i-1][2]);
        else if(j==1)
            dp[i][j] = max(a[i]+dp[i-1][0],c[i]+dp[i-1][2]);
        else
            dp[i][j] = max(a[i]+dp[i-1][0],b[i]+dp[i-1][1]);
    }
    cout << max({dp[N-1][0],dp[N-1][1], dp[N-1][2]}) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/