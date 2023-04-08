#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; int pigs_eaten = 0;
    cin >> n >> m;
    char grid[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'W'){
                if(i > 0 && grid[i-1][j] == 'P')
                    ++pigs_eaten;
                else if(i < n-1 && grid[i+1][j] == 'P')
                    ++pigs_eaten;
                else if(j>0 && grid[i][j-1] == 'P')
                    ++pigs_eaten;
                else if(j<m-1 && grid[i][j+1] == 'P')
                    ++pigs_eaten;
            }
        }
    }
    cout << pigs_eaten << "\n";
    return 0;
}