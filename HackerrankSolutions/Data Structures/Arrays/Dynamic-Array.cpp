#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<int>> seqList;
    int lastAnswer = 0, N, Q, type, x, y, sex;
    cin >> N >> Q;
    seqList.resize(N);
    for( int i = 0; i < Q; i++){
        cin >> type >> x >> y;
        sex = ( x ^ lastAnswer ) % N;
        if( type == 1 )
            seqList[sex].push_back(y);
        else{
            lastAnswer = seqList[sex][y % seqList[sex].size()];
            cout << lastAnswer << endl;
        }
    }
    return 0;
}
