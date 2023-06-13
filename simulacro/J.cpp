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
ll dp[14][109][109][2];
vector<int> di;

void get_d(ll x){
    while(x>0){
        di.pb(x%10);
        x/=10;
    }
    reverse(ALL(di));
}

ll suM;

ll f(int x, int re, int sum, bool b){
    if(x == SZ(di) && re == 0 && sum==suM) return 1;
    if(x == SZ(di) && (re!=0 || sum != suM)) return 0;
    if(dp[x][re][sum][b] != -1)return dp[x][re][sum][b];
    if(b){
        dp[x][re][sum][b] = 0;
        for(int i = 9; i>=0; --i){
            dp[x][re][sum][b]+=f(x+1,(re*10+i)%suM,sum+i,b);
        }
    } else {
        dp[x][re][sum][b] = f(x+1, (re*10+di[x])%suM, sum+di[x], b);
        for(int i = di[x]-1; i>=0; --i){
            dp[x][re][sum][b]+=f(x+1,(re*10+i)%suM,sum+i,1);
        }
    }
    return dp[x][re][sum][b];
}


int main(){FIN;
    #ifdef ONLINE_JUDGE
        freopen("just.in","r",stdin);
        freopen("just.out","w",stdout);
    #endif
    ll n; cin >> n;
    get_d(n);
    ll res = 0;
    mset(dp,-1);
    fore(i,1,110){
        suM = i;
        res += f(0,0,0,0);
        mset(dp,-1);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/