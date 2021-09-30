//https://www.codewars.com/kata/58dea43ff98a7e2124000169

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Compare
{
  larger = 0,
  same = 1,
  smaller = 2,
};

Compare isLarger(string a, string b)
{
  size_t sz = max(a.size(), b.size());
  if (a.size() < sz)
  {
    a.insert(0, sz - a.size(), '0');
  }
  else if (b.size() < sz)
  {
    b.insert(0, sz - b.size(), '0');
  }

  for (int i = 0; i < sz; ++i)
  {
    int ai = a[i] - '0';
    int bi = b[i] - '0';

    if (ai < bi)
    {
      return Compare::smaller;
    }
    else if (ai > bi)
    {
      return Compare::larger;
    }
  }

  return Compare::same;
}

string string_sub(string a, string b)
{
  size_t sz = max(a.size(), b.size());
  if (a.size() < sz)
  {
    a.insert(0, sz - a.size(), '0');
  }
  else if (b.size() < sz)
  {
    b.insert(0, sz - b.size(), '0');
  }

  bool isMinus = false;
  string big, sml;

  for (int i = 0; i < sz; ++i)
  {
    int ai = a[i] - '0';
    int bi = b[i] - '0';

    if (ai < bi)
    {
      isMinus = true;
      break;
    }
    else if (ai > bi)
    {
      isMinus = false;
      break;
    }
  }

  big = isMinus ? b : a;
  sml = isMinus ? a : b;

  string ret;
  ret.resize(sz, '0');

  int r = 0;
  for (int i = sz - 1; i >= 0; --i)
  {
    int ai = big[i] - '0';
    int bi = sml[i] - '0';

    int cal = ai - bi - r;

    if (cal < 0)
    {
      ret[i] = '0' + (10 + cal);
      r = 1;
    }
    else
    {
      ret[i] = '0' + cal;
      r = 0;
    }
  }

  while (true)
  {
    if (ret[0] == '0')
      ret.erase(ret.begin());
    else
      break;
  }

  if (isMinus)
    ret.insert(0, 1, '-');

  if (ret.size() == 0)
    ret = "0";

  return ret;
}

vector<string> divide_strings(string a, string b) {

  if (isLarger(a, b) == Compare::smaller)
    return { "0", a };

  string ret;

  int dg = 0;
  int i = 0;
  while (true)
  {
    string sub = a.substr(0, b.size() + dg);
    string res = a.substr(b.size() + dg, a.size() - b.size() - dg);

    if (isLarger(b, sub) == Compare::larger)
    {
      dg++;

      continue;
    }

    int c = 0;
    while (true)
    {
      sub = string_sub(sub, b);
      c++;

      if (isLarger(sub, b) == Compare::smaller)
        break;
    }

    a = sub + res;
    dg = sub.size() == b.size() ? 1 : 0;

    if (ret.size() == 0)
    {
      ret.resize(res.size() + 1, '0');
      i = res.size() + 1;
    }

    ret[i - res.size() - 1] = c + '0';

    if (isLarger(b, a) == Compare::larger)
      break;
  }

  while (true)
  {
    if (ret[0] == '0')
      ret.erase(ret.begin());
    else
      break;
  }

  while (true)
  {
    if (a.size() == 1)
      break;

    if (a[0] == '0')
      a.erase(a.begin());
    else
      break;
  }

  return { ret, a };
}
