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
const ll NMAX = 1e5+10;
ll n,m,k;
vector<pair<ll,ll>> fl[NMAX];
vector<ll> lad[NMAX];
ll dp[NMAX][2][2];

#define Right 1
#define Left 0
#define Top 0
#define Down 1
vector<ll> x_i(NMAX);

ll f(ll x, ll b, ll d){
    if(dp[x][b][d] < 1e18) return dp[x][b][d];
    ll res = 1e17;
    if(b==Top){
        ll act_f = lad[x][2]; ll act_r = lad[x][3];
        if(act_f==n){
            return abs(act_r-m)*x_i[n];
        }
        if(SZ(fl[act_f])==0) res=1e17;
        else {
            ll next = lower_bound(ALL(fl[act_f]), mp(act_r,x))-fl[act_f].begin()-(d==Left);
            if(next < SZ(fl[act_f]) && next >= 0){
                ll next_i = fl[act_f][next].snd;
                ll next_r = fl[act_f][next].fst;
                ll aux = f(next_i,Down,d);
                res = min((ll)1e17,abs(next_r-act_r)*x_i[act_f]+aux);
            }
        }
    } else if(d == Left){
        ll act_f = lad[x][0]; ll act_r = lad[x][1];
        ll next = lower_bound(ALL(fl[act_f]), mp(act_r,x))-fl[act_f].begin()-1;
        if(next>=0){
            ll next_i = fl[act_f][next].snd;
            ll next_r = fl[act_f][next].fst;
            ll aux = f(next_i,Down,d);
            res = min((ll)1e17,abs(next_r-act_r)*x_i[act_f]+aux);
        }
        ll aux1 = f(x,Top,Right);
        if(aux1<1e17)res = min(res,aux1-lad[x][4]);
        ll aux2 = f(x,Top,Left);
        if(aux2<1e17)res = min(res, aux2-lad[x][4]);
    } else {
        ll act_f = lad[x][0]; ll act_r = lad[x][1];
        ll next = lower_bound(ALL(fl[act_f]), mp(act_r,x))-fl[act_f].begin()+1;
        if(next<SZ(fl[act_f])){
            ll next_i = fl[act_f][next].snd;
            ll next_r = fl[act_f][next].fst;
            ll aux = f(next_i,Down,d);
            res = min((ll)1e17,abs(next_r-act_r)*x_i[act_f]+aux);
        }
        ll aux1 = f(x,Top,Right); 
        if(aux1<1e17)res = min(res,aux1-lad[x][4]);
        ll aux2 = f(x,Top,Left);
        if(aux2<1e17)res = min(res,aux2-lad[x][4]);
    } 
    dp[x][b][d] = res;
    return res;
} 


int main(){FIN;
    ll t; cin >> t;
    while(t--){
        cin>>n>>m>>k;
        fore(i,0,k+5)lad[i].clear();
        fore(i,0,k+5)fore(j,0,2)fore(x,0,2)dp[i][j][x]=1e18;
        fore(i,0,n+5)fl[i].clear();
        fore(i,1,n+1)cin>>x_i[i];
        fore(i,1,k+1){
            ll a,b,c,d,h;cin>>a>>b>>c>>d>>h;
            fl[a].pb({b,i});
            lad[i]={a,b,c,d,h};
        }
        lad[0] = {1,1,1,1,1};
        // fl[n].pb({m,k+1});
        fore(i,1,n+1)sort(ALL(fl[i]));
        ll res = f(0,Top,Right);
        if(res >= 1e17){
            cout << "NO ESCAPE\n";
        } else {
            cout << res << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/