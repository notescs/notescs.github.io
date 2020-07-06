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


int main() {
    cout << "Number of set bits of " << 31 << " is " << countSetBits(31) << "\n";
    cout << "Number of set bits of " << 42 << " is " << countSetBits(42) << "\n";
    return 0;
}
