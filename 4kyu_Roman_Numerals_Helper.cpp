//https://www.codewars.com/kata/51b66044bce5799a7f000003

#include <string>
#include <map>

class RomanHelper{
private:
  std::map<int, std::tuple<std::string, std::string>> cnvtTo = { {1, {"I", "V"}}, {2,{"X", "L"}}, {3, {"C", "D"}}, {4, {"M", "U"}} };
  std::map<char, int> cnvtFrom= { {'I', 1}, {'V',5}, {'X',10} , {'L',50} , {'C',100} , {'D',500} , {'M',1000}, {'0', 0} };
private:
  std::string singleTo(const int& num, const int& digit)
  {
    std::string ret = "";

    int post = num % 5;
    int pre = (num - post) / 5;

    std::tuple<std::string, std::string> tuple = cnvtTo[digit];
    std::tuple< std::string, std::string> next = cnvtTo[digit + 1];

    if (post == 4)
    {
      ret = std::get<0>(tuple) + (pre == 0 ? std::get<1>(tuple) : std::get<0>(next));
    }
    else
    {
      if (pre == 1)
        ret = std::get<1>(tuple);

      for (int i = 0; i < post; ++i)
      {
        ret += std::get<0>(tuple);
      }
    }

    return ret;
  }

  int singleFrom(const char& str, const char& next, bool& skip)
  {
    if (cnvtFrom[str] < cnvtFrom[next])
    {
      skip = true;
      return cnvtFrom[next] - cnvtFrom[str];
    }
    else
    {
      skip = false;
      return cnvtFrom[str];
    }
  }
  public:
    std::string to_roman(unsigned int n){
      std::string sNum = std::to_string(n);
    size_t len = sNum.size();

    std::string ret = "";
    for (int i = 0; i < len; ++i)
    {
      int sglNum = sNum[i] - '0';
      int digit = len - i;
      std::string sub = singleTo(sglNum, digit);
      ret += sub;
    }

    return ret;
    }
  
  int from_roman(std::string sNum)
   {
      size_t len = sNum.size();
    sNum += '0';

    int ret = 0;
    for (int i = 0; i < len; ++i)
    {
      bool skip = true;
      int sub = singleFrom(sNum[i], sNum[i + 1], skip);

      if (skip)
        i++;

      ret += sub;
    }

    return ret;
    }
} RomanNumerals;
