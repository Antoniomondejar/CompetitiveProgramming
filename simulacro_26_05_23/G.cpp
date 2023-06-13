#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Point {
    ll x, y;

    Point operator+(Point p) { 
        return {x + p.x, y + p.y};
    }
};



pair<int,int> x0,x1,x2; // (xi,yi)

pair<int,int> p[3];

int main(void){FIN;
    cin>>x0.fst>>x0.snd;
    cin>>x1.fst>>x1.snd;
    cin>>x2.fst>>x2.snd;

    p[0].fst = (x1.fst+x2.fst) - x0.fst;
    p[0].snd = (x1.snd+x2.snd) - x0.snd;

    p[1].fst = x0.fst+ x1.fst-x2.fst ;
    p[1].snd = x0.snd+ x1.snd-x2.snd ;

    p[2].fst=x0.fst+(x2.fst-x1.fst);
    p[2].snd=x0.snd+(x2.snd-x1.snd);

    cout << "3\n";

    fore(i, 0, 3) {
        cout << p[i].first << ' ' << p[i].second << '\n';
    }

    return 0;
}