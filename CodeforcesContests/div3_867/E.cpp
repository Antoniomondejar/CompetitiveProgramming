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
        ll n; cin >> n;
        string s; cin >> s;
        if(s.length()&1) {cout << "-1\n"; continue;}
        map<char,ll> p1, p2; set<char> b;
        fore(i,0,n/2){
            if(p1.count(s[i])) ++p1[s[i]];
            else p1[s[i]] = 1;
            if(p2.count(s[n-1-i])) ++p2[s[n-i-1]];
            else p2[s[n-1-i]] = 1;
            if(p1.count(s[n-i-1])) b.insert(s[n-i-1]);
            if(p2.count(s[i])) b.insert(s[i]);
        }
        ll aux = n/2; bool con = false;
        for(auto i:b){
            ll m = min(p1[i], p2[i]); ll ma = max(p1[i], p2[i]);
            if(aux-m<m){cout << "-1\n"; con = true;continue;}
            aux-=m;
        }
        if(con) continue;
        ll c = 0;
        fore(i,0,n/2) c+=(s[i]==s[n-i-1]);
        cout << (!(c&1)?c/2:c/2+1) << "\n";
    }
    return 0;
}