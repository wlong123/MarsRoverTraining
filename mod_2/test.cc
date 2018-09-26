#include <iostream>

void foo1(int x) { x++; }

void foo2(int &x) { x++; }

void foo3(int *x) { *x = *x + 1; }

int main()
{
  int x = 5;
  std::cout << x << std::endl;
  foo1(x);
  std::cout << x << std::endl;
  foo2(x);
  std::cout << x << std::endl;
  foo3(&x);
  std::cout << x << std::endl;
}

/* this program outputs:
5
5
6
7

The first output is 5 because it just prints x
The second output is 5 because foo1 does not change the value of x in main. It
just changes the x in the local function.
The third output is 6 because the &x input to foo2 means the memory address of
x is getting passed into the function. The increases the value of the reference
to x which changes x on a global scale.
The fourth output is 7 because *x means a pointer to x is getting passed into 
foo3. The &x means the memory address of x which now contains the value 6 is
getting passed into foo3. So a pointer to the memory address of x is incremented
which causes x to now be 7. 
*/