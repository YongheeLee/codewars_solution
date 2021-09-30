//https://www.codewars.com/kata/585894545a8a07255e0002f1

struct path
{
  std::vector<bool> visit;
  int cnt = 0;

  path() {
    visit.resize(9, false);
  }
};


void possible(const int& leng, int s, path p, int &total)
{
  if (leng == p.cnt)
  {
    total++;
    return;
  }

  std::vector<int> ret;
  for (int i = 0; i < 9; ++i)
  {
    if (i == s || p.visit[i] ||
      (s % 3 == 0 && s + 2 == i && p.visit[s + 1] == false) ||
      (s % 3 == 2 && s - 2 == i && p.visit[s - 1] == false) ||
      (s / 3 == 0 && s + 6 == i && p.visit[s + 3] == false) ||
      (s / 3 == 2 && s - 6 == i && p.visit[s - 3] == false) ||
      (s + i == 8 && p.visit[4] == false))
      continue;
    path cp;
    cp.cnt = p.cnt + 1;
    cp.visit = p.visit;
    cp.visit[i] = true;
  
    possible(leng, i, cp, total);
  }
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) {
  
  if (length == 0 || length > 9)
    return 0;
  
  int first = firstDot - 'A';

  path p;
  p.visit[first] = true;
  p.cnt = 1;

  int totalCnt = 0;

  possible(length, first, p, totalCnt);

  return totalCnt;
}
