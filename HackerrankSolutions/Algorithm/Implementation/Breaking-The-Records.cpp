#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, lCtr = -1, hCtr = -1, min = 10e9, max = -1;
    cin >> n;
    vector<int> score(n);
    for(int score_i = 0; score_i < n; score_i++){
       cin >> score[score_i];
       if( score[score_i] > max ){
           hCtr++;
           max = score[score_i];
       }
       if( score[score_i] < min ){
           lCtr++;
           min = score[score_i];
       }
    }
    cout << hCtr << " " << lCtr << "\n";

    return 0;
}
