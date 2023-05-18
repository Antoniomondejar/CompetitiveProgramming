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
    ll N; cin >> N;
    string s; cin >> s;
    ll a=0; ll t=0; char las='a';
    fore(i,0,N){
        if(s[i]=='T') ++t;
        else ++a;
        if(t>a){
            las = 't';
        } else if (a>t){
            las = 'a';
        }
    }
    if(a>t) cout << "A\n";
    else if(t>a) cout << "T\n";
    else if(a==t && las=='a') cout << "A\n";
    else cout << "T\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/