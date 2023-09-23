#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef vii vector<ll>
//typedef ii pair<ll,ll>

ll sum[11];
ll res[11];
bool puede[11];


ll elevar(ll b, ll e){
	if(e==0)return 1;
	if(e&1){
		ll x = elevar(b,(e-1)/2);
		return x*x*b;
	} else {
		ll x = elevar(b,e/2);
		return x*x;
	}
}


ll cant_le;
ll respuesta;

void f(ll x, vector<ll> cuales, ll sum_act){
	if(x==cant_le){
		respuesta+=sum_act==0;
		return;
	}
	vector<ll> n_posi(10);
	fore(i,0,SZ(cuales)){
		n_posi[cuales[i]]=1;
	}
	ll sum_aux = sum_act;
	fore(i,0,10){
		if(n_posi[i])continue;
		if(i==0 && !puede[x])continue;
		cuales.pb(i);
		sum_act+=sum[x]*i;
		sum_act-=res[x]*i;
		f(x+1,cuales,sum_act);
		sum_act = sum_aux;
		cuales.pop_back();
	}
	return;
}

//AAAAAAAAAA

int main(){FIN;
	ll n;cin>>n;
	vector<string> words(n);
	set<char> let;
	fore(i,0,n){
		string s;cin>>s;
		reverse(ALL(s));
		words[i]=s;
		fore(j,0,SZ(s)){
			let.insert(s[j]);
		}
	}
	fore(i,0,11)puede[i]=1;
	ll it=0;
	cant_le = SZ(let);
	for(auto i:let){
		fore(j,0,n){
			if(j==n-1){
				fore(h,0,SZ(words[j])){
					if(words[j][h]==i){
						res[it]+=elevar(10,h);
						if(h==SZ(words[j])-1)puede[it]=0;
					}

				}
			} else {
				fore(h,0,SZ(words[j])){
					if(words[j][h]==i){
						sum[it]+=elevar(10,h);
						if(h==SZ(words[j])-1)puede[it]=0;
					}

				}
			}
		}
		++it;
	}
	respuesta = 0;
	f(0,{},0);
	cout << respuesta << "\n";
	return 0;
}