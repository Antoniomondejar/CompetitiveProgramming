#include <bits/stdc++.h>
using namespace std;

int main(void){
    int friends_right, friends_wrong; int my_possible_right = 0;
    cin >> friends_right;
    string friend_answers, my_answers;
    cin >> friend_answers >> my_answers;
    friends_wrong = friend_answers.length()-friends_right;
    for(int i = 0; i < friend_answers.length() && (friends_right > 0 || friends_wrong > 0); ++i){
        if(friend_answers[i] == my_answers[i] && friends_right > 0){
            ++my_possible_right;
            --friends_right;
        }
        if(friend_answers[i] != my_answers[i] && friends_wrong > 0){
            ++my_possible_right;
            --friends_wrong;
        }
    }
    cout << my_possible_right << endl;
    return 0;
}