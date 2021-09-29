//https://www.codewars.com/kata/51ba717bb08c1cd60f00002f

#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {

  std::vector<std::vector<int>> ext;
  ext.push_back(std::vector<int>());
  int cnt = 0;
  ext[cnt].push_back(args[0]);
  for (int i = 1; i < args.size(); ++i)
  {
    if (ext[cnt].back() == args[i] - 1)
    {
      ext[cnt].push_back(args[i]);
    }
    else
    {
      if (ext[cnt].size() == 2)
      {
        ext.push_back(std::vector<int>());
        cnt++;
        ext[cnt].push_back(ext[cnt - 1].back());
        ext[cnt - 1].pop_back();
      }

      ext.push_back(std::vector<int>());
      cnt++;
      ext[cnt].push_back(args[i]);
    }
  }

  if (ext[cnt].size() == 2)
  {
    ext.push_back(std::vector<int>());
    cnt++;
    ext[cnt].push_back(ext[cnt - 1].back());
    ext[cnt - 1].pop_back();
  }

  std::string ret;
  for (int i = 0; i < ext.size(); ++i)
  {
    if (ext[i].size() > 2)
    {
      ret += std::to_string(ext[i].front()) + "-" + std::to_string(ext[i].back()) + ",";
    }
    else
    {
      ret += std::to_string(ext[i][0]) + ",";
    }
  }

  ret = ret.substr(0, ret.size() - 1);
  return ret;
}
