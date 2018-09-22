using namespace std;
#include<bits/stdc++.h>
#define ll long long

int main(){
    ll n;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", (1LL<<n)-1);
    }


    return 0;
}
