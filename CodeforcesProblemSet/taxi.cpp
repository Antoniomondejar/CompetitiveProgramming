#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, group, number_of_taxis;
    cin >> N;
    map<int,int> groups;
    groups[1] = 0;
    groups[2] = 0;
    groups[3] = 0;
    groups[4] = 0;
    for(int i = 0; i < N; ++i){
        cin >> group;
        ++groups[group];
    }
    int min_3_1 = min(groups[3],groups[1]);
    groups[3] = groups[3] - min_3_1;
    groups[1] = groups[1] - min_3_1;
    number_of_taxis = groups[4]+min_3_1+(groups[2]/2)+groups[3];
    groups[2] = groups[2]%2;
    number_of_taxis = number_of_taxis + groups[1]/4;
    groups[1] = groups[1]%4;
    if(groups[1] == 3 && groups[2] == 1){
        number_of_taxis = number_of_taxis + 2;
    } else if (groups[1] > 0 || groups[2] > 0)
        ++number_of_taxis;
    cout << number_of_taxis << endl;
    return 0;
}