//https://www.codewars.com/kata/56541980fa08ab47a0000040

class Printer
{
public:
    static std::string printerError(const std::string &s)
      {
          int t = s.size();
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] > 'm')
        cnt++;
    }

    char buf[100];
    sprintf(buf, "%d/%d", cnt, t);

    return std::string(buf);
    }
};
