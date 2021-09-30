//https://www.codewars.com/kata/515de9ae9dcfc28eb6000001

#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
  std::vector<std::string> ret;
  int idx = 0;
  
  if(s.size()==0)
    return ret;
  
  while (true)
  {
    if (idx + 2 > s.size())
    {
      ret.push_back(s.substr(idx, 1) + "_");
      break;
    }
    else
      ret.push_back(s.substr(idx, 2));
    
    idx += 2;
    
    if (idx >= s.size())
      break;
  }
  return ret;}
