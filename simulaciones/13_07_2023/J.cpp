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
const ll MOD = 1e9+7;

double dp[NMAX][NMAX];
double ac[NMAX][NMAX];
ll n,m;double k;
string s1,s2;
// pair<double,double> f(ll x, ll y){
//     if(x==n && y==m)return {0,0};
//     pair<double,double> &r = dp[x][y];
//     if(r.fst!=-1.0)return r;
//     if(x==n){
//         r.fst = min(1.0+f(x,y+1).fst,k+f(x,y+1).snd/double((m-y)));
//     } else if (y==m){
//         r.fst = min(1.0+f(x+1,y).fst,k+f(x+1,y).snd/double((n-x)));
//     } else if(s1[x]==s2[y]){
//         r.fst = f(x+1,y+1).fst;
//     } else {
//         r.fst = min({1.0+f(x+1,y).fst,1.0+f(x,y+1).fst,k+((f(x+1,y).snd+f(x,y+1).snd-f(x+1,y+1).snd)/double(((n-x+1)*(m-y+1))-1))});
//     }
//     if(x==n){
//         r.snd=r.fst+f(x,y+1).snd;
//     } else if(y==m){
//         r.snd=r.fst+f(x+1,y).snd;
//     } else {
//         r.snd=r.fst+f(x+1,y).snd+f(x,y+1).snd-f(x+1,y+1).snd;
//     }
//     cout << x << " " << y << " " << r.fst << " " << r.snd << "\n";
//     return r;
// }

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cout << setprecision(8);
        cin>>n>>m>>k;
        cin>>s1>>s2;
        // cout << s << " " << t << "\n";
        dp[n][m]=0; ac[n][m]=0;
        for(int i=n;i>=0;--i){
            for(int j=m;j>=0;--j){
                if(i==n && j==m)continue;
                if(i==n){
                    // cout<<i<<" "<<j<<" "<<ac[i][j+1]<<"\n";
                    dp[i][j]=min(1+dp[i][j+1],k+ac[i][j+1]/double(m-j));
                    ac[i][j]=dp[i][j]+ac[i][j+1];
                } else if(j==m){
                    // cout << i <<" "<<j<<" "<<ac[i+1][j]<<"\n";
                    dp[i][j]=min(1+dp[i+1][j],k+ac[i+1][j]/double(n-i));
                    ac[i][j]=dp[i][j]+ac[i+1][j];
                } else if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                    ac[i][j]=dp[i][j]+ac[i][j+1]+ac[i+1][j]-ac[i+1][j+1];
                } else {
                    // cout <<i << " " << j << " " << ac[i+1][j]+ac[i][j+1]-ac[i+1][j+1] << "\n";
                    dp[i][j]=min({1+dp[i+1][j],1+dp[i][j+1],k+ac[i+1][j+1]/double((n-i)*(m-j))});
                    ac[i][j]=dp[i][j]+ac[i][j+1]+ac[i+1][j]-ac[i+1][j+1];
                }
            }
        }
        // fore(i,0,n+1)fore(j,0,m+1)cout << i << " " << j << " " << dp[i][j] << "\n";
        // fore(i,0,n+1)fore(j,0,m+1)cout << i << " " << j << " " << ac[i][j] << "\n";
        // fore(i,0,n+5)fore(j,0,m+5)dp[i][j]={-1.0,-1.0};
        // double res = f(0,0).fst;
        cout << dp[0][0] << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/