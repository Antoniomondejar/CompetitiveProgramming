#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggmat=b;i<ggmat;++i)
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX=1e3+10;

vector<pair<ll,ll>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
string grid[NMAX];
bool g[NMAX][NMAX][4];
ll vis[NMAX][NMAX];
ll dis[NMAX][NMAX];

bool bfs(pair<ll,ll> ex){
    queue<pair<ll,ll>> q;
    q.push(ex);vis[ex.fst][ex.snd]=1; dis[ex.fst][ex.snd]=0;
    while(SZ(q)){
        auto cv = q.front();q.pop();
        fore(i,0,4){
            if(!g[cv.fst][cv.snd][i])continue;
            if(vis[cv.fst+moves[i].fst][cv.snd+moves[i].snd])continue;
            vis[cv.fst+moves[i].fst][cv.snd+moves[i].snd]=1;
            dis[cv.fst+moves[i].fst][cv.snd+moves[i].snd]=dis[cv.fst][cv.snd]+1;
            q.push({cv.fst+moves[i].fst,cv.snd+moves[i].snd});
        }
    }
    return 0;
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        fore(i,0,n){
            fore(j,0,m){
                g[i][j][0]=0;g[i][j][1]=0;g[i][j][2]=0;g[i][j][3]=0;
                vis[i][j]=0;dis[i][j]=1e18;
            }
        }
        fore(i,0,n)cin>>grid[i];
        vector<pair<ll,ll>> fires;
        pair<ll,ll> st, ex;
        fore(i,0,n){
            fore(j,0,m){
                if(grid[i][j]=='#')continue;
                if(i>0 && grid[i-1][j]!='#')g[i][j][0]=1;
                if(i<n && grid[i+1][j]!='#')g[i][j][1]=1;
                if(j>0 && grid[i][j-1]!='#')g[i][j][2]=1;
                if(j<m && grid[i][j+1]!='#')g[i][j][3]=1;
                if(grid[i][j]=='S')st={i,j};
                if(grid[i][j]=='F')fires.pb({i,j});
                if(grid[i][j]=='E')ex={i,j};
            }
        }
        bfs(ex);
        if(dis[st.fst][st.snd]==1e18){cout << "N\n";continue;}
        bool p = true;
        for(auto i:fires){
            if(dis[i.fst][i.snd]<=dis[st.fst][st.snd]){p=false;break;}
        }
        if(p)cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}