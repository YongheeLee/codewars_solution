//https://www.codewars.com/kata/54d496788776e49e6b00052f

#include <string>
#include <vector>
#include <set>
#include <math.h>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst)
        {
    std::set<int> pFAll;
    std::vector<std::set<int>> pFList;
    
      for(int i = 0 ; i< lst.size();++i)
        {
        std::cout<< lst[i]<<", ";
      }
    for (int i = 0; i < lst.size(); ++i)
    {
      int val = fabs(lst[i]);
      std::set<int> pF;
      int a = 2;
      while (true)
      {
        if (val % a == 0)
        {
          pF.insert(a);
          val /= a;
        }
        else
        {
          a++;
        }

        if ((double)a > (double)val)
        {
          if (fabs(val) != 1)
            pF.insert(val);

          break;
        }
      }

      pFList.push_back(pF);
      pFAll.insert(pF.begin(), pF.end());
    }

    std::vector<int> pFs;
    pFs.insert(pFs.end(), pFAll.begin(), pFAll.end());
    std::sort(pFs.begin(), pFs.end());

    std::string ret;
    for (auto it = pFAll.begin(); it != pFAll.end(); ++it)
    {
      int sum = 0;
      for (int i = 0; i < lst.size(); ++i)
      {
        if (lst[i] % (*it) == 0)
        {
          sum += lst[i];
        }
      }

      ret += "(" + std::to_string(*it) + " " + std::to_string(sum) + ")";

    }

    return ret;
  }
};
