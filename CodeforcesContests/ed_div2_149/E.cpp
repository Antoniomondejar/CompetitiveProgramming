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
const ll KMAX = 20;
ll p2[KMAX];

int main(){FIN;
    p2[0] = 1;
    fore(i,1,KMAX) p2[i] = p2[i-1]*2;
    ll k; cin >> k;
    vector<ll> a(p2[k]);
    fore(i,0,p2[k]) cin >> a[i];
     
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/