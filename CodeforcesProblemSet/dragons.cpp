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
    ll s, n, inp1, inp2; cin >> s >> n;
    vector<pair<ll,ll>> a(n);
    fore(i,0,n){
        cin >> inp1 >> inp2;
        a[i] = {inp1,inp2};
    }
    sort(ALL(a));
    fore(i,0,n){
        if(s<=a[i].fst) {cout << "NO\n"; return 0;}
        s+=a[i].snd;
    }
    cout << "YES\n";
    return 0;
}