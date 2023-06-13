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
const ll NMAX = 1e6+10;
const ll MOD = 1e9+7;

ll c_di[NMAX];

int main(){FIN;
    ll n; cin >> n;
    while(n--){
        ll aux; cin>>aux;
        if(c_di[aux]) {cout << c_di[aux] << "\n"; continue;}
        ll c_d = 0;
        for(int i = 1; i*i<=aux;++i){
            if(aux%i==0){
                ++c_d;
                if(i*i!=aux)++c_d;
            }
        }
        c_di[aux]=c_d;
        cout << c_d << "\n";
    }
    return 0;
}
 
/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/