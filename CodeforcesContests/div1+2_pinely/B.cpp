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
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> p(n);
        vector<ll> p_inv(n);
        bool po = true;
        fore(i,0,n){
            cin>>p[i];
            po=po&&p[i]==i+1;
            p_inv[p[i]-1]=i;
        }
        if(po){cout << "0\n";continue;}
        ll res = 1; ll last = -1;
        fore(i,0,n){
            if(last>p_inv[i])res++;
            last = p_inv[i];
        }
        cout << res-1 << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/