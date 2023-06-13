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
        string s; cin >> s;
        ll r_c = 0; ll l_c = 0;
        fore(i,0,SZ(s)){
            if(s[i]=='(')r_c++;
            else l_c++;
        }
        if(l_c!=r_c){cout << "-1\n";continue;}
        l_c = 0; r_c = 0; bool p_l = true; bool p_r = true; ll po_l = -1; ll po_r = -1;
        string t = s; reverse(ALL(t));
        fore(i,0,SZ(s)){
            if(s[i]=='(')++l_c;
            else --l_c;
            if(l_c < 0 && p_l) p_l = false, po_l = i;
            if(t[i]=='(')++r_c;
            else --r_c;
            if(r_c < 0 && p_r) p_r = false, po_r = i;
        }
        if(p_l || p_r){
            cout << "1\n";
            fore(i,0,n) cout << "1 ";
            cout << "\n";
            continue;
        }
        vector<ll> c(n);
        l_c = 0;
        fore(i,0,SZ(s)){
            if(s[i]=='(')++l_c;
            else --l_c;
            if(l_c<0)l_c = 0, c[i]=2;
            else c[i]=1;
        }
        if(l_c>0){
            ll ig = 0;
            fore(i,0,SZ(s)){
                if(ig == 0 && s[n-1-i]=='('){
                    --l_c; c[n-1-i]=2;
                } else if(ig>0 && s[n-1-i] == '(') --ig;
                else if(s[n-1-i]==')')++ig;
                if(l_c == 0) break;
            }
        }
        cout << "2\n";
        fore(i,0,n){
            cout << c[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/