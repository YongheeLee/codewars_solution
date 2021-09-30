//https://www.codewars.com/kata/58c5577d61aefcf3ff000081

struct cipher
{
  char c;
  int r;
  int o;
};

std::string encode_rail_fence_cipher(const std::string& str, int n) {
  
  std::cout<< "ENCODE: "<< str<<" "<<n << "\n";
  
  if (str.size() == 0 || n < 2)
    return "";

  std::string en;
  en.resize(str.size());

  int r = 0;
  int o = 0;
  bool down = true;

  std::vector<std::vector<cipher>> rails;
  rails.resize(n);

  for (int i = 0; i < str.size(); ++i) {
    o = rails[r].size();

    cipher ci = { str[i], r, o };
    rails[r].push_back(ci);

    if (r == n - 1)
      down = false;
    else if (r == 0)
      down = true;

    if (down)
      r++;
    else
      r--;
  }

  int cnt = 0;
  for (int l = 0; l < rails.size(); ++l)
  {
    for (int t = 0; t < rails[l].size(); ++t)
    {
      en[cnt] = rails[l][t].c;
      cnt++;
    }
  }

  return en;
}

std::string decode_rail_fence_cipher(const std::string& str, int n) {
  if (str.size() == 0 || n < 2)
    return "";

  std::cout << "DECODE: " << str << " " << n << "\n";

  std::string en;
  en.resize(str.size());

  int r = 0;
  int o = 0;
  bool down = true;

  std::vector<std::vector<cipher>> rails;
  rails.resize(n);

  int s = n - 1;
  int s2 = s * 2;
  int len = str.size() / s2;
  int res = str.size() - (len * s2);

  for (int i = 0; i < n; ++i)
  {
    if (i == 0 || i == n - 1)
      rails[i].resize(len);
    else
      rails[i].resize(len * 2);
  }

  r = 0;
  down = false;
  for (int i = 0; i < res; ++i)
  {
    rails[r].push_back(cipher());

    if (r == n - 1)
      down = false;
    else if (r == 0)
      down = true;

    if (down)
      r++;
    else
      r--;
  }

  int cnt = 0;
  for (int l = 0; l < rails.size(); ++l)
  {
    for (int t = 0; t < rails[l].size(); ++t)
    {
      rails[l][t] = { str[cnt], l, t };
      cnt++;
    }
  }

  std::vector<int> railCnt(n, 0);
  r = 0;
  down = true;

  for (int i = 0; i < str.size(); ++i) {
    en[i] = rails[r][railCnt[r]].c;
    railCnt[r]++;
    if (r == n - 1)
      down = false;
    else if (r == 0)
      down = true;

    if (down)
      r++;
    else
      r--;
  }

  return en;
}
