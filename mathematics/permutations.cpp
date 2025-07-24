#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<long long> factorial(21, 1);

void computeFactorials() {
    for (int i = 1; i <= 20; ++i)
        factorial[i] = factorial[i - 1] * i;
}


vector<int> kthPermutation(int n, long long k) {
    vector<int> numbers;
    for (int i = 1; i <= n; ++i)
        numbers.push_back(i);
    
    --k;  // Convert to 0-based
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        long long f = factorial[n - 1 - i];
        int index = k / f;
        result.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);
        k %= f;
    }
    return result;
}

long long permutationRank(int n, const vector<int>& perm) {
    vector<int> numbers;
    for (int i = 1; i <= n; ++i)
        numbers.push_back(i);
    
    long long rank = 1;
    for (int i = 0; i < n; ++i) {
        int pos = find(numbers.begin(), numbers.end(), perm[i]) - numbers.begin();
        rank += pos * factorial[n - 1 - i];
        numbers.erase(numbers.begin() + pos);
    }
    return rank;
}

int main() {
    computeFactorials();
    int t;
    cin >> t;
    while (t--) {
        int type;
        cin >> type;
        if (type == 1) {
            int n;
            long long k;
            cin >> n >> k;
            vector<int> result = kthPermutation(n, k);
            for (int num : result)
                cout << num << " ";
            cout << "\n";
        } else if (type == 2) {
            int n;
            cin >> n;
            vector<int> perm(n);
            for (int i = 0; i < n; ++i)
                cin >> perm[i];
            cout << permutationRank(n, perm) << "\n";
        }
    }
    return 0;
}
