#include <bits/stdc++.h>
using namespace std;
int main(void){
    string day;
    long long N, number_of_the_day;
    cin >> day >> N;
    string days[7] = {"Mon", "Tue","Wed","Thu", "Fri", "Sat", "Sun"};
    for(long i = 0; i < 7; ++i){
        if (days[i] == day){
            number_of_the_day = i;
            break;
        }
    }
    long long minimum_days = LONG_LONG_MAX;
    long long days_elapsed;
    long long day_of_deposit, day_end_deposit;
    for(int i = 0; i < N; ++i){
        cin >> days_elapsed;
        day_of_deposit = ((number_of_the_day - (days_elapsed%30)%7)+7)%7;
        if (days[day_of_deposit] == "Sat")
            days_elapsed = days_elapsed-2;
        else if (days[day_of_deposit] == "Sun")
            days_elapsed = days_elapsed-1;
        if (days_elapsed%30==0 && days_elapsed>0){
            day_end_deposit = number_of_the_day;
            if(days[day_end_deposit] == "Sat")
                minimum_days = (minimum_days<2) ? minimum_days:2;
            else if(days[day_end_deposit] == "Sun")
                minimum_days = (minimum_days<1) ? minimum_days:1;
            else
                minimum_days = 0;
        } else {
            day_end_deposit = (number_of_the_day+(30-days_elapsed%30)%7)%7;
            if(days[day_end_deposit] == "Sat")
                minimum_days = min(minimum_days, 30-(days_elapsed%30)+2);
            else if(days[day_end_deposit] == "Sun")
                minimum_days = min(minimum_days, 30-(days_elapsed%30)+1);
            else
                minimum_days = min(minimum_days, 30-(days_elapsed%30));
        }
    }
    cout << minimum_days << endl;
    return 0;
}