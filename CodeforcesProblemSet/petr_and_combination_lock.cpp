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
const ll MOD = 360;
ll n;
vector<ll> a;

bool f(ll x){
    ll pointer = 0;
    fore(i,0,n){
        if(x&1)
            pointer = (pointer+a[i])%MOD;
        else
            pointer = ((pointer-a[i])%MOD+MOD)%MOD;
        x/=2;
    }
    return pointer==0;
}

int main(){FIN;
    cin >> n; a.resize(n);
    fore(i,0,n)cin>>a[i];
    fore(i,0,1<<n){
        if(f(i)){cout << "YES\n";return 0;}
    }
    cout << "NO\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/