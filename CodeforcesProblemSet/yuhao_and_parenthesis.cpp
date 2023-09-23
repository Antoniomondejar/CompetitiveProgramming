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
const ll NMAX = 5e5+10;
const ll MOD = 1e9+7;

ll in[NMAX];
ll fi[NMAX];

int main(){FIN;
    ll n; cin >> n;
    vector<string> strs(n);
    fore(i,0,n)cin>>strs[i];
    fore(i,0,n){
        ll ba = 0; bool p_p = true;  
        fore(j,0,SZ(strs[i])){
            if(strs[i][j]=='(')++ba;
            else --ba;
            if(ba<0)p_p=false;
        }
        if(p_p){
            in[ba]++;
            continue;
        }
        string copy = strs[i];
        reverse(ALL(copy));
        ba = 0; p_p = true;
        fore(j,0,SZ(strs[i])){
            if(copy[j]=='(')++ba;
            else --ba;
            if(ba>0)p_p=false;
        }
        if(p_p && ba<0)
            fi[-ba]++;
    }
    ll res=in[0]/2;
    fore(i,1,NMAX){
        res += min(in[i],fi[i]);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/