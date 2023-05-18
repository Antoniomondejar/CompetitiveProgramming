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
const ll MAXN = 1e6 + 10;
int spf[MAXN];
int main(){FIN;
    fore(i,2,MAXN) if(!spf[i]) for(int j=i;j<MAXN;j+=i) if(!spf[j]) spf[j]=i;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        if(n == 1 || m == 1){cout << "YES\n"; continue;}
        if(n<m){cout << "NO\n"; continue;}
        if(n%m == 0){cout << "NO\n"; continue;}
        if(spf[n]<m){cout << "NO\n"; continue;}
        cout << "YES\n";
    }
    return 0;
}