#include "fun.h"
#include "compose.h"
#include <iostream>

using namespace std;

int square(int x) {
  return x*x;
}

int increment(int x) {
  return x + 1;
}

int main() {
  // Conversion from non member function
  Fun<int, int> f(square);
  Fun<int, int> g(increment);

  // Equivalence
  cout << "f(5) = " << f(5) << ", square(5) = " << square(5) << "\n";

  // Composition
  cout << "(f o g)(5) = " << compose(f, g)(5) << ", (g o f)(5) = " << compose(g, f)(5) << "\n";
  
  return 0;
}
