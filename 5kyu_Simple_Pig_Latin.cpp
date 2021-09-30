//https://www.codewars.com/kata/520b9d2ad5c005041100000f

std::string pig_it(std::string str)
{
  std::vector<std::string> fields;
  std::string sub;
  for (size_t i = 0; i < str.size(); ++i)
  {
    if (str[i] == ' ')
    {
      
      std::string temp;
      size_t sz = sub.size();
      if (sz == 0)
        continue;

      if ((sub[0] >= 'a' && sub[0] <= 'z') || (sub[0] >= 'A' && sub[0] <= 'Z'))
      {
        temp = sub.substr(1, sz - 1) + sub[0];
        temp += "ay";
      }
      else
        temp = sub;

      fields.push_back(temp);
      sub.clear();
    }
    else
    {
      sub += str[i];
    }
  }

  if (sub.size() != 0)
  {
    std::string temp;
    size_t sz = sub.size();

    if ((sub[0] >= 'a' && sub[0] <= 'z') || (sub[0] >= 'A' && sub[0] <= 'Z'))
    {
      temp = sub.substr(1, sz - 1) + sub[0];
      temp += "ay";
    }
    else
      temp = sub;

    fields.push_back(temp);
  }

  std::string ret;
  for (size_t i = 0; i < fields.size(); ++i)
  {
    ret += fields[i] + " ";
  }

  return ret.substr(0, ret.size() - 1);
}
