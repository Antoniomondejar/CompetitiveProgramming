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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        string a,b; cin >> a >> b;
        if(a.back()==b.back()){
            cout << "YES\n";
            cout << "*" << a.back() << "\n";
            continue;
        }
        if(a[0]==b[0]){
            cout << "YES\n";
            cout << a[0]<< "*\n";
            continue;
        }
        bool p = false; int ind = -1;
        fore(i,0,SZ(a)-1){
            fore(j,0,SZ(b)-1){
                if(a[i]==b[j] && a[i+1]==b[j+1]){
                    p=true;
                    ind=i; break;
                }
            }
            if(p)break;
        }
        if(p){
            cout << "YES\n";
            cout << "*" << a[ind] << a[ind+1] << "*\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/