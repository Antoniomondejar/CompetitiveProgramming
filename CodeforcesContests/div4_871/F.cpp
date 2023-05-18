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
        ll n, m; cin >> n >> m;
        vector<ll> dg(n,0);
        fore(i,0,m){
            ll x; ll y;
            cin >> x >> y; --x; --y;
            ++dg[x]; ++dg[y];
        }
        map<ll,ll> h_d;
        fore(i,0,n){
            if(h_d.count(dg[i]))
                ++h_d[dg[i]];
            else h_d[dg[i]] = 1;
        }
        vector<pair<ll,ll>> tw;
        for(auto i:h_d){
            if(i.fst != 1) tw.pb(i);
        }
        if(SZ(h_d) == 2){
            cout << tw[0].fst << " " << tw[0].fst-1 << "\n";
        } else {
            if(tw[0].snd == 1)
                cout << tw[0].fst << " " << tw[1].fst-1 << "\n";
            else
                cout << tw[1].fst << " " << tw[0].fst-1 << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/