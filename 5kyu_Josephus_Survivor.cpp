//https://www.codewars.com/kata/555624b601231dc7a400017a

int josephusSurvivor(int n, int k) {
  if (n == 1)
    return 1;
  
  std::vector<int> a;
  for (int i = 1; i <= n; ++i)
  {
    a.push_back(i);
  }

  int idx = 0;
  int cnt = 0;
  while (true)
  {
    if (cnt == k-1)
    {
      a.erase(a.begin() + idx);
      cnt = 0;

      if (idx == a.size())
        idx = 0;

      if (a.size() == 1)
        break;
    }
    else
    {
      cnt++;
      idx++;
      if (idx >= a.size())
        idx = 0;
    }
  }

  return a[0];
}
