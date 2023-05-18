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
const ll NMAX = 3e3+10;
ll N;
long double dp[NMAX][NMAX];
long double p[NMAX];

long double f(ll x, ll c){
    if(x==-1 && c < (N/2)+1) return 0.0;
    if(x==-1)return 1.0;
    if(dp[x][c] != -1.0)return dp[x][c];
    dp[x][c] = p[x]*f(x-1,c+1)+(1.0-p[x])*f(x-1,c);
    return dp[x][c];
}

int main(){FIN;
    cin >> N; fore(i,0,N)cin>>p[i];
    fore(i,0,N)fore(j,0,N)dp[i][j]=-1.0;
    long double res = f(N-1,0);
    cout << setprecision(12);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/