fib = [0, 1]

for i in range(2, 6000):
   fib.append(fib[i-1] + fib[i-2])

n = input()
while(n!=""):
   print("The Fibonacci number for " + n + " is " + str(fib[int(n)]))
   n = input()