#include <bits/stdc++.h>

using namespace std;

vector < int > solve(vector < int > grades){
    // Completed by me
    for( int &grade : grades ){
        if ( grade > 35 && grade % 5 > 2 )
            grade += (5 - grade % 5);
    }
    return grades;
}

int main() {
    int n;
    cin >> n;
    vector<int> grades(n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       cin >> grades[grades_i];
    }
    vector < int > result = solve(grades);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;
    

    return 0;
}
