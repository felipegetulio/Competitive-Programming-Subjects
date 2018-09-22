using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ull unsigned long long

int qntBits(ull n){
    int cont = 0;
    while(n){
        cont += (n&1);
        n >>= 1;
    }
    return cont;
}

int main(){
    ull a, b;

    while(scanf("%llu%llu", &a, &b) && (a || b)){
        printf("%d\n", qntBits(a^b));
    }


    return 0;
}
