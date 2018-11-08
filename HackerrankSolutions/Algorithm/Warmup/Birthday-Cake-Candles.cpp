#include <bits/stdc++.h>
#include <algorithm>    //I added this library

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Code added by me
    int max = *max_element(ar.begin(), ar.end());
    return count(ar.begin(), ar.end(), max);
    // until here
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
