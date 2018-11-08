#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// I have completed getTotalX method
int getTotalX(vector <int> a, vector <int> b) {
    int aMod, bMod, result = 0;
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    for( int x = a[a.size()-1]; x <= b[0] ; x++ ){
        aMod = bMod = 0;
        for( int element : a )
            aMod += x % element;
        for( int element : b )
            bMod += element % x;
        if ( aMod == bMod && aMod == 0 )
            result++;
    }
    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
