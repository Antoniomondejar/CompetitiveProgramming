#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 510;
const ll MOD = 1e9+7;

string grid[NMAX];


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        fore(i,0,n)cin>>grid[i];
        vector<ll> rows(n);
        vector<ll> col(m);
        fore(i,0,n){
            fore(j,0,m){
                if(grid[i][j]!='.'){
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        bool p = true;
        fore(i,0,n){
            if(rows[i]&1){p=false;break;}
        }
        fore(j,0,m){
            if(col[j]&1){p=false;break;}
        }
        if(!p){cout << "-1\n";continue;}
        vector<ll> u_r(n), l_c(m);
        vector<string> ans;
        fore(i,0,n){
            ans.pb("");
            fore(j,0,m){
                if(grid[i][j]=='.') {ans[i]+='.';continue;}
                if(grid[i][j]=='U'){
                    if(u_r[i]%2==0){
                        ans[i]+='W';
                    } else {
                        ans[i]+='B';
                    }
                    u_r[i]++;
                } else if(grid[i][j]=='L'){
                    if(l_c[j]%2==0){
                        ans[i]+='W';
                    } else {
                        ans[i]+='B';
                    }
                    l_c[j]++;
                } else if(grid[i][j]=='R'){
                    if(ans[i][j-1]=='W')ans[i]+='B';
                    else ans[i]+='W';
                } else {
                    if(ans[i-1][j]=='B') ans[i]+='W';
                    else ans[i]+='B';
                }
            }
        }
        fore(i,0,n){
            cout << ans[i] << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/