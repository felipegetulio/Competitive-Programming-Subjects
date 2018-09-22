using namespace std;
#include<cstdio>
#define uint64 unsigned long long
#define MAXN 102

struct TVector{
	int x, y;

	TVector(){}
   	TVector(int _x, int _y):x(_x), y(_y){}
 
    TVector operator+(const TVector& p)const{ return TVector(x+p.x, y+p.y);}
   	TVector operator-(const TVector& p)const{ return TVector(x-p.x, y-p.y);}
   	int operator*(const TVector& p)const{ return x*p.x + y*p.y;}
   	int operator%(const TVector& p)const{ return x*p.y - y*p.x;}
};


struct BitSet100{
	uint64 a, b;


	BitSet100(){ reset(); }

    BitSet100 operator&(const BitSet100& bit)const{
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

	void reset(){
		a = b = 0;
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
	
    int count(int n){
    	int count = 0;
		uint64 a = this->a;
		uint64 b = this->b;
		uint64 ind;
		int ans[] = {63, n-1};

		if(n > 64){
			while(b){
				ind = b&-b;
				count += (ind <= (1ULL << (n - 65)));
				b -= ind;
			}
		}

		while(a){
			ind = a&-a;
			count += (ind <= (1ULL << ans[n <= 64]));
			a -= ind;
		}
		
		return count;
    }
};


BitSet100 mask[MAXN][MAXN];
TVector bp[MAXN], wp[MAXN];

int main(){
	int n, m;
	TVector vij, vik, vjk;
	BitSet100 intersection;

	int qnt;
	uint64 ans;

	while(scanf("%d %d", &n, &m) != EOF){
		ans = 0;

		for(int i=0; i<n; ++i){
			scanf("%d %d", &bp[i].x, &bp[i].y);
		}

		for(int i=0; i<m; ++i){
			scanf("%d %d", &wp[i].x, &wp[i].y);
		}

		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				mask[i][j].reset();
				vij = bp[j] - bp[i];

				for(int k=0; k<m; ++k){
					vik = wp[k] - bp[i];
					mask[i][j].changeBit(k, (vij % vik) < 0);
				}
			}
		}

		for(int i=0; i<n-2; ++i){
			for(int j=i+1; j<n-1; ++j){
				vij = bp[j] - bp[i];

				for(int k=j+1; k<n; ++k){
					vik = bp[k] - bp[i];
					vjk = bp[k] - bp[j];

					if(vij % vik > 0){
						intersection = ~mask[i][j] & mask[i][k] & ~mask[j][k];
					}
					else{
						intersection = mask[i][j] & ~mask[i][k] & mask[j][k];
					}
					
					qnt = intersection.count(m);
					ans += qnt * qnt;
				}
			}
		}

		printf("%lld\n", ans);
	}


	return 0;
}