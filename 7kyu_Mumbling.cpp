//https://www.codewars.com/kata/5667e8f4e3f572a8f2000039

class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string& s)
{
  std::string ret;

  for (int i = 0; i < s.size(); ++i)
  {
    char upper = std::toupper(s[i]);
    char lower = std::tolower(s[i]);

    if (i != 0)
      ret += "-";

    ret += upper;

    for (int j = 0; j < i; j++)
    {
      ret += lower;
    }

    
  }

  return ret;
}
