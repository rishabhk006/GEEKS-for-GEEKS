#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int power(int n, int p) {
        long long res = 1;
        long long base = n;
        
        while (p > 0) {
            if (p & 1) {
                res = res * base;
            }
            base = base * base;
            p >>= 1;
        }
        
        return (int)res;
    }

public:
    int reverseExponentiation(int n) {
        int temp = n;
        int rev = 0;
        
        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        
        return power(n, rev);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna