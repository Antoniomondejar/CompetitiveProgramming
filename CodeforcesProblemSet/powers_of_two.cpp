#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n, k;
    cin >> n >> k;
    long long powers_of_two[30];
    powers_of_two[0] = 1;
    for(int i = 1; i < 30; ++i)
        powers_of_two[i] = powers_of_two[i-1]*2;

    queue <int> terms;
    long long remainder = n; int i = 0;
    while(remainder > 0){ // Menor cantidad de términos.
        i = 0;
        while (powers_of_two[i]<remainder){
            ++i;
        }
        if (remainder == powers_of_two[i]){
            remainder = remainder - powers_of_two[i];
            terms.push(i);
        } else {
            remainder = remainder - powers_of_two[i-1];
            terms.push(i-1);
        }
    }
    int queue_length = terms.size();
    if (k < terms.size() || k > n){
        cout << "NO" << endl;
        return 0;
    }
    if (k == terms.size()){
        cout << "YES" << endl;
        for(int i = 0; i < queue_length; ++i){
            cout << powers_of_two[terms.front()] << " ";
            terms.pop();
        }
        return 0;
    }

    int current_power_of_two = terms.front();
    while(k > terms.size()){
        if(powers_of_two[current_power_of_two] == 1){
            terms.pop();
            terms.push(0);
            current_power_of_two = terms.front();
            continue;
        }
        terms.pop();
        terms.push(current_power_of_two-1);
        terms.push(current_power_of_two-1);
        current_power_of_two = terms.front();
    }
    queue_length = terms.size();
    cout << "YES" << endl;
    for(int i = 0; i < queue_length; ++i){
        cout << powers_of_two[terms.front()] << " ";
        terms.pop();
    }
    return 0;
}