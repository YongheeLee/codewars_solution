//https://www.codewars.com/kata/52a78825cdfc2cfc87000005

#include <string>

struct vals
{
  std::string str;
  double val;
};

vals subCalc(std::string sub)
{
  std::vector<vals> fields;

  std::string field;
  for (int i = 0; i < sub.size(); ++i)
  {
    if (field.size() != 0 && (sub[i] == '+' || sub[i] == '*' || sub[i] == '-' || sub[i] == '/'))
    {
      vals v;
      v.str = field;

      if (field != "*" && field != "/" && field != "+" && field != "-")
        v.val = atof(field.c_str());

      fields.push_back(v);
      field.clear();

      vals op;
      op.str = sub[i];
      fields.push_back(op);
    }
    else
    {
      field += sub[i];
    }
  }

  if (field.size() != 0)
  {
    vals v;
    v.str = field;

    if (field != "*" && field != "/" && field != "+" && field != "-")
      v.val = atof(field.c_str());

    fields.push_back(v);
  }
  int cnt = 0;
  while (fields.size() > cnt)
  {
    if (fields[cnt].str == "-" && fields[cnt + 1].str == "-")
    {
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      cnt = 0;
      continue;
    }
    cnt++;
  }
  

  cnt = 0;
  while (fields.size()>cnt)
  {
    if (fields[cnt].str == "*" || fields[cnt].str == "/")
    {
      double p = fields[cnt - 1].val;
      double e = fields[cnt + 1].val;
      
      fields[cnt - 1].val = fields[cnt].str == "*" ? p * e : p / e;
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      cnt = 0;
      continue;
    }

    cnt++;
  }

  cnt = 0;
  while (fields.size() > cnt)
  {
    if (fields[cnt].str == "+" || fields[cnt].str == "-")
    {
      double p = fields[cnt - 1].val;
      double e = fields[cnt + 1].val;

      fields[cnt - 1].val = fields[cnt].str == "+" ? p + e : p - e;
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      cnt = 0;
      continue;
    }

    cnt++;
  }

  vals final;
  final.val = fields[0].val;

  
    char buf[100];
    sprintf(buf, "%.20f", fields[0].val);
    final.str = buf;
  

  return final;
}

double calc(std::string expression) {

    std::cout<< expression<< "???????\n";

  bool start = false;
  int startIdx = 0, endIdx = 0;
  std::string sub;
  size_t cnt = 0;

  bool hasBrace = false;
  while (expression.size() > cnt)
  {
    if (expression[cnt] == '(' || expression[cnt] == ')')
      hasBrace = true;

    if (expression[cnt] == ' ')
    {
      expression.erase(expression.begin() + cnt);
      continue;
    }

    cnt++;
  }

  if (hasBrace)
  {
    cnt = 0;
    while (expression.size() > cnt)
    {
      if (expression[cnt] == '(')
      {
        start = true;
        sub.clear();
        startIdx = cnt;
        cnt++;
        continue;
      }

      if (start)
      {
        if (expression[cnt] == ')')
        {
          start = false;
          endIdx = cnt;
          auto subStr = subCalc(sub);

          std::string f = expression.substr(0, startIdx);
          std::string e = expression.substr(endIdx + 1, expression.size() - endIdx-1);
          expression = f + subStr.str + e;

          sub.clear();
          cnt = 0;
          continue;
        }
        else
          sub += expression[cnt];
      }

      cnt++;
    }
  }

  
  return subCalc(expression).val;
}
