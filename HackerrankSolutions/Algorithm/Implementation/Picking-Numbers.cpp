#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int pickingNumbers(vector <int> a) {
    int max = 0, ctr, ar[a.size() - 1] = {0};
    sort( a.begin(), a.end() );
    for( int i = 0; i < a.size()-1; i++){
        ctr = 1;
        for(int j = i+1; j < a.size(); j++){
            if( a[j] == a[i] || a[j] == (a[i] + 1) )
                ctr++;
            else
                break;
        }
        ar[i] = ctr;
        if ( max < ar[i] )
            max = ar[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = pickingNumbers(a);
    cout << result << endl;
    return 0;
}
