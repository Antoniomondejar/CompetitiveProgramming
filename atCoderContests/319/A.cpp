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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    map<string,ll> rat;
    rat["tourist"]= 3858;
    rat["ksun48"]= 3679;
    rat["Benq"]= 3658;
    rat["Um_nik"]= 3648;
    rat["apiad"]= 3638;
    rat["Stonefeang"]= 3630;
    rat["ecnerwala"]= 3613;
    rat["mnbvmar"]= 3555;
    rat["newbiedmy"]= 3516;
    rat["semiexp"]= 3481;
    string s;cin>>s;
    cout << rat[s] << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/