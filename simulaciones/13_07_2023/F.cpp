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
const ll NMAX = 2e3+10;
const ll MOD = 1e9+7;
 
ll dp[NMAX][NMAX];
ll n,h,k;
vector<pair<ll,ll>> h_s;
 
ll f(ll x, ll cua){
    if(x==n)return 0;
    ll &res=dp[x][cua];
    if(res!=1e18)return res;
    if(cua){
        res = min(max(h_s[x].fst,h_s[x].fst+f(x+1,cua)-h_s[x].snd),f(x+1,cua-1));
    } else {
        res = max(h_s[x].fst,h_s[x].fst-h_s[x].snd+f(x+1,cua));
    }
    // cout << x << " " << cua << " " << res << "\n";
    return res;
}
 
int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n>>h>>k;
        vector<pair<ll,ll>>pos;vector<pair<ll,ll>>neg;
        fore(i,0,n){
            ll x,y;cin>>x>>y;
            if(x<=y)pos.pb({x,y});
            else neg.pb({-y,x});
        }
        sort(ALL(pos));sort(ALL(neg));
 
        for(auto i:pos)h_s.pb(i);
        for(auto i:neg)h_s.pb({i.snd,-i.fst});
        fore(i,0,n)fore(j,0,k+1)dp[i][j]=1e18;
        ll mini = f(0,k);
        if(mini<h)cout << "Y\n";
        else cout << "N\n";
        h_s.clear();
    }
    return 0;
}
 
/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/