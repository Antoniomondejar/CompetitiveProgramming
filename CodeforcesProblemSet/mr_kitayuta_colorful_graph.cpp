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

const ll MAXN = 1e2+10;
int uf[MAXN][MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x, int i){return uf[x][i]<0?x:uf[x][i]=uf_find(uf[x][i],i);}
bool uf_join(int x, int y, int i){
	x=uf_find(x,i);y=uf_find(y,i);
	if(x==y)return false;
	if(uf[x][i]>uf[y][i])swap(x,y);
	uf[x][i]+=uf[y][i];uf[y][i]=x;
	return true;
}


int main(){FIN;
    ll n,m; cin >> n >> m;
    uf_init();
    set<ll> colors;
    fore(i,0,m){
        ll x,y,c; cin >> x >> y >> c;
        uf_join(x,y,c);
        colors.insert(c);
    }
    ll q; cin >> q;
    fore(i,0,q){
        ll res = 0;
        ll x,y; cin >> x >> y;
        for(auto i:colors){
            if(uf_find(x,i)==uf_find(y,i) && uf_find(x,i)>0) ++res;
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/