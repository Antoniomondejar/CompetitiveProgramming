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

typedef long long td; typedef vector<int> vi; typedef vector<td> vd;
const td INF=1000000000000000LL;//for maximum set INF to 0, and negate costs
bool zero(td x){return (x==0);}//change to x==0, for ints/ll
struct Hungarian{
    int n; vector<vd> cs; vi L, R;
    Hungarian(int N, int M):n(max(N,M)),cs(n,vd(n)),L(n),R(n){
        fore(x,0,N)fore(y,0,M)cs[x][y]=INF;
    }
    void set(int x,int y,td c){cs[x][y]=c;}
    void show(){
        fore(i,0,n){
            fore(j,0,n){
                cout << cs[i][j] << " ";
            }
            cout << "\n";
        }
    }
	td assign() {
		int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n);
		fore(i,0,n)u[i]=*min_element(ALL(cs[i]));
		fore(j,0,n){v[j]=cs[0][j]-u[0];fore(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);}
		L=R=vi(n, -1);
		fore(i,0,n)fore(j,0,n)
			if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		for(;mat<n;mat++){
		    int s=0, j=0, i;
		    while(L[s] != -1)s++;
		    fill(ALL(dad),-1);fill(ALL(sn),0);
		    fore(k,0,n)ds[k]=cs[s][k]-u[s]-v[k];
		    for(;;){
		        j = -1;
		        fore(k,0,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
		        sn[j] = 1; i = R[j];
		        if(i == -1) break;
		        fore(k,0,n)if(!sn[k]){
		            auto new_ds=ds[j]+cs[i][k]-u[i]-v[k];
		            if(ds[k] > new_ds){ds[k]=new_ds;dad[k]=j;}
		        }
		    }
		    fore(k,0,n)if(k!=j&&sn[k]){auto w=ds[k]-ds[j];v[k]+=w,u[R[k]]-=w;}
		    u[s] += ds[j];
		    while(dad[j]>=0){int d = dad[j];R[j]=R[d];L[R[j]]=j;j=d;}
		    R[j]=s;L[s]=j;
		}
		td value=0;fore(i,0,n)value+=cs[i][L[i]];
		return value;
	}
};

ll a[510][510];
ll N;

ll fuerza_bruta(){
    vector<ll> p(N/2);
    fore(i,0,N/2){
        p[i]=i;
    }
    ll res = INF;
    do{
        ll cost = 0;
        fore(i,0,N/2){
            cost += a[2*i][p[i]]+a[p[i]][2*i+2];
        }
        res = min(res,cost);
    } while(next_permutation(ALL(p)));
    return res;
}


int main(){FIN;
    cin>>N;
    fore(i,0,N){
        fore(j,0,N){
            cin>>a[i][j];
        }
    }
    Hungarian h((N+1)/2,(N+1)/2);
    fore(i,0,(N+1)/2){
        fore(j,0,(N+1)/2){
            ll cost = 0;
            if(j==0){
                cost=a[2*i][1];
            } else {
                cost=a[2*j-1][2*i]+a[2*i][2*j+1];
            }
            h.set(i,j,cost);
        }
    }
    ll res = h.assign();
    cout << res << "\n";
    // h.show();
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/