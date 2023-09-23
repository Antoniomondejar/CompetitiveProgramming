#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 5e4+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll n,q;cin>>n>>q;
    vector<ll> k(n);
    fore(i,0,n)cin>>k[i];
    vector<ll> ans(q);
    vector<vector<pair<bool,vector<ll>>>> qs(n);
    ll ra=sqrt(NMAX)+2;
    vector<vector<ll>> mods(ra);
    fore(i,1,ra){
        mods[i].resize(i);
        fore(j,0,i) mods[i][j]=0;
    }
    vector<ll> occ(NMAX);
    fore(i,0,q){
        ll l,r,x,m;cin>>l>>r>>x>>m;--l;--r;
        if(l>0)qs[l-1].pb({false,{x,m,i}});
        qs[r].pb({true,{x,m,i}});
    }
    fore(i,0,n){
        occ[k[i]]++;
        fore(j,1,ra){
            mods[j][k[i]%j]++;
        }
        fore(j,0,SZ(qs[i])){
            bool ty = qs[i][j].fst;
            ll mod = qs[i][j].snd[1], re = qs[i][j].snd[0];
            ll ind = qs[i][j].snd[2];
            if(mod<ra){
                if(ty){
                    ans[ind]+=mods[mod][re];
                } else {
                    ans[ind]-=mods[mod][re];
                }
            } else {
                for(int z = re; z<NMAX; z+=mod){
                    if(ty){
                        ans[ind]+=occ[z];
                    } else {
                        ans[ind]-=occ[z];
                    }
                }
            }
        }
    }
    for(auto i:ans){
        cout << i << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/