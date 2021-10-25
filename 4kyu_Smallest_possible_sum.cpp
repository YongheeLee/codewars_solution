//https://www.codewars.com/kata/52f677797c461daaf7000740

#include <vector>

unsigned long long solution(const std::vector<unsigned long long>& arr) {

  std::vector<unsigned long long> cpy(arr);
  std::sort(cpy.begin(), cpy.end());

    unsigned long long min = cpy.back();
  unsigned long long divide = cpy.front();

  while (true)
  {
    bool transformed = false;
    int b = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
      unsigned long long mod = cpy[i] % divide;
      if (mod == 0)
        continue;

      if (mod < min)
      {
        min = mod;
        transformed = true;
      }
    }

    if (transformed == false)
      break;

    divide = min;
  }
  

  return divide * arr.size();
  }
