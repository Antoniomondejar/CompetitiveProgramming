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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vector<ll> b(n); vector<pair<ll,ll>> a(n);
        fore(i,0,n)cin>>a[i].fst, a[i].snd = i;
        fore(i,0,n)cin>>b[i];
        sort(ALL(a)); sort(ALL(b));
        vector<ll> ans(n);
        fore(i,0,n){
            ans[a[i].snd] = b[i];
        }
        for(auto i:ans){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/