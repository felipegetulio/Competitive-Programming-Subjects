using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);


int main(){

	char a[9], b[2];
	char c;
	int b1, b2, sum;
	char valid;
	string ans[] = {"invalido", "valido"};

	while(scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, a+1, a+2, &c, a+3, a+4, a+5, &c, a+6, a+7, a+8, &c, b, b+1) != EOF){

		sum = 0;

		for(int i=0; i<9; ++i){
			sum += (a[i]-'0') * (i+1);
		}

		b1 = sum%11;
		b1 = b1 == 10? 0 : b1;

		sum = 0;

		for(int i=0; i<9; ++i){
			sum += (a[i]-'0') * (9-i);
		}
		b2 = sum%11;
		b2 = b2 == 10? 0 : b2;




		valid = b1 == (b[0]-'0') && b2 == (b[1] - '0');

		cout << "CPF " << ans[valid] << endl;
	}


	return 0;
}