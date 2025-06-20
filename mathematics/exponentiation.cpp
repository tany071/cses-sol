#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int N;
ll A, B;

ll fastpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    scanf("%d", &N);
    int input1[N], input2[N];
    for(int i = 0; i < N; i++){
        scanf("%lld %lld", &A, &B);
        input1[i] = A;
        input2[i] = B;
        // printf("%lld\n", fastpow(A, B));
    }
    for(int i = 0;i<N;i++){
        printf("%lld \n" , fastpow(input1[i],input2[i]));
    }
}