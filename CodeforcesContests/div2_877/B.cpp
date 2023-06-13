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
        ll n; cin >> n;
        vector<ll> p(n);
        ll p_1 = 0; ll p_2 = 0; ll p_n = 0;
        fore(i,0,n){
            cin>>p[i];
            if(p[i]==1)p_1 = i;
            if(p[i]==2)p_2 = i;
            if(p[i]==n)p_n = i;
        }
        if(p_n > p_1 && p_n < p_2) {cout << "1 1\n";continue;}
        if(p_n > p_2 && p_n < p_1) {cout << "1 1\n";continue;}
        ll M = max({p_1,p_2,p_n});vector<ll> trs; trs.pb(p_1);trs.pb(p_2);trs.pb(p_n);
        sort(ALL(trs));
        ll MI = min({p_1,p_2,p_n});
        if(M == p_n)
            cout << M+1 << " " << trs[1]+1 << "\n";
        else
            cout << MI+1 << " " << trs[1]+1 << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/