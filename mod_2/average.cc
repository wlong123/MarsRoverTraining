#include <iostream>
#include <vector>
#include <numeric>

double average(const std::vector<int> &vec)
{
  double output = 0.0;
  int size = vec.size();
  // for (int i = 0; i < size; i++)
  // {
  //   output += vec.at(i);
  // }
  // for (const int &i : vec)
  // {
  //   output += i;
  // }
  output = std::accumulate(vec.begin(), vec.end(), 0);
  return output / size;
}

int main()
{
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);

  std::cout << average(nums) << std::endl;
}
