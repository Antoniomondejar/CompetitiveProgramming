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
const ll NMAX = 5e3+10;
const ll MOD = 1e9+7;

int dp[NMAX][NMAX][2];
int n,new_n,w,h;
vector<vector<int>> h_s;

int f(int x, int y, int puse){
    if(x==new_n)return 0;
    int &res = dp[x][y][puse];
    if(res!=-1)return res;
    if(!puse){
        res = max(1+f(x+1,x,1),f(x+1,y,0));
    } else if(h_s[x][0]>h_s[y][0] && h_s[x][1]>h_s[y][1]){
        res = max(1+f(x+1,x,1),f(x+1,y,1));
    } else {
        res = f(x+1,y,1);
    }
    // cout << x << " " << y << " " << puse << " " << res << "\n";
    return res;
}

vector<int> ans;

void build(int x, int y, int puse){
    if(x==new_n)return;
    int res = f(x,y,puse);
    if(!puse){
        if(res == 1+f(x+1,x,1)){
            ans.pb(h_s[x][2]);
            build(x+1,x,1);
        } else {
            build(x+1,y,0);
        }
    } else if(h_s[x][0]>h_s[y][0] && h_s[x][1]>h_s[y][1]){
        if(res==1+f(x+1,x,1)){
            ans.pb(h_s[x][2]);
            build(x+1,x,1);
        } else {
            build(x+1,y,1);
        }
    } else {
        build(x+1,y,1);
    }
}

int main(){
    cin>>n>>w>>h;
    fore(i,0,n){
        int wi,hi;cin>>wi>>hi;
        if(wi<=w || hi<=h)continue;
        h_s.pb({wi,hi,i});
    }
    new_n = SZ(h_s);
    if(new_n==0){cout << "0\n";return 0;}
    mset(dp,-1);
    // cout << new_n << "\n";
    sort(ALL(h_s));
    build(0,0,0);
    cout << SZ(ans) << "\n";
    for(auto i:ans){cout << i+1 << " ";}
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/