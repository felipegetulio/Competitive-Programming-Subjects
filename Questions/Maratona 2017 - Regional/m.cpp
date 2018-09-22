using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", min(2*b + 4*c, min(2*a + 2*c, 4*a+2*b)));

	return 0;
}