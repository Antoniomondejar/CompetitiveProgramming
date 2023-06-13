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
const ll NMAX = 1e6+10;
const ll MOD = 1e9+7;
ll spf[NMAX];

void div_rec(vector<ll>& r, vector<pair<ll,ll> >& f, int k, ll c){
	if(k==f.size()){r.pb(c);return;}
	fore(i,0,f[k].snd+1)div_rec(r,f,k+1,c),c*=f[k].fst;
}
vector<ll> divisors(vector<pair<ll,ll> > f){
	vector<ll> r; // returns divisors given factorization
	div_rec(r,f,0,1);
	return r;
}

int main(){
    fore(i,2,NMAX){
        if(!spf[i]){
            spf[i] = i;
            for(ll j = 2*i;j<NMAX;j+=i){
                spf[j]=i;
            }
        }
    }
    ll n; cin >> n;
    while(n--){
        ll aux; cin>>aux;
        map<ll,ll> fs;
        while(aux!=1){
            fs[spf[aux]]++;
            aux/=spf[aux];
        }
        vector<pair<ll,ll>> f;
        for(auto i:fs){
            f.pb(i);
        }
        vector<ll> di = divisors(f);
        cout << SZ(di) << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/