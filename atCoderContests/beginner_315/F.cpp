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
typedef long double ld;
const ll NMAX = 1e4+10;
const ll MOD = 1e9+7;

pair<ld,ld> a[NMAX];
ld dp[NMAX][30];
ll n;

ld distance(pair<ld,ld> x, pair<ld,ld> y){
    return sqrt((x.fst-y.fst)*(x.fst-y.fst)+(x.snd-y.snd)*(x.snd-y.snd));
}


ld f(ll x, ll c){
    if(x==n-1) return 0;
    ld &res = dp[x][c];
    if(res!=-1)return res;
    res = distance(a[x],a[x+1])+f(x+1,c);
    fore(i,1,30){
        if(i+c>28 || i+x+1>n-1)break;
        res = min(res,(1LL<<(c+i-1))-(c==0?0:1LL<<(c-1))+distance(a[x],a[x+i+1])+f(x+i+1,c+i));
    }
    // cout << x << " " << c << " " << res << "\n";
    return res;
}


int main(){FIN;
    cin>>n;
    fore(i,0,n)cin>>a[i].fst>>a[i].snd;
    fore(i,0,n)fore(j,0,30)dp[i][j]=-1;
    ld res = f(0,0);
    cout <<setprecision(16) << fixed << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/