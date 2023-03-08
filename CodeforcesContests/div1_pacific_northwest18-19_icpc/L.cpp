#include <bits/stdc++.h>
using namespace std;

int comparison(pair<int,int> a, pair<int,int> b){

}


int main(void){
    int n, first, second;
    cin >> n;
    pair<int,int> people[n];
    for(int i = 0; i < n; ++i){
        cin >> first >> second;
        people[i] = make_pair(first, second);
    }
    sort(people, people+n);
    int minimum_truthful_people = 0; int maximum_truthful_people = 0;
    int truthful_people_at_the_moment = 0; bool inconsistent = false;
    int max_truthful_at_the_moment = -1;
    for(int i = n-1; i >= 0; --i){
        minimum_truthful_people = people[i].first;
        maximum_truthful_people = people[i].second;
        truthful_people_at_the_moment = 1;
        for(int j = i-1; j >= 0; --j){
            
        }
    }
