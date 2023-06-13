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
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        fore(i,0,n){
            cin >> a[i];
        }
        fore(i,0,n)cin>>b[i];
        map<ll,ll> nms_a, nms_b; ll l_b = b[0], l_a=a[0]; ll b_c = 1, a_c = 1;
        fore(i,1,n){
            if(l_b == b[i])b_c++;
            else {
                nms_b[l_b] = max(nms_b[l_b], b_c);
                b_c = 1;
                l_b = b[i];
            }
            if(l_a==a[i])a_c++;
            else {
                nms_a[l_a] = max(nms_a[l_a], a_c);
                a_c = 1;
                l_a = a[i];
            }
        }
        nms_a[l_a] = max(nms_a[l_a], a_c);
        nms_b[l_b] = max(nms_b[l_b], b_c);
        ll ms = -1;
        for(auto i:nms_a){
            if(nms_b.count(i.fst)){
                ms = max(ms,i.snd + nms_b[i.fst]);
            } else {
                ms = max(ms, i.snd);
            }
        }
        for(auto i:nms_b){
            if(nms_a.count(i.fst)){
                ms = max(ms,i.snd + nms_a[i.fst]);
            } else {
                ms = max(ms, i.snd);
            }
        }
        cout << ms << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/