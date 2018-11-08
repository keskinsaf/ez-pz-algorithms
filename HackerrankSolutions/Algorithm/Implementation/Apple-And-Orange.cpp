#include <bits/stdc++.h>

using namespace std;

// this function is written by me
bool isInRange( int s, int t, int tr, int val ){//tr is the point of tree
    val = tr + val;
    if( s <= val && val <= t )
        return true;
    return false;
}

vector <int> appleAndOrange(int s, int t, int a, int b, vector <int> apple, vector <int> orange) {
    // below code inside this function is written by me
    std::vector<int> result;
    int ctr = 0;
    for ( int& app : apple ){
        if( isInRange(s, t, a, app) )
            ctr++;
    }
    result.push_back(ctr);
    ctr = 0;
    for ( int& ora : orange ){
        if( isInRange(s, t, b, ora) )
            ctr++;
    }
    result.push_back(ctr);
    return result;
}

int main() {
    int s;
    int t;
    cin >> s >> t;
    int a;
    int b;
    cin >> a >> b;
    int m;
    int n;
    cin >> m >> n;
    vector<int> apple(m);
    for(int apple_i = 0; apple_i < m; apple_i++){
       cin >> apple[apple_i];
    }
    vector<int> orange(n);
    for(int orange_i = 0; orange_i < n; orange_i++){
       cin >> orange[orange_i];
    }
    vector <int> result = appleAndOrange(s, t, a, b, apple, orange);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
