#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1; // check if the last bit is set
        n = n >> 1; // right shift by 1 is equivalent to division by 1
    }
    return count;
}


int main() {
    cout << "Number of set bits of " << 31 << " is " << countSetBits(31) << "\n";
    cout << "Number of set bits of " << 42 << " is " << countSetBits(42) << "\n";
    return 0;
}
