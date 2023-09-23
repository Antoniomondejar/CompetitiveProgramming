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


int main(){
    ll t; cin >> t;
    while(t--){
        ll n,m,h;cin>>n>>m>>h;
        vector<pair<ll,pair<ll,ll>>> posi;
        vector<ll> tim;
        fore(i,0,n){
            tim.clear();
            ll sum = 0;
            fore(j,0,m){
                ll inp; cin>>inp;
                tim.pb(inp);
            }
            sort(ALL(tim));
            ll sum_aux=0;
            fore(j,0,m){
                if(sum_aux+tim[j]>h){
                    posi.pb({-j,{sum,i}});
                    break;
                }
                sum+=sum_aux+tim[j];
                sum_aux+=tim[j];
                if(j==m-1){
                    posi.pb({-j-1,{sum,i}});
                }
            }
        }
        sort(ALL(posi));
        // fore(i,0,n){
        //     cout << posi[i].fst << " " << posi[i].snd.fst << " " << posi[i].snd.snd << "\n";
        // }
        fore(i,0,n){
            if(posi[i].snd.snd==0){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/