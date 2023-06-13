#include "bits/stdc++.h"
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
const int NMAX = 15000010;
// const ll MOD = 1e9+7;

int crib[NMAX];
vector<map<int,int>> fs;
map<int,int> all_f, gcd_f;

map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	while(crib[n]>=0)r[crib[n]]++,n/=crib[n];
	if(n>1)r[n]++;
	return r;
}

int gcd(int a, int b){return a?gcd(b%a,a):b;}

int main(){FIN;
    mset(crib,-1);
    fore(i,2,NMAX)if(crib[i]<0)for(ll j=1LL*i*i;j<NMAX;j+=i)crib[j]=i;
    int n; cin >> n;
    vector<int> a(n);
    int mcd = 0;
    fore(i,0,n) cin >> a[i], mcd = gcd(a[i],mcd);
    fore(i,0,n){
        if(a[i]==1)continue;
        fs.pb(fact(a[i]));
        for(auto i:fs.back()){
            all_f[i.fst]++;
        }
    }
    gcd_f = fact(mcd);
    int res = 0;
    if(mcd != 1){
        set<int> nP;
        for(auto i:gcd_f){
            int count = SZ(fs);
            fore(j,0,SZ(fs)){
                ll exp = fs[j][i.fst];
                if(exp-i.snd==0)--count;
            }
            res = max(res,count);
        }
    }
    for(auto i:all_f){
        if(gcd_f.count(i.fst))continue;
        res=max(res,i.snd);
    }
    if(res == 0) cout << "-1\n";
    else cout << n-res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/