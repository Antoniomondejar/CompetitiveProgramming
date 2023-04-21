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

int main(){FIN;
    ll N, M, inp; cin >> N >> M;
    vector<pair<ll,ll>> num(N+M);
    fore(i,0,N){
        cin >> inp;
        num[i] = {inp, i};
    }
    fore(i, N, N+M){
        cin >> inp;
        num[i] = {inp, i};
    }
    sort(ALL(num));
    vector<ll> ind(N+M);
    fore(i,0,N+M){
        ind[num[i].second] = i;
    }
    fore(i,0,N){
        cout << ind[i]+1 << " ";
    }
    cout << "\n";
    fore(i,N,N+M) cout << ind[i]+1 << " ";
    cout << "\n";
    return 0;
}