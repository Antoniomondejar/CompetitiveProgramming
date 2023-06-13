#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;


ll mul(ll x, ll y){
    return (x*y)%MOD;
}

vector<int> z_function(string& s){
    int l=0, r=0,n=s.size();
    vector<int> z(s.size(),0);
    fore(i,1,n){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}

int main(void){FIN;
    ll n,m; cin >> n >> m;
    string p; cin >> p;
    vector<ll> ps(m);
    fore(i,0,m) cin >> ps[i];
    vector<int> z_a = z_function(p);
    ll cant = 26; ll res = max(1LL,mul(cant,ps[0]-1));
    fore(i,1,m){
        if(ps[i-1]+SZ(p)>ps[i]){
            ll ind = ps[i]-ps[i-1];
            if(z_a[ind]+ind<SZ(p)) res = 0;
        } else {
            ll many = ps[i]-SZ(p)-ps[i-1];
            ll aux = 1;
            fore(i,0,many){
                aux = mul(aux,cant);
            }
            res = mul(res,aux);
        }
    }
    fore(i,ps[SZ(ps)-1]-1+SZ(p),n){
        res = mul(res,cant);
    }
    cout << res << "\n";
    return 0;
}