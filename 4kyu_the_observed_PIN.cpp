//https://www.codewars.com/kata/5263c6999e0f40dee200059d

#include <string>
#include <vector>

std::vector<std::string> combination(const std::vector<std::string> &lhs, const std::vector<std::string> &rhs)
{
  std::vector<std::string> ret;

  for (int l = 0; l < lhs.size(); ++l)
  {
    for (int r = 0; r < rhs.size(); ++r)
    {
        ret.push_back(lhs[l] + rhs[r]);
    }
  }

  return ret;
}

std::vector<std::string> get_pins(std::string observed)
{
  if (observed.size() == 0)
    return {};

  std::vector<std::vector<std::string>> pattern = {
      {"0", "8"},
      {"1", "2", "4"},
      {"1", "2", "3", "5"},
      {"2", "3", "6"},
      {"1", "4", "5", "7"},
      {"2", "4", "5", "6", "8"},
      {"3", "5", "6", "9"},
      {"4", "7", "8"},
      {"0", "5", "7", "8", "9"},
      {"6", "8", "9"}};

  std::vector<std::string> ret = pattern[observed[0] - '0'];
  for (int s = 1; s < observed.size(); ++s)
  {
    int num = observed[s] - '0';
    ret = combination(ret, pattern[num]);
  }

  return ret;
}

int main()
{
  std::vector<std::string> output = get_pins("369");

  return 0;
}
