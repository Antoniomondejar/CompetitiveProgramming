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
        ll n; cin >> n;string s; cin >> s;
        ll add=0;
        fore(i,0,s.length()-1){
            if(s[i]=='0' && s[i+1]=='0') add+=2;
            else if(i>0 && s[i] == '1' && s[i-1] == '0' && s[i+1] == '0') ++add;
        }
        cout << add << "\n";
    }
    return 0;
}