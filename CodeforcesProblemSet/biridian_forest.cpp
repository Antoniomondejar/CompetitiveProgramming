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

const ll NMAX = 1e3+10;
bool g[NMAX][NMAX][4]; // {izq,der,arriba,abajo}
ll dis[NMAX][NMAX];
bool vis[NMAX][NMAX];
vector<pair<ll,ll>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
string row[NMAX];

void bfs(pair<ll,ll> v){
    queue<pair<pair<ll,ll>,ll>> b_q; b_q.push({v,0});
    vis[v.fst][v.snd] = 1;
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,4){
            if(!g[cv.fst.fst][cv.fst.snd][i])continue;
            if(vis[cv.fst.fst+moves[i].fst][cv.fst.snd+moves[i].snd]) continue;
            vis[cv.fst.fst+moves[i].fst][cv.fst.snd+moves[i].snd] = 1;
            dis[cv.fst.fst+moves[i].fst][cv.fst.snd+moves[i].snd] = cv.snd+1;
            b_q.push({{cv.fst.fst+moves[i].fst,cv.fst.snd+moves[i].snd},cv.snd+1});
        }
    }
}


int main(){
    ll r, c; cin >> r >> c;
    pair<ll,ll> ex, y;
    fore(i,0,r) cin >> row[i];
    fore(i,0,r){
        fore(j,0,c){
            if(row[i][j] == 'T')continue;
            if(i>0 && row[i-1][j]!='T')g[i][j][0] = 1;
            if(i<r && row[i+1][j] != 'T')g[i][j][1] = 1;
            if(j>0 && row[i][j-1] != 'T')g[i][j][2] = 1;
            if(j<c && row[i][j+1] != 'T')g[i][j][3] = 1;
            if(row[i][j] == 'E') ex = {i,j};
            if(row[i][j] == 'S') y = {i,j};
            dis[i][j] = NMAX*NMAX;
        }
    }
    bfs(ex);
    ll min_d = dis[y.fst][y.snd]; ll res = 0;
    fore(i,0,r){
        fore(j,0,c){
            if(row[i][j]>'0' && row[i][j]<='9' && dis[i][j]<=min_d){
                res += row[i][j]-'0';
            }
        }
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/