#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    int ctr = 0, no, noCtr;
    sort(ar.begin(), ar.begin() + ar.size());
    while( ar.size() > 0 ){
        noCtr = 1;
        no = ar[0];
        for( int sCtr = 1; sCtr < ar.size() && no == ar[sCtr]; sCtr++ )
            noCtr++;
        ar.erase(ar.begin(), ar.begin() + noCtr);
        ctr += noCtr / 2;
    }
    return ctr;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
