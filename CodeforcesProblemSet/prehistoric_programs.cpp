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

int main(){FIN;
    ll n; cin >> n;
    vector<string> ws(n);
    ll l_c = 0; ll r_c=0;
    fore(i,0,n){
        cin>>ws[i];
        for(auto j:ws[i]){
            if(j=='(')++l_c;
            else ++r_c;
        }
    }
    if(r_c != l_c){cout << "impossible\n";return 0;}
    vector<pair<ll,ll>> ord;
    ll fst; ll l_c_f = -1; bool po = false;
    fore(i,0,n){
        l_c = 0; bool p = true;
        for(auto j:ws[i]){
            if(j=='(')++l_c;
            else --l_c;
            if(l_c<0)p=false;
        }
        if(p){
            if(l_c>l_c_f){
                fst = i;
                l_c_f = l_c;
            }
            po=true;
        }
        ord.pb({l_c,i});
    }
    if(!po){cout << "impossible\n";return 0;}
    cout << fst+1 << "\n";
    sort(ALL(ord));
    reverse(ALL(ord));
    for(auto i : ord){
        if(i.snd == fst)continue;
        cout << i.snd+1 << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/