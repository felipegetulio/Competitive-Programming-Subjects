using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1004

int v[MAXN];

int main(){_
    int n, m, k;
    while(cin >> n >> m >> k){
        for(int i=0; i<n; i++)
           cin >> v[i];
        k--;
        k =(k-m%n+n)%n;
        printf("%d\n", v[k]);
    }


    return 0;
}
