#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(ull i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){FIN;

    ull A, S, L, R;
    cin >> A >> S >> L >> R;

    fore(i, L, min(S,R)+1) {
        // k = 1
        if (i == S) {
            cout << i << endl;
        }
        // k > 1
        fore(k, 2, R-L+1) {
            if (((S-i*k)*2) % ((k-1)*k)) {
                ull D = (S-i*k)*2/((k-1)*k);
                if (D*k <= R) {
                    // print i,D,k
                    ull x = i;
                    cout << x;
                    fore(j, 1, k) {
                        x += j*D;
                        cout << "," << x;
                    }
                    cout << endl;       
                }
            }
        }
    }


    return 0;
}

/*
visitante@stic06:~/tap$ ./a.out 
5 15 1 10
1,2,4,7
1,1,1,1,1,1
1,1,1,1,1,1,1
1,1,1,1,1,1,1,1
1,1,1,1,1,1,1,1,1
2,3,5,8
2,2,2,2,2
2,2,2,2,2,2
2,2,2,2,2,2,2
3,3,3,3
*/