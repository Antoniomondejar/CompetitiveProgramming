#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 1e5+10;
const ll INF = 1e16;
ll n; vector<ll> h_a;
map<char,ll> aux;
ll dp[NMAX][5];
str hard = "";

ll f(ll x, ll l_c){
    if(l_c == 4)return INF;
    if(x==SZ(hard))return 0;
    if(dp[x][l_c]!=-1)return dp[x][l_c];
    if(l_c+1==aux[hard[x]]){
        dp[x][l_c] = min(h_a[x]+f(x+1,l_c),f(x+1,l_c+1));
    } else {
        dp[x][l_c] = f(x+1,l_c);
    }
    return dp[x][l_c];
}


int main(){FIN;
    aux['h']=1;aux['a']=2;aux['r']=3;aux['d']=4;
    mset(dp,-1);
    cin >> n;
    string s; cin >> s;
    vector<ll> a(n);fore(i,0,n)cin>>a[i];
    ll f_h = n+1, l_h = -1, f_a = n+1, l_a = -1, f_r = n+1, l_r = -1, f_d = n+1, l_d = -1;
    fore(i,0,n){
        if(s[i]=='h')f_h = min(i,f_h),l_h = max(l_h,i);
        if(s[i]=='a')f_a = min(i,f_a),l_a = max(l_a,i);
        if(s[i]=='r')f_r = min(i,f_r),l_r = max(l_r,i);
        if(s[i]=='d')f_d = min(i,f_d),l_d = max(l_d,i);
    }
    if(l_h == -1 || l_a == -1 || l_r == -1 || l_d == -1) {cout << "0\n"; return 0;}
    fore(i,0,n){
        if(s[i]=='h'&&i<l_a&&i<l_r&&i<l_d){
            if(hard!="" && hard.back()=='h')h_a[SZ(h_a)-1]+=a[i];
            else hard.pb('h'),h_a.pb(a[i]);
        }
        if(s[i]=='a'&&i>f_h&&i<l_r&&i<l_d){
            if(hard.back()=='a')h_a[SZ(h_a)-1]+=a[i];
            else hard.pb('a'),h_a.pb(a[i]);
        }
        if(s[i]=='r'&&i>f_a&&i>f_h&&i<l_d){
            if(hard.back()=='r')h_a[SZ(h_a)-1]+=a[i];
            else hard.pb('r'),h_a.pb(a[i]);
        }
        if(s[i]=='d'&&i>f_h&&i>f_a&&i>f_r){
            if(hard.back()=='d')h_a[SZ(h_a)-1]+=a[i];
            else hard.pb('d'),h_a.pb(a[i]);
        }
    }
    cout << f(0,0) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/