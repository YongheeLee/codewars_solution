//https://www.codewars.com/kata/54c14c1b86b33df1ff000026

#include <string>
#include <math.h>

class Negabinary {
public:
static std::string ToNegabinary(int i)
  {
    if (i == 0)
      return "0";

  std::cout<<i<<"\n";
        std::string ret;

    int c = 0;
    while (true)
    {
      int exp = pow(-2, c);

      if ((i<0 && i>exp) || (i > 0 && i < exp))
      {
        if (abs(exp - i) > 2*abs(i))
        {
          exp /= 4;
          c -= 2;
        }

        i -= exp;
        break;
      }

      c++;
    }

    int len = c + 1;
    ret.resize(len, '0');
    ret[0] = '1';

    for (int t = 1; t < len; ++t)
    {
      int exp = pow(-2, len - 1 - t);

      if (exp == i)
      {
        ret[t] = '1';
        break;
      }
      
      if (abs(exp - i) > 2 * abs(i))
        continue;

      if (exp * i > 0)
      {
        ret[t] = '1';
        i -= exp;
      }
    }

    return ret;
  }

  static int ToInt(std::string s)
  {
      std::cout << s << "\n";

    size_t len = s.size();
    int ret = 0;
    for (size_t i = 0; i < len; ++i)
    {
      if (s[i] == '0')
        continue;
      
      int exp = len - i - 1;
      ret += pow(-2, exp);
    }
    return ret;
  }
};
