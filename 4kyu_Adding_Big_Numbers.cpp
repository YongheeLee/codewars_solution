//https://www.codewars.com/kata/525f4206b73515bffb000b21

#include <string>
#include <math.h>

std::string add(const std::string& a, const std::string& b) {
  size_t sz = std::max(a.size(), b.size());

  std::string acopy(a);
  std::string bcopy(b);

  std::string zero;
  if (acopy.size() < sz)
  {
    zero.resize(sz - acopy.size(), '0');
    acopy = zero + acopy;
  }
  else if (b.size() < sz)
  {
    zero.resize(sz - bcopy.size(), '0');
    bcopy = zero + bcopy;
  }

  std::string ret;
  ret.resize(sz, '0');

  int r = 0;
  for (int i = sz - 1; i >= 0; --i)
  {
    int ai = acopy[i] - '0';
    int bi = bcopy[i] - '0';

    int cal = ai + bi + r;
    if (cal > 9)
    {
      r = 1;
      ret[i] = '0' + (cal % 10);
    }
    else
    {
      r = 0;
      ret[i] = '0' + cal;
    }
  }

  if (r == 1)
  {
    ret = "1" + ret;
  }

  return ret;
}
