#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // clear the right-most bit
        ++count;
    }
    return count;
}

int countDifferntBits(int a, int b) {
    return countSetBits(a ^ b);
}

int main() {
    cout << "Number of different bits of " << 19 << " and " << 10 << " is " << countDifferntBits(19, 10) << "\n";
    return 0;
}
