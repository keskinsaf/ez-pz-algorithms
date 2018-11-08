#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector <int> countingSort(vector <int> arr) {
    vector<int> res;
    for( int i = 0; i < 100; i++)
        res.push_back( count(arr.begin(), arr.end(), i ) );
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = countingSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
