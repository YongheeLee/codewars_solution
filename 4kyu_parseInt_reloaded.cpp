//https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5

#include <string>

long parse_int(std::string number) {
  std::map<std::string, int> wordMap =
  {
    { "zero", 0 },
    { "one", 1 },
  { "two", 2 },
  { "three", 3 },
  { "four", 4 },
  { "five", 5 },
  { "six", 6 },
  { "seven", 7 },
  { "eight", 8 },
  { "nine", 9 },
  { "ten", 10 },
  { "eleven", 11 },
  { "twelve", 12 },
  { "thirteen", 13 },
  { "fourteen", 14 },
  { "fifteen", 15 },
  { "sixteen", 16 },
  { "seventeen", 17 },
  { "eighteen", 18 },
  { "nineteen", 19 },
  { "twenty", 20 },
  { "thirty", 30 },
  { "forty", 40 },
  { "fifty", 50 },
  { "sixty", 60 },
  { "seventy", 70 },
  { "eighty", 80 },
  { "ninety", 90 },
  { "hundred", 100 },
  { "thousand", 1000 },
  { "million", 1000000 }
  };

  std::vector<std::string> fileds;

  int idx = 0;
  std::string loc;
  while (true)
  {
    if (idx == number.size())
    {
      if (loc.size() != 0)
        fileds.push_back(loc);
      break;
    }

    if ((number[idx] == ' ' || number[idx] == '-') && loc.size() != 0)
    {
      fileds.push_back(loc);
      loc.clear();
    }
    else
      loc += number[idx];

    idx++;
  }

  long ret = 0;

  for (int i = 0; i < fileds.size(); ++i)
  {
    auto it = wordMap.find(fileds[i]);
    if (it == wordMap.end())
      continue;

    int num = it->second;
    if (num == 1000 || num == 1000000)
    {
      ret *= num;
    }
    else if (num == 100)
    {
      int res = ret % 100;
      ret -= res;
      ret += res * 100;
    }
    else
      ret += num;
  }

  return ret;}
