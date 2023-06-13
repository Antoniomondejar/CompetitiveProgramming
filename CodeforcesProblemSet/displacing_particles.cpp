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
ll p2[25];
int main(){FIN;
    p2[0]=1;
    fore(i,1,21)p2[i]=p2[i-1]*2;
    ll N, x, y; cin>>N>>x>>y; 
    ll c1 = 0, c2 = 0;
    ll xi = p2[N-1]; ll yi = p2[N-1];
    // fore(i,1,21) cout << p2[i] << "\n";
    // cout << xi << " " << yi << "\n";
    bool f_ma=0; bool f_me = 0; ll i = 0;ll xi_aux = p2[N-1];
    while(xi!=x){
        if(xi>x && !f_me){
            xi /= 2;
            f_ma = 1;
        } else if(f_ma){
            i+=1;
            xi = xi_aux + p2[N-1-i];
            xi_aux = xi;
            c1 = i-1;
        } else if(x>xi){
            xi = (p2[N]+xi)/2;
            f_me = 1;
        } else {
            i+=1;
            xi = p2[N-1-i];
            c1 = i-1;
        }
        ++c1;
    }
    f_ma = 0; f_me = 0; i = 0;ll yi_aux = p2[N-1];
    while(yi!=y){
        if(yi>y && !f_me){
            yi /= 2;
            f_ma = 1;
        } else if(f_ma){
            i+=1;
            yi = yi_aux + p2[N-1-i];
            yi_aux = yi;
            c2 = i-1;
        } else if(y>yi){
            yi = (p2[N]+yi)/2;
            f_me = 1;
        } else {
            i+=1;
            yi = p2[N-1-i];
            c2 = i-1;
        }
        ++c2;
    }
    cout << max(c1,c2) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/