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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll g[26][26];
const ll INF=1e9;
ll n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}


int main(){FIN;
    string s,t;cin>>s>>t;
    ll cant;cin>>cant; n=26;
    fore(i,0,26)fore(j,0,26){
        if(i==j)g[i][j]=0;
        else g[i][j]=INF;
    }
    fore(i,0,cant){
        char x,y;ll c;cin>>x>>y>>c;
        g[x-'a'][y-'a']=min(g[x-'a'][y-'a'],c);
    }
    floyd();
    if(SZ(s)!=SZ(t)){cout << "-1\n";return 0;}
    string ans="";ll cost = 0;
    fore(i,0,SZ(s)){
        if(s[i]==t[i]){ans+=s[i];continue;}
        ll aux = INF;char ag;
        if(g[s[i]-'a'][t[i]-'a']<aux){ag=t[i];aux=g[s[i]-'a'][t[i]-'a'];}
        if(g[t[i]-'a'][s[i]-'a']<aux){ag=s[i];aux=g[t[i]-'a'][s[i]-'a'];}
        fore(j,0,26){
            if(g[s[i]-'a'][j]+g[t[i]-'a'][j]<aux){
                ag=j+'a';aux=g[s[i]-'a'][j]+g[t[i]-'a'][j];
            }
        }
        cost += aux;
        ans += ag;
    }
    if(cost>=INF){cout << "-1\n";return 0;}
    cout << cost << "\n";
    cout << ans << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/