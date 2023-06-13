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

ll crib[NMAX];

map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	while(crib[n]>=0)r[crib[n]]++,n/=crib[n];
	if(n>1)r[n]++;
	return r;
}

int main(){FIN;
    ll t; cin >> t;
    mset(crib,-1);
    fore(i,2,NMAX)if(crib[i]<0)for(ll j=1LL*i*i;j<NMAX;j+=i)crib[j]=i;
    ll ct = 0; fore(i,2,NMAX) if(crib[i]<0)++ct;
    while(t--){
        ll n,m; cin >> n >> m;
        if(crib[m]<0){
            ll a[n+1][m+1];
            fore(i,1,m+1) cout << i << " ", a[1][i]=i;
            cout << "\n";
            fore(i,2,n+1){
                fore(j,1,m+1){
                    if(a[i-1][j]+m+1 > m*i){
                        cout << a[i-1][j]+1 << " ";
                        a[i][j] = a[i-1][j]+1;
                    } else {
                        cout << a[i-1][j]+m+1 << " ";
                        a[i][j] = a[i-1][j]+m+1;
                    }
                }
                cout << "\n";
            }
        } else {
            fore(i,0,n){
                fore(j,0,m){
                    cout << (j+1)+m*i << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/