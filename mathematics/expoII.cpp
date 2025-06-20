#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int N;
ll A, B, C;

ll fastpow(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b&1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    scanf("%d", &N);
    int input1[N], input2[N], input3[N];
    for(int i = 0; i < N; i++){
        scanf("%lld %lld %lld", &A, &B, &C);
        input1[i] = A;
        input2[i] = B;
        input3[i] = C;
    }
    for(int i = 0;i<N;i++){
        printf("%lld \n" , fastpow(input1[i],fastpow(input2[i],input3[i],MOD-1), MOD));
    }
}