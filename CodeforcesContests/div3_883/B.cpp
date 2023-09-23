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

vector<string> a;
int main(){
    ll t; cin>>t;
    while(t--){
        a.clear();
        fore(i,0,3){
            string hola;cin>>hola;
            a.pb(hola);
        }
        bool p = false;
        fore(i,0,3){
            set<char> let;
            fore(j,0,3){
                let.insert(a[i][j]);
            }
            if(SZ(let)==1 && a[i][0]!='.'){
                p=true;
                cout << a[i][0] << "\n";
                break;
            }
        }
        if(p)continue;
        fore(j,0,3){
            set<char> let;
            fore(i,0,3){
                let.insert(a[i][j]);
            }
            if(SZ(let)==1 && a[0][j]!='.'){
                p=true;
                cout << a[0][j] << "\n";
                break;
            }
        }
        if(p)continue;
        set<char> let; let.insert(a[0][0]);
        let.insert(a[1][1]); let.insert(a[2][2]);
        if(SZ(let)==1&& a[0][0]!='.'){
            p=true;
            cout << a[0][0] << "\n";
            continue;
        }
        if(p)continue;
        let.clear();let.insert(a[0][2]);
        let.insert(a[1][1]); let.insert(a[2][0]);
        if(SZ(let)==1&& a[0][2]!='.'){
            cout << a[0][2] << "\n";
            continue;
        }
        cout << "DRAW\n";
        
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/