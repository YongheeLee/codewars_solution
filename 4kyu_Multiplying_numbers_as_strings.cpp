//https://www.codewars.com/kata/55911ef14065454c75000062

#include <iostream>
#include <string>

using namespace std;

string multiply(string a, string b) {
  size_t subSz = 4;
  std::vector<string> subA;
  std::vector<string> subB;

  size_t i = a.size();
  while (true)
  {
    if (i < subSz)
    {
      if (i != 0)
        subA.push_back(a.substr(0, i));
      break;
    }
    
    subA.push_back(a.substr(i - subSz, subSz));
    i -= subSz;
  }

  i = b.size();
  while (true)
  {
    if (i < subSz)
    {
      if (i != 0)
        subB.push_back(b.substr(0, i));
      break;
    }

    subB.push_back(b.substr(i - subSz, subSz));
    i -= subSz;
  }

  size_t deg = subA.size() - 1 + subB.size() - 1;

  std::vector<int> p;

  int added = 0;
  int n = 10000;

  for (size_t d = 0; d <= deg; ++d)
  {
    size_t e1 = 0;
    size_t e2 = d - e1;

    int iR = added;
    added = 0;

    while (true)
    {
      if (e1 >= 0 && e1 < subA.size() && e2 >= 0 && e2 < subB.size())
      {
        int iA = atoi(subA[e1].c_str());
        int iB = atoi(subB[e2].c_str());
        iR += iA * iB;
      }
      
      if(e2==0)
        break;

      e1++;
      e2 = d - e1;
    }
    
    int res = iR % n;
    added = (iR - res) / n;

    p.push_back(res);
  }
  
  if(added != 0)
    p.push_back(added);

  std::string ret;
  for (int i = p.size() - 1; i >= 0; --i)
  {
    std::string b = to_string(p[i]);

    if (i != p.size() - 1)
    {
      while (b.size() != 4)
      {
        b = "0" + b;
      }
    }

    ret += b;
  }

  int start = 0;
  for (int i = 0; i < ret.size(); ++i)
  {
    if (ret[i] != '0')
    {
      start = i;
      break;
    }
  }

  return ret.substr(start, ret.size() - start);
}
