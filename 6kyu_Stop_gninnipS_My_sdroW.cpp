//https://www.codewars.com/kata/5264d2b162488dc400000001

std::string spinWords(const std::string &str)
{
  std::vector<std::string*> arr;

  std::string* word = new std::string;
  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] == ' ')
    {
      if ((*word).length() < 5)
        arr.push_back(word);
      else
      {
        std::reverse(word->begin(), word->end());
        arr.push_back(word);
      }
      word = new std::string;
    }
    else
    {
      *word += str[i];
    }
  }

  if ((*word).length() < 5)
    arr.push_back(word);
  else
  {
    std::reverse(word->begin(), word->end());
    arr.push_back(word);
  }
  
  std::string ret;

  for (size_t i = 0; i < arr.size(); ++i)
  {
    ret += *arr[i] + " ";
  }

  return ret.substr(0, ret.length()-1);
}// spinWords
