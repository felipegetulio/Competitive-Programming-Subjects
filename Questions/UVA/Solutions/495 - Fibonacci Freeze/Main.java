
import java.math.BigInteger;
import java.util.Scanner;


class Main {
	public static final int MAXN = 5002;
	
	public static BigInteger[] fib;
	
	static void init(){
		fib = new BigInteger[MAXN];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		
		for(int i=2; i<MAXN; i++)
			fib[i] = fib[i-1].add(fib[i-2]);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);		
		int n;
		init();
		while(in.hasNextInt()){
			n = in.nextInt();
			System.out.println("The Fibonacci number for " + n + " is " + fib[n].toString());
		}

		
	}

}
