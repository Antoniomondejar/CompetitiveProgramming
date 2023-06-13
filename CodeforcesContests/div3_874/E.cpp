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
        ll n; cin >> n;
        vector<ll> a(n+1);
        set<ll> cad;
        vector<ll> vis(n+1);
        fore(i,1,n+1)cin>>a[i]; ll m = 0; ll M = 0; ll c_aux = 0;
        fore(i,1,n+1){
            if(vis[i])continue;
            vis[i]=1; cad.insert(i);
            ll cv = a[i]; bool a_r = false;
            while(1){
                if(vis[cv] && !a_r)--M, a_r=true;
                vis[cv]=1;
                if(cad.count(a[cv])){
                    ++M;
                    if(!a_r)
                        c_aux += a[a[cv]]==cv;
                    break;
                }
                cad.insert(cv);
                cv = a[cv];
            }
            cad.clear();
        }
        m = min(M-c_aux+1, M);
        cout << m << " " << M << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/