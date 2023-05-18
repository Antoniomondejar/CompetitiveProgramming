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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> b(n);
        fore(i,0,n) cin >> b[i];
        ll dp[n][3];
        fore(i,0,n){
            fore(j,0,3){
                if(i==0 && j == 0) dp[i][j] = b[0]-1;
                else if(i == 0) dp[i][j] = -(1e17);
                else if(j == 0) dp[i][j] = max(b[i]-1,dp[i-1][j]-1);
                else if(j == 2) dp[i][j] = max(dp[i-1][j-1]+b[i], dp[i-1][j]);
                else dp[i][j] = max(dp[i-1][j-1]+b[i]-1, dp[i-1][j]-1);
            }
        }
        cout << dp[n-1][2] << "\n";
    }
    return 0;
}