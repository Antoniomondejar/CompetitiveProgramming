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
const ll NMAX = 410;
const ll MOD = 1e9+7;
const ll INF = 1e12;


ll g_m[NMAX][NMAX];
ll g_M[NMAX][NMAX];
ll n,r;

int main(){FIN;
    cin>>n>>r;
    vector<ll> t_uni;
    vector<pair<ll,ll>> te(n);
    fore(i,0,n)cin>>te[i].fst,te[i].snd=i,t_uni.pb(te[i].fst);
    map<ll,vector<ll>> pos;
    fore(i,0,n){
        fore(j,0,n){
            if(i==j){g_m[i][j]=0;g_M[i][j]=0;}
            else {g_m[i][j]=INF;g_M[i][j]=INF;}
        }
    }
    fore(i,0,r){
        ll x,y,d;cin>>x>>y>>d;--x;--y;
        g_M[x][y]=d;g_M[y][x]=d;
        g_m[x][y]=d;g_m[y][x]=d;
    }
    sort(ALL(te));
    fore(i,0,n) pos[te[i].fst].pb(i);
    sort(ALL(t_uni));
    unique(ALL(t_uni));
    vector<ll> t_uni_cre=t_uni;
    reverse(ALL(t_uni_cre));
    ll q;cin>>q;
    vector<vector<vector<ll>>> que_m(n), que_M(n);
    ll it=0;
    vector<ll> ans(q);
    while(q--){
        ll x,y,k,ty;
        cin>>x>>y>>k>>ty;
        --x;--y;--k;
        if(ty==0){
            if(k>=SZ(t_uni)) que_m[n-1].pb({x,y,it});
            else que_m[pos[t_uni[k]].back()].pb({x,y,it});
        } else {
            if(k>=SZ(t_uni)) que_M[n-1].pb({x,y,it});
            else que_M[n-1-pos[t_uni_cre[k]][0]].pb({x,y,it});
        }
        ++it;
    }
    fore(k,0,n){
        fore(i,0,n)if(g_m[i][te[k].snd]<INF)fore(j,0,n)if(g_m[te[k].snd][j]<INF)
		    g_m[i][j]=min(g_m[i][j],g_m[i][te[k].snd]+g_m[te[k].snd][j]);
        fore(z,0,SZ(que_m[k])){
            // assert(g_m[que_m[k][z][0]][que_m[k][z][1]]==g_m[que_m[k][z][1]][que_m[k][z][0]]);
            if(g_m[que_m[k][z][0]][que_m[k][z][1]]<INF)ans[que_m[k][z][2]]=g_m[que_m[k][z][0]][que_m[k][z][1]];
            else ans[que_m[k][z][2]]=-1;
        }
    }
    reverse(ALL(te));
    fore(k,0,n){
        fore(i,0,n)if(g_M[i][te[k].snd]<INF)fore(j,0,n)if(g_M[te[k].snd][j]<INF)
		    g_M[i][j]=min(g_M[i][j],g_M[i][te[k].snd]+g_M[te[k].snd][j]);
        fore(z,0,SZ(que_M[k])){
            // assert(g_M[que_M[k][z][0]][que_M[k][z][1]]==g_M[que_M[k][z][1]][que_M[k][z][0]]);
            if(g_M[que_M[k][z][0]][que_M[k][z][1]]<INF)ans[que_M[k][z][2]]=g_M[que_M[k][z][0]][que_M[k][z][1]];
            else ans[que_M[k][z][2]]=-1;
        }
    }
    for(auto i:ans) cout << i << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/