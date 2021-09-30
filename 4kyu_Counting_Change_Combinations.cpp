//https://www.codewars.com/kata/541af676b589989aed0009e7

#include <vector>
void substract(const unsigned int money, const std::vector<unsigned int>& coins, int start, std::vector< unsigned int> p, unsigned long long& aa)
{
  for (size_t i = start; i < coins.size(); ++i)
  {
    if (money < coins[i])
      continue;

    if (coins[i] == 1)
    {
      aa++;
      return;
    }

    if (coins[i] == 2)
    {
      if (coins.back() == 1)
      {
        aa += (money / 2) + 1;
        return;
      }
      else
      {
        if (money % 2 != 0)
          return;

        aa++;
        return;
      }
    }

    std::vector <unsigned int> ps(p);
    unsigned int res = money - coins[i];

    {
      ps[i]++;

      if (res == 0)
      {
        aa++;
      }
      else
        substract(res, coins, i, ps, aa);
    }
  }
}

unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
  std::cout << "s "<< money << "\n";
  unsigned long long ret = 1;

  for (size_t i = 0; i < coins.size(); ++i)
  {
    std::cout << coins[i] << "\n";
  }
  
  if(money == 0)
    return 1;

  std::vector<unsigned int> convt;
  convt.insert(convt.begin(), coins.begin(), coins.end());
  std::sort(convt.begin(), convt.end(), std::greater<unsigned int>());

  std::vector<std::vector<unsigned int>> aa;
  unsigned long long tCnt = 0;
  std::vector<unsigned int> c(convt.size(), 0);
  substract(money, convt, 0, c, tCnt);

  return tCnt;
}
