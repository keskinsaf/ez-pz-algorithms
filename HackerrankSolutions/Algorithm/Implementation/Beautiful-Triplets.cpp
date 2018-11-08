#include <bits/stdc++.h>

using namespace std;

int beautifulTriplets(int d, vector <int> arr) {
    int ctr = 0;
    for(int i = 0; arr.size() > 2 && (i < arr.size() - 2); i++ ){ //if array size is less than 3, result must be 0
        for( int j = i + 1; j < arr.size() - 1; j++ ){
            if( arr[j] - arr[i] == d ){
                for( int k = j + 1; k < arr.size(); k++ ){
                    if( arr[k] - arr[j] == d ){
                        ctr++;
                        break;
                    }
                }
                break;
            }
        }
    }
    return ctr;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = beautifulTriplets(d, arr);
    cout << result << endl;
    return 0;
}
