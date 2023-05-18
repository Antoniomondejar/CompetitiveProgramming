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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,q,ty,l,r,x; cin >> n >> q;
        vector<ll> a(n);
        vector<vector<ll>> s_a(n);
        vector<ll> a_a(n,0);
        set<ll> rem;
        fore(i,0,n){
            cin >> a[i];
            ll sum = 0; ll aux = a[i];
            while(aux!=0){
                sum += aux%10;
                aux /= 10;
            }
            s_a[i].pb(sum);
            while(sum>=10){
                aux = sum;
                sum = 0;
                while(aux!=0){
                    sum += aux%10;
                    aux /= 10;
                }
                s_a[i].pb(sum);
            }
            rem.insert(i);
        }
        fore(i,0,q){
            cin >> ty;
            if(ty==1){
                cin >> l >> r; --l; --r;
                auto it = rem.lower_bound(l);
                vector<ll> to_e;
                while(it != rem.end() && *it<=r){
                    ++a_a[*it];
                    a[*it] = s_a[*it][a_a[*it]-1];
                    if(a_a[*it] == SZ(s_a[*it])) to_e.pb(*it);
                    ++it;
                }
                for(auto i:to_e){
                    rem.erase(i);
                }
            } else {
                cin >> x; --x;
                cout << a[x] << "\n";
            }
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/