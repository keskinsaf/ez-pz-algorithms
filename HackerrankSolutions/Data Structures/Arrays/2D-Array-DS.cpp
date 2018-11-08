#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    int res, max = -10000;
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    for( int i = 1; i < 5; i++){
        res = 0;
        for( int j = 1; j < 5; j++ ){
            res = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1] + arr[i][j];
            if( res > max )
                max = res;
        }    
    }
    cout << max;
    return 0;
}
