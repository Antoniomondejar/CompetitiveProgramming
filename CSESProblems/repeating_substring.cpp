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

ll sz;

#define bint __int128
struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,s.size()+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};

bool can(ll m, Hash &ha){
    set<bint> hs; bool p = false;
    fore(i,0,sz+1){
        if(i+m>sz)break;
        bint subs = ha.get(i,i+m);
        if(hs.count(subs)){p=true;break;}
        hs.insert(subs);
    }
    return p;
}

ll get_p(ll l, Hash &ha){
    set<bint> hs; bool p = false;
    fore(i,0,sz+1){
        if(i+l>sz)break;
        bint subs = ha.get(i,i+l);
        if(hs.count(subs)){return i;}
        hs.insert(subs);
    }
    return p;
}

int main(){FIN;
    string s; cin >> s; sz = SZ(s);
    ll l = 1; ll r = SZ(s);
    Hash ha(s);
    if(!can(1,ha)){cout << "-1\n";return 0;}
    while(l<=r){
        ll m = (l+r)/2;
        if(can(m,ha)){
            l = m+1;
        } else {
            r = m-1;
        }
    }
    ll i = get_p(r,ha);
    string res = "";
    fore(j,i,i+r){
        res += s[j];
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/