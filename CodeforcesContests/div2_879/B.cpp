#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
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
        string l,r; cin>>l>>r;
        ll res = 0;
        if(SZ(l)<SZ(r)){
            res = 9*SZ(l);
            res += 9*(SZ(r)-SZ(l)-1)+r[0]-'0';
            cout << res << "\n"; continue;
        }
        ll i=0;
        while(i < SZ(r) && l[i] == r[i])++i;
        if(i < SZ(r)){
            res = (r[i]-'0')-(l[i]-'0')+9*(SZ(l)-1-i);
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/