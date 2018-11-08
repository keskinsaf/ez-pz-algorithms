#include <bits/stdc++.h>
#include <string>
using namespace std;

string solve(int year){
    if(year < 1918){
        if( year % 4 == 0 )
            return string("12.09.") + to_string(year);
        else
            return string("13.09.") + to_string(year);
    }else if(year == 1918){
        return string("26.09.") + to_string(1918);
    }
    else{
        if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0) )
            return string("12.09.") + to_string(year);
        else
            return string("13.09.") + to_string(year);
    }
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
