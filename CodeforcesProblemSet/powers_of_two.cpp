#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int powers_of_two[30];
    powers_of_two[0] = 1;
    for(int i = 1; i < 30; ++i)
        powers_of_two[i] = powers_of_two[i-1]*2;

    queue <unsigned char> terms;
    int remainder = n; unsigned char i = (char)0;
    while(remainder > 0){ // Menor cantidad de términos.
        i = 0;
        while (i < 30 && powers_of_two[i]<remainder){
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
    // cout << queue_length << endl;
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
    int terms_length = terms.size();
    while(k > terms_length){
        // cout << "hola" << endl;
        if(powers_of_two[current_power_of_two] == 1){
            terms.pop();
            terms.push((char)0);
            current_power_of_two = terms.front();
            continue;
        }
        terms.pop();
        terms.push(current_power_of_two-1);
        terms.push(current_power_of_two-1);
        current_power_of_two = terms.front();
        ++terms_length;
    }
    cout << "YES" << endl;
    for(int i = 0; i < k; ++i){
        cout << powers_of_two[terms.front()] << " ";
        terms.pop();
    }
    return 0;
}