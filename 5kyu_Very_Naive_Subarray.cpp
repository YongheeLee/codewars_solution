//https://www.codewars.com/kata/5988a7747a43212f2e000052

#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cstring>

template<std::size_t S>
int solve(std::array<int, S> a0) {
  std::vector<int> cpy;
  cpy.insert(cpy.end(), a0.begin(), a0.end());

  int cnt = cpy.size();
  for (int i = 2; i <= a0.size(); ++i)
  {
    for (int l = 0; l <= a0.size() - i; ++l)
    {
      std::vector<int> tmp;
      tmp.insert(tmp.begin(), cpy.begin() + l, cpy.begin() + l + i);
      std::sort(tmp.begin(), tmp.end());

      int prev = tmp[0];
      int len = 1;
      for (int e = 1; e < tmp.size(); ++e)
      {
        if (prev == tmp[e])
          len++;
        else
        {
          if (len != 0 && len % 2 == 0)
            break;
          len = 1;
        }

        prev = tmp[e];
      }

      if (len != 0 && len % 2 == 0)
        continue;

      cnt++;
    }
  }

  return cnt;
}
