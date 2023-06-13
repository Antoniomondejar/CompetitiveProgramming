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

vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
int main(){FIN;
    string s; cin >> s;
    vector<int> z_res = z_function(s);
    vector<int> ans;
    fore(i,1,SZ(s)){
        if(z_res[i]==SZ(s)-i)ans.pb(SZ(s)-i);
    }
    reverse(ALL(ans));
    for(auto i:ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/