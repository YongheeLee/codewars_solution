//https://www.codewars.com/kata/56c04261c3fcf33f2d000534

#include <math.h>

class Magnets
{
public:
  static double unit(int k, int n)
  {
    double t = log(double(k)) + 2.0 * double(k) * log(double(n) + 1.0);
    t = exp(t);

    return 1.0 / t;
  }

  static double doubles(int maxk, int maxn)
  {
    std::cout<< maxk << " " << maxn << " "<<"\n";
    double sum = 0.0;
    for (int k = 1; k <= maxk; ++k)
    {
      for (int n = 1; n <= maxn; ++n)
      {
        sum += unit(k, n);
      }
    }

    return sum;
  }
};
