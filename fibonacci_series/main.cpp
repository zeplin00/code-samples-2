#include <iostream>

using namespace std;

unsigned long long fibonacci(int x)
{
  // Return the xth element in the Fobonacci series
  //
  //
  if (x<2) return x;

  unsigned long long fibnminus2 = 0;
  unsigned long long fibnminus1 = 1;

  // Compute for other values
  //
  //
  unsigned long long fibn = 0;

  for (int i=2; i<=x; i++) {
    fibn = fibnminus1 + fibnminus2;

    // Check for overflow
    //
    if (fibn < fibnminus1) {
      // Overflow
      return 0;  
    }

    fibnminus2 = fibnminus1;
    fibnminus1 = fibn;
  }

  return fibn;
}

int main(int argc, char **argv, char **envp)
{
  cout << "Fib(2) = " << fibonacci(2) << endl;
  cout << "Fib(3) = " << fibonacci(3) << endl;
  cout << "Fib(4) = " << fibonacci(4) << endl;
  cout << "Fib(5) = " << fibonacci(5) << endl;
  cout << "Fib(6) = " << fibonacci(6) << endl;
  cout << "Fib(7) = " << fibonacci(7) << endl;
  cout << "Fib(8) = " << fibonacci(8) << endl;
  cout << "Fib(9) = " << fibonacci(9) << endl;
  cout << "Fib(10) = " << fibonacci(10) << endl;

  cout << "Fib(20) = " << fibonacci(20) << endl;
  cout << "Fib(30) = " << fibonacci(30) << endl;
  cout << "Fib(40) = " << fibonacci(40) << endl;


  cout << "Fib(41) = " << fibonacci(41) << endl;
  cout << "Fib(42) = " << fibonacci(42) << endl;
  cout << "Fib(43) = " << fibonacci(43) << endl;
  cout << "Fib(44) = " << fibonacci(44) << endl;
  cout << "Fib(45) = " << fibonacci(45) << endl;

  cout << "Fib(46) = " << fibonacci(46) << endl;
  cout << "Fib(47) = " << fibonacci(47) << endl;
  cout << "Fib(48) = " << fibonacci(48) << endl;
  cout << "Fib(49) = " << fibonacci(49) << endl;

  cout << "Fib(75) = " << fibonacci(75) << endl;

  cout << "Fib(90) = " << fibonacci(90) << endl;
  cout << "Fib(91) = " << fibonacci(91) << endl;
  cout << "Fib(92) = " << fibonacci(92) << endl;
  cout << "Fib(93) = " << fibonacci(93) << endl;

  cout << "Fib(94) = " << fibonacci(94) << endl;

  cout << "Fib(94) = " << fibonacci(95) << endl;

  cout << "Fib(1000) = " << fibonacci(1000) << endl;

  return(0);
}
