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
    ll n;cin>>n;
    vector<ll> div;
    fore(i,1,10){
        if(n<i)break;
        if(n%i==0)div.pb(i);
    }
    fore(i,0,n+1){
        bool p = false;
        for(auto j:div){
            if(i%(n/j)==0){
                cout << j;
                p=true;
                break;
            }
        }
        if(!p)cout << '-';
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/