#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, k, d, w, input;
        cin >> n >> k >> d >> w;
        int arrival_moments[n];
        for(int i = 0; i < n; ++i)
            cin >> arrival_moments[i];
        int current_time = arrival_moments[0]; int moment_of_doses_open = 0; int doses_remaining_of_pack = 0;
        int current_pacient = 0; int packs_opened = 0; int dose_time_left=0; int difference;
        while(current_pacient < n){
            current_time = w+arrival_moments[current_pacient];
            moment_of_doses_open = current_time;
            doses_remaining_of_pack = k;
            ++packs_opened;
            dose_time_left = d;
            while(current_pacient < n && arrival_moments[current_pacient]<=current_time && doses_remaining_of_pack>0){
                --doses_remaining_of_pack;
                ++current_pacient;
                if(current_pacient < n && arrival_moments[current_pacient]>current_time){
                    difference = max(0, min(w+(arrival_moments[current_pacient]-current_time), dose_time_left));
                    current_time = current_time + difference;
                    dose_time_left = dose_time_left - difference;
                }
            }
        }
        cout << packs_opened << endl;
    }
}