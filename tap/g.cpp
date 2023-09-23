#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 1e5+10;
const ll INF=1e18;
const ll NEUTmini = INF;
const ll NEUTmaxi = -1;


struct STreeMax{
    vector<ll> t; int n;
    STreeMax(int n):n(n),t(2*n+5,NEUTmaxi){}
    void upd(int p, ll v){
        p+=n;
        for(t[p]=v;p>1;p>>=1) t[p>>1]=max(t[p],t[p^1]);
    }
    ll query(int l, int r){ // [l, r)
        ll res=NEUTmaxi;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) res=max(res,t[l++]);
            if(r&1) res=max(res,t[--r]);
        }
        return res;
    }
};

struct STreeMin{
    vector<ll> t; int n;
    STreeMin(int n):n(n),t(2*n+5,NEUTmini){}
    void upd(int p, ll v){
        p+=n;
        for(t[p]=v;p>1;p>>=1) t[p>>1]=min(t[p],t[p^1]);
    }
    ll query(int l, int r){ // [l, r)
        ll res=NEUTmini;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) res=min(res,t[l++]);
            if(r&1) res=min(res,t[--r]);
        }
        return res;
    }
};

vector<pair<ll,pair<ll,ll > > > es;

int uf[NMAX];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
    x=uf_find(x);y=uf_find(y);
    if(x==y)return false;
    if(uf[x]>uf[y])swap(x,y);
    uf[x]+=uf[y];uf[y]=x;
    return true;
}


ll kruskal(){  // assumes graph is connected
    sort(es.begin(),es.end());uf_init();
    ll r=0;
    fore(i,0,es.size()){
        int x=es[i].snd.fst,y=es[i].snd.snd;
        if(uf_join(x,y))r+=es[i].fst; // (x,y,c) belongs to mst
    }
    return r; // total cost
}

int main(){FIN;
    ll n;cin>>n;
    vector<vector<ll>> plat(n);
    vector<ll> heights;
    heights.pb(0);
    fore(i,0,n){
        ll h,l,r;cin>>h>>l>>r;
        plat[i]={h,l,r};
        heights.pb(h);
    }
    sort(ALL(heights));
    unique(ALL(heights));
    vector<vector<ll>> events;
    // (l,ty,h,ind) if ty==0
    // (r,ty,h,ind) if ty==1
    events.pb({-INF,0,0,0});
    events.pb({INF,1,0,0});
    ll max_h = heights.back();
    fore(i,0,n){
        ll h = plat[i][0], l = plat[i][1], r = plat[i][2]; 
        events.pb({l-max_h+h,0,h,i+1});
        events.pb({r-max_h+h,1,h,i+1});
    }
    sort(ALL(events));
    map<ll,ll> act;
    STreeMax maxi(SZ(heights));
    STreeMin mini(SZ(heights));
    fore(i,0,SZ(events)){
        ll ty = events[i][1],  h = events[i][2];
        ll ind = events[i][3];
        ll posi = lower_bound(ALL(heights),h)-heights.begin();
        if(ty){
            maxi.upd(posi,NEUTmaxi);mini.upd(posi,NEUTmini);
            if(mini.query(posi+1,SZ(heights))<INF){
                ll h_nu = mini.query(posi+1,SZ(heights));
                es.pb({h_nu-h,{ind,act[h_nu]}});
            }
            if(maxi.query(0,posi)>=0){
                ll h_nu = maxi.query(0,posi);
                es.pb({h-h_nu,{ind,act[h_nu]}});
            }
        } else {
            act[h]=ind;
            maxi.upd(posi,h); mini.upd(posi,h);
            if(mini.query(posi+1,SZ(heights))<INF){
                ll h_nu = mini.query(posi+1,SZ(heights));
                es.pb({h_nu-h,{ind,act[h_nu]}});
            }
            if(maxi.query(0,posi)>=0){
                ll h_nu = maxi.query(0,posi);
                es.pb({h-h_nu,{ind,act[h_nu]}});
            }
        }
    }

    events.clear();act.clear();
    events.pb({-INF,0,0,0});
    events.pb({INF,1,0,0});
    fore(i,0,n){
        ll h = plat[i][0], l = plat[i][1], r = plat[i][2]; 
        events.pb({l+max_h-h,0,h,i+1});
        events.pb({r+max_h-h,1,h,i+1});
    }
    sort(ALL(events));

    fore(i,0,SZ(events)){
        ll ty = events[i][1],  h = events[i][2];
        ll ind = events[i][3];
        ll posi = lower_bound(ALL(heights),h)-heights.begin();
        // cout << ind << " " << ty << "\n";
        if(ty){
            maxi.upd(posi,NEUTmaxi);mini.upd(posi,NEUTmini);
            if(mini.query(posi+1,SZ(heights))<INF){
                ll h_nu = mini.query(posi+1,SZ(heights));
                es.pb({h_nu-h,{ind,act[h_nu]}});
            }
            if(maxi.query(0,posi)>=0){
                ll h_nu = maxi.query(0,posi);
                es.pb({h-h_nu,{ind,act[h_nu]}});
            }
        } else {
            act[h]=ind;
            maxi.upd(posi,h); mini.upd(posi,h);
            if(mini.query(posi+1,SZ(heights))<INF){
                ll h_nu = mini.query(posi+1,SZ(heights));
                es.pb({h_nu-h,{ind,act[h_nu]}});
            }
            if(maxi.query(0,posi)>=0){
                ll h_nu = maxi.query(0,posi);
                es.pb({h-h_nu,{ind,act[h_nu]}});
            }
        }
    }

    // cout << "\n";

    //for(auto i:es){
    //    cout << i.fst << " " << i.snd.fst << " " << i.snd.snd << "\n";
    //}

    ll cost = kruskal();

    cout << cost << "\n";

    return 0;
}