#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


struct UF {
  vector<ll> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) {return find(a) == find(b);}
  int size(int x) { return -e[find(x)]; }
  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a,b);
    e[a] += e[b]; e[b]=a;
    return true;
  }
};

map<ll,vector<pair<ll,ll>>> col;
map<ll,vector<pair<ll,ll>>> fil;



int main(){FIN;
	ll n;cin>>n;
	UF uf(n);
	vector<vector<ll>> fig(n);
	fore(i,0,n){
		ll x,y,w,h;cin>>x>>y>>w>>h;
		fil[y].pb({x,i});fil[y].pb({x+w,i});
		fil[y+h].pb({x,i});fil[y+h].pb({x+w,i});
		col[x].pb({y,i});col[x].pb({y+h,i});
		col[x+w].pb({y,i});col[x+w].pb({y+h,i});
		fig[i]={x,y,w,h};
	}
	for(auto &i:col){
		sort(ALL(i.snd));
	}
	for(auto &i:fil){
		sort(ALL(i.snd));
	}
	fore(i,0,n){
		ll x=fig[i][0],y=fig[i][1],w=fig[i][2],h=fig[i][3];
		//abajo
		ll pos = lower_bound(ALL(fil[y]),make_pair(x,0ll))-fil[y].begin();
		while(pos<SZ(fil[y]) && fil[y][pos].fst<x+w){
			uf.join(fil[y][pos].snd,i);
			++pos;
		}
		//arriba
		pos = lower_bound(ALL(fil[y+h]),make_pair(x,0ll))-fil[y+h].begin();
		while(pos<SZ(fil[y+h]) && fil[y+h][pos].fst<x+w){
			uf.join(fil[y+h][pos].snd,i);
			++pos;
		}
		// izq
		pos = lower_bound(ALL(col[x]),make_pair(y,0ll))-col[x].begin();
		while(pos<SZ(col[x]) && col[x][pos].fst<y+h){
			uf.join(col[x][pos].snd,i);
			++pos;
		}
		// der
		pos = lower_bound(ALL(col[x+w]),make_pair(y,0ll))-col[x+w].begin();
		while(pos<SZ(col[x+w]) && col[x+w][pos].fst<y+h){
			uf.join(col[x+w][pos].snd,i);
			++pos;
		}
	}
	ll res = 0;
	vector<ll> areas(n);
	fore(i,0,n){
		ll h = fig[i][2], w=fig[i][3];
		ll pa = uf.find(i);
		areas[pa]+=h*w;
		res = max(res,areas[pa]);
	}
	cout << res << "\n";
	return 0;
}