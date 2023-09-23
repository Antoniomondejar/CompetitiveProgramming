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
const ll MOD = 1e9+7;

ll n,m,q;
ll pa[NMAX], su[NMAX], a[NMAX];
pair<ll,pair<ll,ll>> ar[NMAX];
pair<ll,ll> qs[NMAX];
priority_queue<pair<ll,ll>> pqs[NMAX];
ll ans[NMAX];


void dsu_init(){
    fore(i,0,n){
        su[i]=a[i];
        pa[i]=i;
    }
    fore(i,0,q){
        pqs[qs[i].fst].push({-qs[i].snd,i});
    }
}

ll find(ll x){
    if(pa[x]==x)return x;
    return pa[x]=find(pa[x]);
}

void join(ll x, ll y){
    ll px = find(x), py = find(y);
    if(SZ(pqs[py])>SZ(pqs[px]))swap(px,py);
    pa[py]=px;
    su[px]+= su[py];
    while(SZ(pqs[py])){
        auto ce = pqs[py].top();
        pqs[px].push(ce);
        pqs[py].pop();
    }
}

void solve(){
    ll i = 0;
    dsu_init();
    while(i<m){
        ll c=ar[i].fst; ll x=ar[i].snd.fst,y=ar[i].snd.snd;
        // cout << c << " " << x << " " << y << "\n";
        if(find(x)==find(y)){
            ++i;continue;
        }
        ll px = find(x), py=find(y);
        while(SZ(pqs[px])){
            auto ce = pqs[px].top();
            if(-ce.fst+su[px]<c){ans[ce.snd]=-ce.fst+su[px];pqs[px].pop();}
            else break;
        }
        while(SZ(pqs[py])){
            auto ce = pqs[py].top();
            if(-ce.fst+su[py]<c){ans[ce.snd]=-ce.fst+su[py];pqs[py].pop();}
            else break;
        }
        join(x,y);
        ++i;
    }
    fore(i,0,q){
        if(ans[i]>-1)continue;
        ans[i]=su[find(i)]+qs[i].snd;
    }
}


int main(){FIN;
    cin>>n>>m>>q;
    mset(ans,-1);
    fore(i,0,n)cin>>a[i];
    fore(i,0,m){
        ll x,y,m;cin>>x>>y>>m;--x;--y;
        ar[i]={m,{x,y}};
    }
    fore(i,0,q){
        cin>>qs[i].fst>>qs[i].snd;qs[i].fst--;
    }
    sort(ar,ar+m);
    solve();
    fore(i,0,q)cout << ans[i] << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/