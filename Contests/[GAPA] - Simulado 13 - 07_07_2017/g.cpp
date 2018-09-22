using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define __lcm(a, b) ((a)*((b)/__gcd((a), (b))))

struct Fraction{
	int num, den;

	Fraction operator+(Fraction b){
	    Fraction ans;
		int lcm = __lcm(den, b.den);
		ans.num = num*(lcm/den) + b.num*(lcm/b.den);
		ans.den = lcm;
		return ans;
	}

	Fraction operator-(Fraction b){
	    b.num = -b.num;
	    return *this+b;
	}

	Fraction operator*(Fraction b){
	    Fraction ans;
		ans.num = num*b.num;
		ans.den = den*b.den;
		return ans;
	}

	Fraction operator/(Fraction b){
	    if(b.num != 0){
            b.num^=b.den;
            b.den^=b.num;
            b.num^=b.den;
	    }
	    return *this*b;
	}

	Fraction propperFraction(){
		Fraction a = *this;
		int gcd = __gcd(a.num, a.den);
		a.num /= gcd;
		a.den /= gcd;
		return a;
	}
};

Fraction operation(Fraction a, Fraction b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}

int main(){
    int t;
    Fraction a, b, ans;
    char op;
    scanf("%d", &t);
    while(t--){
        scanf("%d / %d %c %d / %d ", &a.num, &a.den, &op, &b.num, &b.den);
        printf("%d %d %c %d %d\n", a.num, a.den, op, b.num, b.den);
        ans = operation(a, b, op);
        printf("%d/%d = ", ans.num, ans.den);
        ans = ans.propperFraction();
        printf("%d/%d\n", ans.num, ans.den);
    }


    return 0;
}
