//https://www.codewars.com/kata/52e864d1ffb6ac25db00017f

#include <string>

struct numericExp
{
  std::string exp;
  bool isNumber = false;
  double val = 0.0;
};

bool isNumeric(char c) {
  if (c >= '0' && c <= '9')
    return true;

  return false;
}

numericExp makeExp(std::string str, bool isOps) {
  numericExp exp;
  exp.exp = str;

  if (!isOps) {
    double dval = atof(str.c_str());
    if (str != "0" && dval != 0.0) {
      exp.isNumber = true;
      exp.val = dval;
    }
  }
  return exp;
}

numericExp makePost(std::vector<numericExp>& fileds)
{
  numericExp ret;
  int cnt = fileds.size() - 1;
  //expo
  while (true)
  {
    if (cnt < 0)
      break;

    if (fileds[cnt].exp == "^")
    {
      fileds[cnt - 1].exp = fileds[cnt - 1].exp + fileds[cnt + 1].exp + fileds[cnt].exp;
      fileds.erase(fileds.begin() + cnt, fileds.begin() + cnt + 2);
    }

    cnt--;
  }

  cnt = 0;
  //times/divide
  while (true)
  {
    if (cnt >= fileds.size())
      break;

    if (fileds[cnt].exp == "*" || fileds[cnt].exp == "/")
    {
      fileds[cnt - 1].exp = fileds[cnt - 1].exp + fileds[cnt + 1].exp + fileds[cnt].exp;
      fileds.erase(fileds.begin() + cnt, fileds.begin() + cnt + 2);
      continue;
    }

    cnt++;
  }

  cnt = 0;
  //plus/minus
  while (true)
  {
    if (cnt >= fileds.size())
      break;

    if (fileds[cnt].exp == "+" || fileds[cnt].exp == "-")
    {
      fileds[cnt - 1].exp = fileds[cnt - 1].exp + fileds[cnt + 1].exp + fileds[cnt].exp;
      fileds.erase(fileds.begin() + cnt, fileds.begin() + cnt + 2);
      continue;
    }

    cnt++;
  }

  return fileds[0];
}


std::string to_postfix(std::string infix) {
  std::vector<numericExp> fields;

  std::string sub;
  for (int i = 0; i < infix.size(); ++i) {
    if (isNumeric(infix[i])) {
      sub += infix[i];

      if (i == infix.size() - 1) {
        numericExp nex = makeExp(sub, false);
        fields.push_back(nex);
      }
    }
    else {
      if (!sub.empty()) {
        numericExp nex = makeExp(sub, false);
        fields.push_back(nex);

        sub.clear();
      }

      numericExp ops = makeExp(std::string(1, infix[i]), true);
      fields.push_back(ops);
    }
  }

  int fieldCnt = 0;
  int startIdx, endIdx;
  bool start = false;

  while (true)
  {
    if (fields[fieldCnt].exp == "(")
    {
      start = true;
      startIdx = fieldCnt;
    }
    else if (start && fields[fieldCnt].exp == ")")
    {
      start = false;
      endIdx = fieldCnt;

      std::vector<numericExp> subFields(fields.begin() + startIdx + 1, fields.begin() + endIdx);
      numericExp ret = makePost(subFields);

      fields[startIdx] = ret;
      fields.erase(fields.begin() + startIdx + 1, fields.begin() + endIdx  +1);
    }

    fieldCnt++;
    if (fieldCnt >= fields.size())
      break;
  }

  return makePost(fields).exp;
}
