#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    cin >> N;
    string b;
    vector<string> a;
    for( int i = 0; i < N; i++ ){
        cin >> b;
        a.push_back(b);
    }
    cin >> Q;
    for( int i = 0; i < Q; i++ ){
        cin >> b;
        cout << count( a.begin(), a.begin() + N , b ) << endl;
    }
    return 0;
}
