#include "fun.h"
#include "partial.h"
#include "compose.h"
#include <iostream>

using namespace std;

int square(int x) {
  return x*x;
}

int increment(int x) {
  return x + 1;
}

int add(int x, int y) {
  return x + y;
}

int main() {
  // Conversion from non member function
  Fun<int, int> f(square);
  Fun<int, int> g(increment);
  Fun2<int, int, int> h(add);

  // Equivalence
  cout << "f(5) = " << f(5) << ", square(5) = " << square(5) << "\n";

  // Composition
  cout << "(f o g)(5) = " << compose(f, g)(5) << ", (g o f)(5) = " << compose(g, f)(5) << "\n";

  // Partial Application
  cout << "h(1)(2) = " << h(1)(2) << ", increment(2) = " << increment(2) << "\n";

  // Composition and partial application
  cout << "(h(2) o f)(2) = " << compose(h(2), f)(2) << "\n";
  
  return 0;
}
