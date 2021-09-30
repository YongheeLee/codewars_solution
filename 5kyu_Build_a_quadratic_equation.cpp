//https://www.codewars.com/kata/60a9148187cfaf002562ceb8

#include <string>

bool isSymbol1(const char c)
{
  if (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=')
    return true;
  else
    return false;
}

bool isNumber1(const char c)
{
  if (c >= '0' && c <= '9')
    return true;
  else
    return false;
}

void Parse(const std::string& expression, std::string& valStr, int& a, int& b)
{
  bool passX = false;
  bool isMinus = false;
  a = 1;
  b = 1;

  bool start = false;
  int startNum = 0;
  int endNum = 0;

  for (int i = 0; i < expression.size(); ++i)
  {
    if (start== false && isNumber1(expression[i]))
    {
      start = true;
      startNum = i;
    }
    else if (start && !isNumber1(expression[i]))
    {
      std::string sub = expression.substr(startNum, i - startNum);
      if (passX)
        b *= atoi(sub.c_str());
      else
        a *= atoi(sub.c_str());

      startNum = 0;
      start = false;
    }

    if (expression[i] == '-')
    {
      if (passX)
        b *= -1;
      else
        a *= -1;
    }

    if (!isSymbol1(expression[i]) && !isNumber1(expression[i]))
    {
      valStr = expression[i];
      passX = true;
    }

  }
}

std::string quadratic_builder(const std::string& expression)
{
  std::string first= "", second = "";
  bool brace = false;
  bool isFirst = true;
  for (int i = 0; i < expression.size(); ++i)
  {
    if (expression[i] == '(')
    {
      brace = true;
    }
    else if(expression[i] == ')')
    {
      brace = false;
      if (isFirst)
        isFirst = false;
    }
    else
    {
      if (brace)
      {
        if (isFirst)
          first += expression[i];
        else
          second += expression[i];
      }
    }
    
  }

  std::string valStr;
  int m = 1, n = 1, p, q;

  Parse(first + ")", valStr, m, p);
  Parse(second + ")", valStr, n, q);
  
  int a = m * n;
  int b = m * q + n * p;
  int c = p * q;

  std::string ret;
  if(a !=0)
    {
    ret += a<0?"-" : "";
    
    ret += abs(a) == 1 ? "" : std::to_string(abs(a));
    }
  ret += valStr + "^2";
  if(b != 0)
    {
  ret += b < 0 ? "-" : "+";
  ret += abs(b) == 1 ? "" : std::to_string(abs(b));
  ret += valStr;
    }
  if(c!=0)
    {
  ret += c < 0 ? "-" : "+";
  ret += std::to_string(abs(c));
  }

  return ret;
}
