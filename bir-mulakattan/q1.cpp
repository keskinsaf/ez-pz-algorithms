#include <iostream>
#include <numeric>

// program for finding least common multiply of the numbers less than input

int gcd(int a, int b){  // Euclidian gcd
    while(true){
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}

int lcm(int a, int b){
    int temp = gcd(a, b);   // find greatest common divisor
    //std::cout << "gcd of a: " << a << " and b: " <<b << "is: " << temp << '\n';
    return temp ? (a / temp * b) : 0;   // divide one number with gcd of two values,
                // then multiply it with other one
}

int main(int argc, char const *argv[]) {
    long number, result = 1;
    std::cin >> number;
    if ( number == 0 ) {
        std::cout << 0 << '\n';
        return 0;
    }
    for (long i = 2; i <= number; i++) {
        result = lcm(result, i);
    }
    std::cout << result << '\n';
    return 0;
}
