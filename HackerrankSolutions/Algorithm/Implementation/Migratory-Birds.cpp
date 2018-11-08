#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    int a[5] = {0}, res = 0, max = 0;
    for( int bird : ar )
        a[--bird]++;
    for( int ctr = 4; ctr >= 0; ctr-- ){
        if( a[ctr] >= max ){
            max = a[ctr];
            res = ctr + 1;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
