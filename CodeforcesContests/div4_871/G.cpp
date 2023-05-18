#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 1e6+10;
ll dp[NMAX];
ll rows[NMAX];

int main(){FIN;
    dp[1] = 1; dp[2] = 5; dp[3] = 10;
    ll last_number = 1;
    fore(i,0,2023){
        fore(j,last_number,last_number+i+1){
            if(j==NMAX) break;
            rows[j] = i+1;
            ++last_number;
        }
    }
    fore(i,4,NMAX){
        if(rows[i-1] < rows[i]){
            dp[i] = i*i+dp[i-rows[i-1]];
        } else if(i < NMAX && rows[i+1]>rows[i]){
            dp[i] = i*i+dp[i-rows[i]];
        } else {
            dp[i] = i*i+dp[i-rows[i]]+dp[i-rows[i]+1]-dp[i-rows[i]+1-rows[i-rows[i]+1]];
        }
    }
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/