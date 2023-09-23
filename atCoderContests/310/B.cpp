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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

struct prod{
    ll p;
    ll c;
    vector<ll> f;
};

int main(){FIN;
    ll n,m;cin>>n>>m;
    vector<prod> ps(n);
    fore(i,0,n){
        ll p,c;cin>>p>>c;
        vector<ll>aux(c);
        fore(j,0,c)cin>>aux[j],aux[j]--;
        ps[i]={p,c,aux};
    }
    bool h_res = false;
    fore(i,0,n){
        fore(j,0,n){
            if(i==j)continue;
            if(ps[i].p>ps[j].p)continue;
            vector<ll> ms(m);
            fore(z,0,ps[j].c){
                ms[ps[j].f[z]]++;
            }
            fore(z,0,ps[i].c){
                ms[ps[i].f[z]]--;
            }
            bool p = true;
            fore(z,0,m){
                if(ms[z]>0){p=false;break;}
            }
            if(!p)break;
            if(ps[i].p<ps[j].p){h_res=true;break;}
            p=false;
            fore(z,0,m){
                if(ms[z]<0){p=true;break;}
            }
            if(p)h_res=true;
        }
        if(h_res)break;
    }
    if(h_res)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/