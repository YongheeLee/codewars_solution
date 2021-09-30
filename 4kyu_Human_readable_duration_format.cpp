//https://www.codewars.com/kata/52742f58faf5485cae000b9a

#include <string>

std::vector<std::string> strVal = { "year", "day","hour","minute","second" };
std::vector<int> secVal = { 0, 0, 0, 0, 0 };
std::vector<int> secSz = { 365 * 24 * 60 * 60, 24 * 60 * 60, 60 * 60, 60, 0 };

std::string format_duration(int seconds) {
  if(seconds == 0)
    return "now";
  
  int mSec = 60;
  int hSec = mSec * 60;
  int dSec = hSec * 24;
  int ySec = dSec * 365;

  int validCnt = 0;
  for (int i = 0; i < strVal.size(); ++i)
  {
    secVal[i] = secSz[i] != 0 ? (seconds - (seconds % secSz[i])) / secSz[i] : seconds;
    seconds -= secVal[i] * secSz[i];
    validCnt = secVal[i] > 0 ? validCnt + 1 : validCnt;
  }

  std::string ret;
  int mapCnt = 0;
  for (int i = 0; i < strVal.size(); ++i)
  {
    if (secVal[i] == 0)
      continue;

    ret += std::to_string(secVal[i]) + " " + strVal[i] + (secVal[i] > 1 ? "s" : "");
    mapCnt++;
    if (validCnt != mapCnt && validCnt > 1)
    {
      ret += validCnt - mapCnt == 1 ? " and " : ", ";
    }
  }
  
  return ret;
}
