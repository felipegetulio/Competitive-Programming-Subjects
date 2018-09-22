using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define uint64 unsigned long long
#define MAXN 104




struct BitSet100{
	uint64 a, b;

    BitSet100 operator&(const BitSet100 bit)const{
    	BitSet100 aux;
    	aux.a = a & bit.a;
    	aux.b = b & bit.b;
    	return aux;
    }

    BitSet100 operator~()const{
    	BitSet100 aux = *this;
    	aux.a = ~aux.a;
    	aux.b = ~aux.b;
    	return aux;
    }

    char operator[] (char index){
		if(index < 64) return (a & (1ULL << index)) == 0 ? 0 : 1;
		return (b & (1ULL << (index - 64))) == 0 ? 0 : 1;
    }

	BitSet100(){
		reset();
	}

	void reset(){
		a = b = 0;
	}

	void set(){
		a = b = -1;
	}

	void changeBit(char index, char value){

		if(value == 0){
			if(index < 64) a &= ~(1ULL << index);
			else b &= ~(1ULL << (index - 64));
		}
		else{
			if(index < 64) a |= (1ULL << index);
			else b |= (1ULL << (index - 64));
		}
	}

	
    int count(){
    	int count = 0;
		int a = this->a;
		int b = this->b;

		while(a){
			a-=a&-a;
			++count;
		}

		while(b){
			b-=b&-b;
			++count;
		}
		return count;
    }

};




int main(){_
	BitSet100 a;

	uint64 s = 0;

	for(int i=0; i<10; ++i)
		a.changeBit(i, 1);

	a.changeBit(2, 0);
	a.changeBit(7, 0);

	for(int i=0; i<101; ++i)
		cout << (a[i] == 0 ? 0 : 1);


	cout << a.count() << endl;

	a = ~a;
	cout << endl;

	for(int i=0; i<101; ++i)
		cout << (a[i] == 0 ? 0 : 1);

	cout << endl;

	return 0;
}