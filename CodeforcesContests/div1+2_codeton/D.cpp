#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        long long q, a, b, n, event_type, aux_max_h, aux_min_h, least_days;
        cin >> q;
        bool max_min_charged = false;
        long long max_h = 0; long long min_h = 0;
        for(int i = 0; i < q; ++i){
            cin >> event_type;
            if(event_type == 1){
                cin >> a >> b >> n;
                if (!max_min_charged){
                    cout << 1 << " ";
                    if (n>1){
                        max_h = (a-b)*(n-1)+a;
                        min_h = (a-b)*(n-1)+b+1;
                    } else {
                        max_h = a;
                        min_h = 1;
                    }
                    max_min_charged = true;
                    continue;
                }
                if (n > 1){
                    aux_max_h = (a-b)*(n-1)+a;
                    aux_min_h = (a-b)*(n-1)+b+1;
                } else {
                    aux_max_h = a;
                    aux_min_h = 1;
                }
                if(aux_max_h >= min_h && aux_min_h <= max_h){
                    // cout << aux_max_h << " " << aux_min_h << endl;
                    cout << 1 << " ";
                    max_h = min(max_h, aux_max_h);
                    min_h = max(min_h, aux_min_h);
                } else {
                    cout << 0 << " ";
                }
            } else if (!max_min_charged){
                cin >> a >> b;
                cout << -1 << " ";
                continue;
            } else {
                cin >> a >> b;
                // cout << "min_h: " << min_h << " max_h:" << max_h << " ";
                least_days = (min_h-a > 0)?(min_h-a)/(a-b):0;
                if(least_days*(a-b)+a >= max_h) {
                    cout << least_days+1 << " ";
                } else if (least_days*(a-b)+a<min_h && (least_days+1)*(a-b)+a>=max_h){
                    cout << least_days+2 << " ";
                } else {
                    cout << -1 << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}