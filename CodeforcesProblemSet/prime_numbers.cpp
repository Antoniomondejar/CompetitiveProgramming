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

ll mul(ll x, ll y){
    return (x*y)%MOD;
}

ll elevar(ll b, ll e){
    if (e==0) return 1;
    else if(e&1){
        ll x = elevar(b,(e-1)/2);
        return mul(x,mul(x,b));
    } else {
        ll x = elevar(b,e/2);
        return mul(x,x);
    }
}


int main(){FIN;
    ll n, x; cin >> n >> x;
    vector<ll> a(n); ll sum = 0;bool has = false;
    fore(i,0,n){
        cin>>a[i], sum += a[i];
        if(a[i]>0)has=true;
    }
    if(!has){cout << "1\n"; return 0;}
    map<ll,ll> sms;
    fore(i,0,n){
        sum-=a[i];
        sms[sum]++;
        sum+=a[i];
    }
    ll res = 0;
    while(SZ(sms)){
        // cout << "hola\n";
        auto fi = sms.begin();
        res = fi->fst;
        sms.erase(fi->fst);
        assert(sms.count(fi->fst)==0);
        ll cant = fi->snd; if(cant%x)break;
        cant /= x;
        sms[fi->fst+1]+=cant;
    }
    res = elevar(x,min(sum,res));
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/