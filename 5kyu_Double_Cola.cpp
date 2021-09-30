//https://www.codewars.com/kata/551dd1f424b7a4cdae0001f0

#include <string>
#include <vector>
#include <math.h>

std::string who_is_next(const std::vector<std::string>& names, long long r) {

  int pCnt = names.size();



  int ref = 1;
  while (true)
  {
    int cnt = pCnt * (pow(2, ref) - 1);
    if (cnt >= r)
      break;

    ref++;
  }

  ref--;
  int sub = pow(2, ref);
  r -= pCnt * (sub - 1);

  for (int i = 0; i < pCnt; ++i)
  {
    r -= sub;
    if (r <= 0)
      return names[i];
  }
}
