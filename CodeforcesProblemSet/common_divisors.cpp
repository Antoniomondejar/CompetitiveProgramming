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

struct Hash {
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(string& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		fore(k,0,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			fore(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
	ll get(int s, int e){
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
};

int main(){FIN;
    string a,b;cin>>a>>b;
    Hash h_a(a), h_b(b);
    ll n_a = SZ(a); ll n_b = SZ(b);
    ll res = 0;
    fore(i,1,n_a){
        if(i>=n_b)break;
        if(h_a.get(0,n_a-i)!=h_a.get(i,n_a) || (n_a%i)!=0)continue;
        res += h_b.get(0,n_b-i)==h_b.get(i,n_b) && h_b.get(0,i)==h_a.get(0,i) && (n_b%i)==0;
    }
    if(n_b>n_a){
        res += h_b.get(0,n_a)==h_a.get(0,n_a) && h_b.get(0,n_b-n_a)==h_b.get(n_a,n_b) && (n_b%n_a)==0; 
    } else {
        res += h_a.get(0,n_b)==h_b.get(0,n_b) && h_a.get(0,n_a-n_b)==h_a.get(n_b,n_a) && (n_a%n_b)==0;
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/