//https://www.codewars.com/kata/52cf02cd825aef67070008fa

std::map<char, int> charToNum = {
  {'a', 1},  {'b', 2},  {'c', 3},  {'d', 4},  {'e', 5},  {'f', 6},  {'g', 7},  {'h', 8},
  {'i', 9},  {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16},
  {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24},
  {'y', 25}, {'z', 26}, {'A', 27},  {'B', 28},  {'C', 29},  {'D', 30},  {'E', 31},  {'F', 32},
  {'G', 33},  {'H', 34},  {'I', 35},  {'J', 36},  {'K', 37},  {'L', 38},  {'M', 39},  {'N', 40},
  {'O', 41},  {'P', 42},  {'Q', 43},  {'R', 44},  {'S', 45},  {'T', 46},  {'U', 47},  {'V', 48},
  {'W', 49},  {'X', 50},  {'Y', 51},  {'Z', 52},  {'0', 53},  {'1', 54},  {'2', 55},  {'3', 56},
  {'4', 57},  {'5', 58},  {'6', 59},  {'7', 60},  {'8', 61},  {'9', 62},  {'.', 63},  {',', 64},
  {'?', 65},  {' ', 66},  {';', 67}, };
std::map<int, char> numToChar;
struct Decoder {
  static char cvt(char in, int pos)
  {
    if (in == '!' || in == '@' || in == '#' || in == '$' || in == '%' || in == '^' || in == '&' || in == '*' || in == '(' || in == ')' || in == '_' || in == '+' || in == '-')
      return in;

    int cnt = 0;
    int num = charToNum[in];

    while (true)
    {
      if (num % 2 == 0)
      {
        num /= 2;
        cnt++;
      }
      else
      {
        num += 67;
      }

      if(cnt == pos + 1)
        break;
    }

    return numToChar[num];
  }

  static std::string decode(const std::string& p_what) {
    
    std::cout<<p_what<<"\n";
    
    for (auto it = charToNum.begin(); it != charToNum.end(); ++it)
    {
      numToChar.insert(std::make_pair(it->second, it->first));
    }

    char* c_ret = new char[p_what.size()];

    for (size_t s = 0; s < p_what.size(); ++s)
    {
      c_ret[s] = cvt(p_what.c_str()[s], s);
    }

    std::string ret(c_ret);

    return ret.substr(0, p_what.size());
  }
};
