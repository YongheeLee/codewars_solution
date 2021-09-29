//https://www.codewars.com/kata/5254ca2719453dcc0b00027d

#include <string>
#include <vector>

void getNext(const std::string& ex, const std::string& s, std::map<std::string, bool>& map)
{
  int sz = s.size();
  map.insert(std::make_pair(ex + s, true));

  if (sz == 2)
  {
    std::string tmp(s);
    if (tmp[0] != tmp[1])
    {
      std::swap(tmp[0], tmp[1]);
      map.insert(std::make_pair(ex + tmp, true));
    }

    return;
  }
  else
  {
    for (int i = 0; i < sz; ++i)
    {
      std::string tmp(s);
      tmp.erase(tmp.begin() + i);

      getNext(ex + s[i], tmp, map);
    }
  }
  
}

std::vector<std::string> permutations(std::string s) {
  int sz = s.size();
  std::sort(s.begin(), s.end());
  if (sz == 1)
    return { s };

  std::map<std::string, bool> map;
  getNext("", s, map);

  std::vector<std::string> ret;
  
  for (auto it = map.begin(); it != map.end(); ++it)
  {
    ret.push_back(it->first);
  }

  return ret;
}
