using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define PI 3.14159265
#define v(B, b, h, t) (double)(PI*t*(3*b*h*(b*h + t*(B-b)) + t*t*(B-b)*(B-b))/(3*h*h))


double bb(double B, double b, double h, double l){
    double lo = 0, hi = h, mid;

    for(int i=0; i<25; i++){
        mid = lo + (hi - lo)/2;

        if(v(B, b, h, mid) >= l) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main(){_
    int t, n, l, b, B, h;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &l);
        scanf("%d%d%d", &b, &B, &h);
        printf("%.2lf\n", bb(B, b, h, l/(1.0*n)));
    }



    return 0;
}
