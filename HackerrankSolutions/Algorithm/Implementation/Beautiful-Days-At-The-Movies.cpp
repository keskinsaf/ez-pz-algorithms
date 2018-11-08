#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int reverse(int day, int length){
    int rev = 0, digit = 0;
    for( int i = length-1; i >= 0; i--)
    {
        rev += (day % 10) * (int)pow(10, i);
        day /= 10;
    }
    return rev;
}

int findLen(int number){
    if( number >= pow(10, 6) )
        return 7;
    if( number >= pow(10, 5) )
        return 6;
    if( number >= pow(10, 4) )
        return 5;
    if( number >= pow(10, 3) )
        return 4;
    if( number >= pow(10, 2) )
        return 3;
    if( number >= pow(10, 1) )
        return 2;
    return 1;
}

int beautifulDays(int i, int j, int k) {
    int ctr = 0;
    for( ; i <= j; i++ ){
        if( (int)abs ( i - reverse(i, findLen(i) ) ) % k == 0 )
            ctr++;
    }
    return ctr;
}

int main() {
    int i;
    int j;
    int k;
    cin >> i >> j >> k;
    int result = beautifulDays(i, j, k);
    cout << result << endl;
    return 0;
}
