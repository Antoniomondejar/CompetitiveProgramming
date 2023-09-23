#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,a,q;cin>>n>>a>>q;
        string s;cin>>s;
        ll cuan = a; ll cuan_s = a;
        bool p = false;
        fore(i,0,q){
            if(cuan>=n){p=true;break;}
            if(s[i]=='+')cuan++, ++cuan_s;
            else cuan--;
        }
        if(p||cuan>=n){cout << "YES\n";continue;}
        if(cuan_s<n){cout << "NO\n";continue;}
        cout << "MAYBE\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/