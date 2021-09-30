//https://www.codewars.com/kata/5672682212c8ecf83e000050

#include <cstring>

class DoubleLinear
{
public:
    static int dblLinear(int n)
      {
    int refSz = 4;
    bool* c = (bool*)calloc(refSz, sizeof(bool));

    c[1] = true;

    int i = 2;
    int cnt = 0;
    while (true)
    {
      int m2 = (i - 1) % 2;
      int m3 = (i - 1) % 3;
      int a2 = 0, a3 = 0;

      if (m2 == 0)
      {
        a2 = (i - 1) / 2;
      }

      if (m3 == 0)
      {
        a3 = (i - 1) / 3;
      }

      if ((a2 != 0 && c[a2])|| (a3 != 0 && c[a3]))
      {
        c[i] = true;
        cnt++;
      }

      if (cnt == n)
        break;

      i++;

      if (i == refSz)
      {
        refSz *= 10;
        bool* nc = (bool*)calloc(refSz, sizeof(bool));
        std::memcpy(nc, c, (refSz / 10) * sizeof(bool));
        std::swap(c, nc);
        free(nc);
      }
    }

    return i;
    }
};
