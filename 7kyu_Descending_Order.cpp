//https://www.codewars.com/kata/5467e4d82edf8bbf40000155

#include <cinttypes>

uint64_t descendingOrder(uint64_t a)
{
  std::string str = std::to_string(a);
  std::sort(str.begin(), str.end(), std::greater<>());

  uint64_t ret = 0;
  uint64_t degree = 1;
  for (int i = str.size()-1; i >=0; --i)
  {
    ret += (str[i] - '0') * degree;
    degree *= 10;
  }

  return ret;
}
