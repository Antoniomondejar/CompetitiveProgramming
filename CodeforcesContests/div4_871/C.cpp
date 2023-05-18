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
       ll n; cin >> n; string s; ll inp;
       map<string,set<ll>> h;
       fore(i,0,n){
            cin >> inp >> s;
            h[s].insert(inp);
       }
       ll min_time = 1e9;
       if(h.count("11")){
        min_time = min(min_time, *h["11"].begin());
       }
       if(h.count("01") && h.count("10")){
        min_time = min(min_time, *h["10"].begin()+*h["01"].begin());
       }
       if(min_time == 1e9) cout << "-1\n";
       else cout << min_time << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/