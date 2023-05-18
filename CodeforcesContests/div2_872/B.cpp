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
        vector<ll> b(n*m);
        fore(i,0,n*m) cin >> b[i];
        sort(ALL(b));
        ll mi = min(n,m); ll ma = max(n,m);
        ll res_1 = (mi-1)*(b[n*m-1]-b[1]) + (ma-1)*mi*(b[n*m-1]-b[0]);
        ll res_2 = (mi-1)*(b[n*m-2]-b[0]) + (ma-1)*mi*(b[n*m-1]-b[0]); 
        cout << max(res_1,res_2) << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/