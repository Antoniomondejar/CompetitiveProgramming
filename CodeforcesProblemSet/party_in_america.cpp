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
const ll NMAX = 78125+10;
const ll MOD = 1e9+7;

ll n,m,k;
string grid[10];

map<ll,vector<ll>> itov;
map<vector<ll>,ll> vtoi;
ll dp[10][NMAX][60];
ll pot[10];

ll add(ll x, ll y){
    return (x+y)%MOD;
}


ll mul(ll x, ll y){
    return (x*y)%MOD;
}

vector<ll> get_vec(ll x){
    vector<ll> res;
    fore(i,0,n){
        res.pb(x%5);
        x/=5;
    }
    return res;
}

ll f(ll x, ll mask, ll y){
    // cout << x << " " << mask << " " << y << "\n";
    if(y==m)return 1;
    ll &res = dp[x][mask][y];
    if(x==n)return res=f(0,mask,y+1);
    if(res!=-1)return res;
    vector<ll> v = get_vec(mask);
    res = 0;
    if(x==0){
        if(grid[x][y]!='-'){
            ll nu = grid[x][y]-'0';
            // cout << nu << " ";
            ll mask_aux = mask;
            if(nu==v[x])return 0;
            mask_aux-=v[x];
            mask_aux+=nu;
            res = f(x+1,mask_aux,y);
        } else {
            fore(i,1,k+1){
                ll mask_aux = mask;
                if(v[x]==i)continue;
                mask_aux -= v[x];
                mask_aux += i;
                res = add(res,f(x+1,mask_aux,y));
            }
        }
    } else {
        if(grid[x][y]!='-'){
            ll nu = grid[x][y]-'0';
            if(nu==v[x]||nu==v[x-1])return 0;
            ll mask_aux = mask;
            mask_aux -= pot[x]*v[x];
            mask_aux += pot[x]*nu;
            res = f(x+1,mask_aux,y);
        } else {
            fore(i,1,k+1){
                ll mask_aux = mask;
                if(v[x]==i || v[x-1]==i)continue;
                mask_aux-=v[x]*pot[x];
                mask_aux+=i*pot[x];
                res = add(res,f(x+1,mask_aux,y));
            }
        }
    }
    // cout << x << " " << mask << " " << y << " " << res << "\n";
    return res;
}


int main(){FIN;
    cin>>n>>m>>k;
    fore(i,0,n)cin>>grid[i];
    vector<ll> v(k+1);
    pot[0]=1;fore(i,1,10)pot[i]=pot[i-1]*5;
    fore(i,0,k+1)v[i]=i;
    mset(dp,-1);
    ll res = f(0,0,0);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/