//https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1

#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}
4 months agoRefactor
size_t duplicateCount(const std::string& in);
  
size_t duplicateCount(const char* in)
{
  std::string test(in);
  for (size_t i = 0; i < test.size(); ++i)
  {
    test[i] = toupper(test[i]);
  }

  std::sort(test.begin(), test.end());

  char prev = test[0];
  bool issame = false;
  size_t cnt = 0;
  for (size_t i = 1; i < test.size(); ++i)
  {
    if (test[i] == prev)
    {
      if (issame == false)
      {
        issame = true;
        cnt++;
      }

    }
    else
    {
      issame = false;
    }

    prev = test[i];
  }

  return cnt;
}
