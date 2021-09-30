//https://www.codewars.com/kata/53005a7b26d12be55c000243

#include <string>
#include <math.h>

double invalid = 1e+20;
std::map<std::string, double> assign;

struct Field
{
  std::string str = "";
  double val = invalid;
  bool isSymbol = false;
  void reset() {
    str = "";
    val = invalid;
    isSymbol = false;
  }
};


std::vector<Field> fields;

bool isSymbol(const char c)
{
  if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=')
    return true;
  else
    return false;
}

bool isNumber(const char c)
{
  if (c >= '0' && c <= '9')
    return true;
  else
    return false;
}

void sanityCheck(std::string expression)
{
  bool ok = false;

  for (size_t i = 0; i < expression.size(); ++i)
  {
    if (expression[i] != ' ')
    {
      ok = true;
      break;
    }
  }

  if (!ok)
    throw 0;
}

double getValue(size_t i)
{
  if (assign.find(fields[i].str) != assign.end())
  {
    if (fields[i].val == invalid)
      return assign[fields[i].str];
    else
      return fields[i].val;
  }
  else
  {
    if (fields[i].val == invalid)
      throw 0;
    
    return fields[i].val;
  }
}

void subCalc(int s, int e)
{
  if (s == e)
  {
    fields[s].val = getValue(s);
    return;
  }

  for (size_t i = s; i <= e; ++i)
  {
    //if (i != s)
    //  fields[s].str += fields[i].str;
    //
    //if (fields[i].str == "=")
    //{
    //  if (assign.find(fields[i - 1].str) == assign.end())
    //    assign.insert(std::make_pair(fields[i - 1].str, getValue(i + 1)));
    //
    //  fields[i - 1].val = assign[fields[i - 1].str];
    //  fields.erase(fields.begin() + i, fields.begin() + i + 2);
    //  e -= 2;
    //}

    if ((i == 0 && fields[i].str == "-") || (i != 0 && fields[i - 1].isSymbol && fields[i].str == "-"))
    {
      fields[i + 1].val *= -1;
      //fields[s].str += fields[i + 1].str;
      fields.erase(fields.begin() + i);
      e--;
    }
  }

  size_t cnt = s;
  while (cnt <= e)
  {
    if (fields[cnt].str == "*")
    {
      fields[cnt - 1].val = getValue(cnt - 1) * getValue(cnt + 1);
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      e -= 2;
      continue;
    }
    else if (fields[cnt].str == "/")
    {
      fields[cnt - 1].val = getValue(cnt - 1) / getValue(cnt + 1);
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      e -= 2;
      continue;
    }
    else if (fields[cnt].str == "%")
    {
      fields[cnt - 1].val = fmod(getValue(cnt - 1), getValue(cnt + 1));
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      e -= 2;
      continue;
    }

    cnt++;
  }

  cnt = s;
  while (cnt <= e)
  {
    if (fields[cnt].str == "+")
    {
      fields[cnt - 1].val = getValue(cnt - 1) + getValue(cnt + 1);
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      e -= 2;
      continue;
    }
    else if (fields[cnt].str == "-")
    {
      fields[cnt - 1].val = getValue(cnt - 1) - getValue(cnt + 1);
      fields.erase(fields.begin() + cnt, fields.begin() + cnt + 2);
      e -= 2;
      continue;
    }

    cnt++;
  }

  for (size_t i = s; i <= e; ++i)
  {
    //if (i != s)
    //  fields[s].str += fields[i].str;

    if (fields[i].str == "=")
    {
      if (assign.find(fields[i - 1].str) == assign.end())
        assign.insert(std::make_pair(fields[i - 1].str, getValue(i + 1)));
    else
        assign[fields[i - 1].str] = getValue(i + 1);
      
      fields[i - 1].val = assign[fields[i - 1].str];
      fields.erase(fields.begin() + i, fields.begin() + i + 2);
      e -= 2;
    }
  }
}

double interpret(std::string expression) {
  fields.clear();

  sanityCheck(expression);

  std::cout << expression << "\n";

  size_t cnt = 0;
  while (cnt < expression.size())
  {
    if (expression[cnt] == ' ')
      expression.erase(expression.begin() + cnt);

    cnt++;
  }

  cnt = 0;
  
  bool afterSign = false;

  Field f;
  for (int i = 0; i < expression.size(); ++i)
  {
    if (isSymbol(expression[i]))
    {
      if (f.str.size() > 0)
      {
        if (isNumber(f.str[0]))
          f.val = atof(f.str.c_str());
        else
        {
          if (assign.find(f.str) != assign.end())
            f.val = assign[f.str];
        }

        fields.push_back(f);
      }

      f.reset();
      if (isSymbol(expression[i]))
        f.isSymbol = true;
      f.str = expression[i];
      fields.push_back(f);

      f.reset();
    }
    else
    {
      f.str += expression[i];
    }
  }

  if (f.str.size() > 0)
  {
    if (isNumber(f.str[0]))
      f.val = atof(f.str.c_str());
    else
    {
      if (assign.find(f.str) != assign.end())
        f.val = assign[f.str];
    }

    fields.push_back(f);
  }

  cnt = 0;
  bool start = false;
  int startIdx = 0;
  while (cnt < fields.size())
  {
    if (fields[cnt].str == "(")
    {
      start = true;
      startIdx = cnt;
    }
    else if (fields[cnt].str == ")")
    {
      fields.erase(fields.begin() + startIdx);
      fields.erase(fields.begin() + cnt - 1);
      subCalc(startIdx, cnt - 2);

      cnt = 0;
      start = false;
      startIdx = 0;

      continue;
    }


    cnt++;
  }

  subCalc(0, fields.size() - 1);

  return fields[0].val;
}
