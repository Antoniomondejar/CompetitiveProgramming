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
        set<str> mds;
        string s; cin >> s;
        string fist = "";fist+=s[0]; fist+=s[1]; mds.insert(fist);
        ll res = 1;
        fore(i,2,n){
            string aux = ""; aux += s[i-1]; aux += s[i];
            if(mds.count(aux))continue;
            mds.insert(aux);
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/