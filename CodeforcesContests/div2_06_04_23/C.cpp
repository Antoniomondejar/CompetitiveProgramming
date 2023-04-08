#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, s1, s2, r_input;
        cin >> n >> s1 >> s2;
        pair<int,int> times_each_color[n];
        for(int i = 0; i < n; ++i){
            cin >> r_input;
            times_each_color[i] = make_pair(r_input, i+1);
        }
        sort(times_each_color, times_each_color+n);
        vector<int> robot_1;
        vector<int> robot_2;
        long long time_spent_1 = 0;long long time_spent_2 = 0;
        for(int i = n-1; i >= 0; --i){
            if(times_each_color[i].first*(s1+time_spent_1) < times_each_color[i].first*(s2 + time_spent_2)){
                time_spent_1 += s1;
                robot_1.push_back(times_each_color[i].second);
            } else {
                time_spent_2 += s2;
                robot_2.push_back(times_each_color[i].second);
            }
        }
        cout << robot_1.size() << " ";
        for(int i = 0; i < robot_1.size(); ++i){
            cout << robot_1.at(i) << " ";
        }
        cout << "\n";
        cout << robot_2.size() << " ";
        for(int i = 0; i < robot_2.size(); ++i){
            cout << robot_2.at(i) << " ";
        }
        cout << "\n";
    }
    return 0;
}