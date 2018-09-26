/**
 * Effect: applies the function f to each element in vec,
 * replaces the old value in vec with the new one.
 * @param vec the vector to operate on
 * @param f the function to apply
 * @tparam T the type of elements in the vector
 */
#include <vector>
#include <iostream>
#include <functional>

template <typename T>
void map(std::vector<T> &vec, T (*f)(T))
{
  // for (auto &i : vec)
  // {
  //   i = f(i);
  // }
  std::function<T(T)> func = f;
  for (auto &i : vec)
  {
    i = f(i);
  }
}
// T is the template argument.You can call your function like so :

int triple(int x)
{
  return x * 3;
}
int main()
{
  std::vector<int> vec = {1, 2, 3};
  // map<int>(vec, triple);
  map<int>(vec, [](int x) { return x * 3; });
  for (const auto &i : vec)
  {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

/*
Java's approach to generics does not work in c++ because templates in c++
are higher order and can take anything in as values (including functions). 
Because of this, you cannot just cast T to a function at compile time. 
*/

/*
template <typename T, typename F>
void map(std::vector<T>& vec, F f);

This approach is much easier to read and abstracts out a lot of the logic unlike
the other approach. This approach is also more ambiguous as to what f is. 
Therefore, users looking at the function declaration might not understand what
f is. F is of type template so anything can be put in as f. So for map to 
work with the intended functionality, the input for f must be a function.

*/