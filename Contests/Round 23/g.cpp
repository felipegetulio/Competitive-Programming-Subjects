using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 104
#define int64 long long

struct Point{
	int x, y;
};

struct Triangle{
	Point a, b, c;

	Triangle(){}

	Triangle(Point a, Point b, Point c){
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

struct Vector{
	int x, y;	
};


Point blackPoints[MAXN], whitePoints[MAXN];


Vector toVector(Point a, Point b){
	Vector v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	return v;
}

int crossProduct(Vector a, Vector b){
	return a.x * b.y - b.x * a.y;
}

char signOf(int n){
	if(n < 0) return -1;
	return 1;
}

char inTriangle(Point p, Triangle t){
	Vector ab, bc, ca, ap, bp, cp;
	int cross1, cross2, cross3;

	ab = toVector(t.a, t.b);
	bc = toVector(t.b, t.c);
	ca = toVector(t.c, t.a);
	ap = toVector(t.a, p);
	bp = toVector(t.b, p);
	cp = toVector(t.c, p);

	
	cross1 = crossProduct(ab, ap);
	cross2 = crossProduct(bc, bp);
	cross3 = crossProduct(ca, cp);

	return signOf(cross1) == signOf(cross2) && signOf(cross2) == signOf(cross3);
}


int main(){_

	int n, m;
	Triangle t;
	int64 ans, inside;


	while(cin >> n >> m){

		ans = 0;

		for(int i=0; i<n; ++i)
			cin >> blackPoints[i].x >> blackPoints[i].y;

		for(int i=0; i<m; ++i)
			cin >> whitePoints[i].x >> whitePoints[i].y;

		for(int i=0; i<n-2; ++i)
			for(int j=i+1; j<n-1; ++j)
				for(int k=j+1; k<n; ++k){
					t = Triangle(blackPoints[i], blackPoints[j], blackPoints[k]);
					inside = 0;
					for(int l=0; l<m; ++l){
						inside += inTriangle(whitePoints[l], t);
					}
					ans += inside * inside;
				}

		cout << ans << endl;
	}



	return 0;
}