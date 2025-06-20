#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1e6 + 1;
int freq[MAX_VAL];

int main() {
    int n, x;
    cin >> n;

    // Count the frequency of each number
    for (int i = 0; i < n; i++) {
        cin >> x;
        freq[x]++;
    }

    // Check from the largest possible GCD down to 1
    for (int i = MAX_VAL - 1; i >= 1; i--) {
        int count = 0;
        // Count how many numbers in the array are divisible by i
        for (int j = i; j < MAX_VAL; j += i) {
            count += freq[j];
        }
        if (count >= 2) {
            cout << i << endl;
            return 0;
        }
    }
}
