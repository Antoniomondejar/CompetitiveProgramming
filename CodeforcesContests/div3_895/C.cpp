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
        ll l,r; cin>>l>>r;
        if(r<4) {cout << "-1\n";continue;}
        if(l<r){
            if(r&1){
                --r;
                cout << r/2 << " " << r/2 << "\n";
                continue;
            } else {
                cout << r/2 << " " << r/2 << "\n";
                continue;
            }
        }
        bool p = false;
        for(ll i = 2;i*i<=r;++i){
            if(r%i==0){
                ll aux = r/i;
                cout << i*(aux-1) << " " << i << "\n";
                p=true;
                break;
            }
        }
        if(!p)cout << "-1\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/