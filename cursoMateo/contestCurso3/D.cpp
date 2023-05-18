#include "bits/stdc++.h"
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
const ll NMAX=50+10; 
bool p[NMAX][NMAX][4]; //{izq,der,arr,ab}
string grid[NMAX];
ll vis[NMAX][NMAX];
vector<pair<ll,ll> > moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<pair<ll,ll> > r11;
vector<pair<ll,ll> > r22;

bool bfs(pair<ll,ll> x, pair<ll,ll> y){
    vis[x.fst][x.snd]=1;
    queue<pair<ll,ll> > b; b.push(x);
    ll min_d = (x.fst-y.fst)*(x.fst-y.fst) + (x.snd-y.snd)*(x.snd-y.snd);
    while(SZ(b)){
        auto cv = b.front(); b.pop();
        if(cv == y) return true;
        fore(i,0,4){
            if(!p[cv.fst][cv.snd][i]) continue;
            pair<ll,ll> n = {cv.fst+moves[i].fst, cv.snd+moves[i].snd};
            if(vis[n.fst][n.snd]) continue;
            vis[n.fst][n.snd] = 1;
            b.push(n);
            r11.pb(n);
        }
    }
    return false;
}

bool bfs2(pair<ll,ll> x, pair<ll,ll> y){
    vis[x.fst][x.snd]=1;
    queue<pair<ll,ll> > b; b.push(x);
    while(SZ(b)){
        auto cv = b.front(); b.pop();
        if(cv == y) return true;
        fore(i,0,4){
            if(!p[cv.fst][cv.snd][i]) continue;
            pair<ll,ll> n = {cv.fst+moves[i].fst, cv.snd+moves[i].snd};
            if(vis[n.fst][n.snd]) continue;
            vis[n.fst][n.snd] = 1;
            b.push(n);
            r22.pb(n);
        }
    }
    return false;
}

int main(){
    ll n; cin >> n;
    ll r1, c1; ll r2,c2; cin >> r1 >> c1 >> r2 >> c2;
    --r1; --r2; --c1; --c2;
    fore(i,0,n){
        cin>>grid[i];
    }
    fore(i,0,n){
        fore(j,0,n){
            if(grid[i][j] == '1') continue;
            if(i>0 && grid[i-1][j] != '1') p[i][j][0] = 1;
            if(i<n && grid[i+1][j] != '1') p[i][j][1] = 1;
            if(j>0 && grid[i][j-1] != '1') p[i][j][2] = 1;
            if(j<n && grid[i][j+1] != '1') p[i][j][3] = 1;
        }
    }
    bool res = bfs({r1,c1}, {r2,c2});
    if(res) {
        cout << "0\n";
        return 0;
    }
    bfs2({r2,c2}, {r1,c1});
    ll min_d = (r1-r2)*(r1-r2) + (c1-c2)*(c1-c2);
    r11.pb({r1,c1});
    r22.pb({r2,c2});
    for(auto i : r11){
        for(auto j: r22){
            min_d = min(min_d, (i.fst-j.fst)*(i.fst-j.fst) + (i.snd-j.snd)*(i.snd-j.snd));
        }
    }
    cout << min_d << "\n";
    return 0;
}