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
    ll n; cin >> n;
    vector<ll> a(n);
    fore(i,0,n){
        ll inp;
        cin>>inp;
        if(i==0)a[i] = inp;
        else a[i] = inp+a[i-1];
    }
    ll m; cin >> m;
    fore(i,0,m){
        ll inp; cin >> inp;
        cout << (lower_bound(ALL(a), inp)-a.begin())+1<< "\n";
    }
    return 0;
}