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
string s,t;
const ll NMAX = 3e3+10;
ll dp[NMAX][NMAX];

vector<ll> res;

ll f(ll i, ll j){
    if(i == s.length() || j == t.length()) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])dp[i][j] = max({f(i+1,j),f(i,j+1),1+f(i+1,j+1)});
    else dp[i][j] = max(f(i+1,j),f(i,j+1));
    return dp[i][j];
}

void build(ll i, ll j){
    if(i == s.length() || j == t.length())return;
    ll res_l = f(i,j);
    if(res_l == f(i+1,j)){
        build(i+1,j);
    } else if(res_l == f(i,j+1)){
        build(i,j+1);
    } else {
        res.pb(i);
        build(i+1,j+1);
    }
}

int main(){
    cin>>s>>t;fore(i,0,NMAX)fore(j,0,NMAX)dp[i][j]=-1;
    build(0,0);
    for(auto i:res)
        cout << s[i];
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/