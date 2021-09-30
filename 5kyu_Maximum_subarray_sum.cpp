//https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c

#include <vector>

int maxSequence(const std::vector<int>& arr) {
  if (arr.size() == 0)
    return 0;

  int sum = 0;
  for (size_t i = 0; i < arr.size(); ++i)
  {
    sum += arr[i];
  }

  for (size_t i = 0; i < arr.size(); ++i)
  {
    for (size_t j = arr.size()-1; j > i; --j)
    {
      int sr = 0;
      for (size_t s = i; s <= j; ++s)
      {
        sr += arr[s];
      }

      if (sr > sum)
        sum = sr;
    }
  }

  return sum > 0 ? sum : 0;
}
