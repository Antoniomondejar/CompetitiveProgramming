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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll n,q;cin>>n>>q;
    map<ll,ll> ids;
    set<pair<ll,ll>> a;
    fore(i,0,n){
        ll w;cin>>w;
        ids[i+1]=w;
        a.insert({w,i+1});
    }
    while(q--){
        char ty; cin>>ty;
        if(ty=='+'){
            ll w,i;cin>>w>>i;
            ids[i]=w;a.insert({w,i});
        } else if(ty=='-'){
            ll i;cin>>i;
            a.erase({ids[i],i});
        } else {
            ll i;cin>>i;
            ll res=0, sum=0; pair<ll,ll> last_add = {0,0};
            bool added = false;
            while(1){
                pair<ll,ll> lo;
                if(last_add.fst==sum){
                    lo={sum,last_add.snd+1};
                } else {
                    lo={sum,0};
                }
                auto el = a.lower_bound(lo);
                if(el==a.end())break;
                if(el->snd == i){
                    added = true;
                    sum+=el->fst;
                    last_add=*el;
                    res++;
                    continue;
                }
                if(!added && sum+el->fst>ids[i]){
                    sum+=ids[i];
                    last_add={ids[i],i};
                    added=true;
                    ++res;
                    continue;
                }
                res++;sum+=el->fst;last_add=*el;
            }
            cout << res << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/