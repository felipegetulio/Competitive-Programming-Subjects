using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define __lcm(a, b) ((a)*((b)/__gcd((a), (b))))

int main(){
    int n, a, b, ans;
    while(scanf("%d%d%d", &n, &a, &b) && (n||a||b)){
        ans = n/a + n/b - n/__lcm(a, b);
        printf("%d\n", ans);
    }


    return 0;
}
