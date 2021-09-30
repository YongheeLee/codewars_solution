//https://www.codewars.com/kata/56b5afb4ed1f6d5fb0000991

#include <string>

class RevRot
{
public:
  static std::string revRot(const std::string& strng, unsigned int sz)
  {
    std::string ret("");
    if(sz ==0)
      return ret;

    int c = strng.size() / sz;

    for (int i = 0; i < c; ++i)
    {
      std::string sub = strng.substr(i * sz, sz);
      
      long iV = atol(sub.c_str());

      long sum = 0;

      while (true)
      {
        long res = iV % 10;
        sum += res;
        iV -= res;

        iV /= 10;

        if (iV == 0)
          break;
      }

      if (sum % 2 == 0)
      {
        std::reverse(sub.begin(), sub.end());
        ret += sub;
      }
      else
      {
        std::string tmp = sub.substr(1, sz - 1);
        tmp += sub[0];

        ret += tmp;
      }
    }
        
    return ret;
  }};
