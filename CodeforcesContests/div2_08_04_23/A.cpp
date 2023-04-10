#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        int min_number_of_obstacles_1 = 4;
        int min_number_of_obstacles_2 = 4;
        if(x1 == 1 || y1 == 1 || x1 == n || y1 == m){
            --min_number_of_obstacles_1;
            if(y1 == 1 && x1 == 1 || x1 == 1 && y1 == m || x1 == n && y1 == 1 || x1 == n && y1 == m){
                --min_number_of_obstacles_1;
            }
        }
        if(x2 == 1 || y2 == 1 || x2 == n || y2 == m){
            --min_number_of_obstacles_2;
            if(y2 == 1 && x2 == 1 || x2 == 1 && y2 == m || x2 == n && y2 == 1 || x2 == n && y2 == m){
                --min_number_of_obstacles_2;
            }
        }
        cout << min(min_number_of_obstacles_1, min_number_of_obstacles_2) << "\n";
    }
    return 0;
}