#include <bits/stdc++.h>
using namespace std;

int main(void){
    while(1){
        int n;
        char input;
        cin >> n;
        if (cin.eof())
            break;
        set<char> rows[n];
        set<char> columns[n];
        char grid[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> input;
                rows[i].insert(input);
                columns[j].insert(input);
                grid[i][j] = input;
            }
        }

        bool latin_square = true; bool reduced = true;
        for(int i = 0; i < n && latin_square; ++i){
            latin_square = latin_square && (rows[i].size() == n) && (columns[i].size() == n);
        }
        
        if (latin_square){
            for(int i = 0; i < (n-1) && reduced; ++i){
                reduced = reduced && (grid[0][i] < grid[0][i+1]) && (grid[i][0] < grid[i+1][0]);
            }
        }

        if(!latin_square)
            cout << "No" << endl;
        else if(!reduced)
            cout << "Not Reduced" << endl;
        else
            cout << "Reduced" << endl;
    }
    return 0;
}