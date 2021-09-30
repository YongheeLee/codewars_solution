//https://www.codewars.com/kata/5629db57620258aa9d000014

class Mix
{
public:
  static std::string mix(const std::string &s1, const std::string &s2)
    {
            struct item
    {
      std::string str;
      int id;
    };

    std::vector<std::string> s = { s1, s2 };
    std::vector<item> total;

    for (int i = 0; i < 2; ++i) {
      std::sort(s[i].begin(), s[i].end());

      char prev = s[i][0];
      std::string p;
      for (int a = 1; a < s[i].size(); ++a)
      {
        if (s[i][a] >= 'a' && s[i][a] <= 'z')
        {
          if (s[i][a] == prev)
            p += s[i][a];
          else
          {
            if (p.size() > 1)
            {
              item itm;
              itm.id = i + 1;
              itm.str = p;

              total.push_back(itm);
            }
            
            p = s[i][a];
          }
        }

        prev = s[i][a];
      }

      if (p.size() >1)
      {
        item itm;
        itm.id = i + 1;
        itm.str = p;

        total.push_back(itm);
      }
    }

    for (auto it1 = total.begin(); it1 != total.end(); ++it1)
    {
      for (auto it2 = total.begin() + 1; it2 != total.end(); ++it2)
      {
        if (it1->id != it2->id && it1->str == it2->str)
        {
          it1->id = 3;
          it2->id = 4;
        }

        if (it1->str.size() != it2->str.size() && it1->str[0] == it2->str[0])
        {
          if (it1->str.size() > it2->str.size())
            it2->id = 3;
          else
            it1->id = 3;
        }
      }
    }

    std::sort(total.begin(), total.end(),
      [&](const item& lhs, const item& rhs) -> bool
      {
        if (lhs.str.size() != rhs.str.size())
          return lhs.str.size() > rhs.str.size();
        else
        {
          int lhId = lhs.id;
          int rhId = rhs.id;
          char lhVa = lhs.str[0];
          char rhVa = rhs.str[0];

          if (lhId == rhId)
          {
            return lhVa < rhVa;
          }
          else
          {
            return lhId < rhId;
          }
        }
      });

    std::string ret;
    for (size_t i = 0; i < total.size(); ++i)
    {
      int id = total[i].id;

      if(id == 3)
        continue;
      else if (id == 4)
      {
        ret += "=:" + total[i].str + "/";
      }
      else
      {
        ret += std::to_string(id) + ":" + total[i].str + "/";
      }
    }

    return ret.substr(0, ret.size() - 1);
  }
};
