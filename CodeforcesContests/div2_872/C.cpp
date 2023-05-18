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
vector<ll> x_i;

bool can(ll med, ll l_m, ll r_m, ll m){
    if(l_m>=med || r_m >=med) return true;
    if(SZ(x_i)>=med) return true;
    fore(i,0,SZ(x_i)){
        ll aux_l = l_m, aux_r = r_m; ll res_1 = 0; ll res_2 = 0;
        if(x_i[i]-1-i > l_m){
            aux_r = r_m-min(x_i[i]-1-i,r_m);
            res_1 = max(r_m-aux_r,l_m)+min(m-x_i[i]-(SZ(x_i)-i-1), aux_r)+SZ(x_i);
            res_1 = max(res_1, min(x_i[i]-1-i,l_m)+min(m-x_i[i]-(SZ(x_i)-i-1), r_m)+SZ(x_i));
        } else {
           res_1 = min(x_i[i]-1-i,l_m)+min(m-x_i[i]-(SZ(x_i)-i-1), r_m)+SZ(x_i);
        }
        if(m-x_i[i]-(SZ(x_i)-i-1) > r_m){
            aux_l = l_m-min(m-x_i[i]-(SZ(x_i)-i-1),l_m);
            res_2 = min(x_i[i]-1-i,aux_l)+max(l_m-aux_l,r_m)+SZ(x_i);
            res_2 = max(res_2, min(x_i[i]-1-i,l_m)+min(m-x_i[i]-(SZ(x_i)-i-1), r_m)+SZ(x_i));
        } else {
           res_2 = min(x_i[i]-1-i,l_m)+min(m-x_i[i]-(SZ(x_i)-i-1), r_m)+SZ(x_i); 
        }
        if(res_1>=med || res_2>=med) return true;
    }
    return false;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m ; cin >> n >> m;
        ll r_m = 0, l_m = 0;
        set<ll> alr;
        fore(i,0,n){
            ll inp; cin >> inp;
            if(inp==-1)++l_m;
            else if(inp==-2)++r_m;
            else if(!alr.count(inp)){
                x_i.pb(inp);
                alr.insert(inp);
            }
        }
        sort(ALL(x_i));
        ll l = 0, r = m; ll med;
        while(l<=r){
            med = (l+r)/2;
            if(can(med, l_m, r_m, m)){
                l = med+1;
            } else {
                r = med-1;
            }
        }
        cout << r << "\n";
        x_i.clear(); alr.clear();
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/