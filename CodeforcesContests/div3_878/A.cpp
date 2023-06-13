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
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        char f = s[0]; ll i = 0;
        string res = "";
        while(i<SZ(s)){
            res += s[i];
            ll j = i+1;
            while(j<SZ(s) && s[j]!=f){
                ++j;
            }
            if(j==SZ(s)){
                ++i;
                f = s[i];
            } else {
                i = j+1;
                if(i<n)f=s[i];
            }
        }
        cout << res << "\n";
    }

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/