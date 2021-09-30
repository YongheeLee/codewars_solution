//https://www.codewars.com/kata/5671d975d81d6c1c87000022

#define S 4

int fixCnt = 0;

struct cell
{
  int fixed = -1;
  int possibleNo = 4;
  bool possible[S + 1] = { false, true, true, true, true };
  int possibleMax()
  {
    if (fixed != -1)
      return fixed;

    for (int i = 0; i < 4; ++i)
    {
      if (possible[S - i])
      {
        return S - i;
      }
    }
    return -1;
  }

  void setImpossible(int v)
  {
    if (possible[v])
    {
      possible[v] = false;
      possibleNo--;

      if (possibleNo == 0 && fixed == -1)
      {
        fixed = v;
        fixCnt++;
      }
    }
  }
};
std::vector<cell> cinfo(S* S);

void Fixed(int idx, int val)
{
  if (cinfo[idx].fixed != -1)
    return;

  int x = idx % S;
  int y = (idx - x) / S;
  fixCnt++;
  cinfo[idx].fixed = val;
  for (int i = 0; i <= S; ++i)
  {
    cinfo[idx].setImpossible(i);
  }

  for (int i = 0; i < S; ++i)
  {
    int ni1 = i * S + x;
    int ni2 = y * S + i;

    if (ni1 != idx)
      cinfo[ni1].setImpossible(val);

    if (ni2 != idx)
      cinfo[ni2].setImpossible(val);
  }
}

void ClueCheck(int* clues)
{
  int d = 0;
  for (int i = 0; i < S; ++i)
  {
    switch (clues[i + d * S])
    {
    case 0:
      continue;
    case 1:
      Fixed(i, S);
      break;
    case 2:
      cinfo[0 * S + i].setImpossible(S);
      cinfo[1 * S + i].setImpossible(S - 1);

      if (cinfo[1 * S + i].fixed != S && cinfo[1 * S + i].possible[S] == false)
        cinfo[0 * S + i].setImpossible(1);

      break;
    case 3:
      cinfo[0 * S + i].setImpossible(S - 1);
      cinfo[0 * S + i].setImpossible(S);

      if (cinfo[2 * S + i].fixed == 3 && cinfo[3 * S + i].fixed == 4)
        cinfo[0 * S + i].setImpossible(1);

      break;
    case 4:
      Fixed(0 * S + i, 1);
      Fixed(1 * S + i, 2);
      Fixed(2 * S + i, 3);
      Fixed(3 * S + i, 4);
      break;
    default:
      break;
    }
  }

  d++;
  for (int i = 0; i < S; ++i)
  {
    switch (clues[i + d * S])
    {
    case 0:
      continue;
    case 1:
      Fixed(i * S + S - 1, S);
      break;
    case 2:
      cinfo[i * S + S - 1].setImpossible(S);
      cinfo[i * S + S - 2].setImpossible(S - 1);

      if (cinfo[i * S + S - 2].fixed != S && cinfo[i * S + S - 2].possible[S] == false)
        cinfo[i * S + S - 1].setImpossible(1);

      break;
    case 3:
      cinfo[i * S + 3].setImpossible(S - 1);
      cinfo[i * S + 3].setImpossible(S);
      if (cinfo[i * S + 1].fixed == 3 && cinfo[i * S + 0].fixed == 4)
        cinfo[i * S + 3].setImpossible(1);
      break;
    case 4:
      Fixed(i * S + 0, 4);
      Fixed(i * S + 1, 3);
      Fixed(i * S + 2, 2);
      Fixed(i * S + 3, 1);
      break;
    default:
      break;
    }
  }

  d++;
  for (int i = 0; i < S; ++i)
  {
    switch (clues[i + d * S])
    {
    case 0:
      continue;
    case 1:
      Fixed((S - 1) * S + S - 1 - i, S);
      break;
    case 2:
      cinfo[(S - 1) * S + S - 1 - i].setImpossible(S);
      cinfo[(S - 2) * S + S - 1 - i].setImpossible(S - 1);

      if (cinfo[(S - 2) * S + S - 1 - i].fixed != S && cinfo[(S - 2) * S + S - 1 - i].possible[S] == false)
        cinfo[(S - 1) * S + S - 1 - i].setImpossible(1);

      break;
    case 3:
      cinfo[3 * S + 3 - i].setImpossible(S - 1);
      cinfo[3 * S + 3 - i].setImpossible(S);
      if (cinfo[1 * S + S - 1 - i].fixed == 3 && cinfo[0 * S + S - 1 - i].fixed == 4)
        cinfo[3 * S + 3 - i].setImpossible(1);
      break;
    case 4:
      Fixed(0 * S + S - 1 - i, 4);
      Fixed(1 * S + S - 1 - i, 3);
      Fixed(2 * S + S - 1 - i, 2);
      Fixed(3 * S + S - 1 - i, 1);
      break;
    default:
      break;
    }
  }

  d++;
  for (int i = 0; i < S; ++i)
  {
    switch (clues[i + d * S])
    {
    case 0:
      continue;
    case 1:
      Fixed((S - 1 - i) * S + 0, S);
      break;
    case 2:
      cinfo[(S - 1 - i) * S + 0].setImpossible(S);
      cinfo[(S - 1 - i) * S + 1].setImpossible(S - 1);

      if (cinfo[(S - 1 - i) * S + 1].fixed != S && cinfo[(S - 1 - i) * S + 1].possible[S] == false)
        cinfo[(S - 1 - i) * S + 0].setImpossible(1);

      break;
    case 3:
      cinfo[(S - 1 - i) * S + 0].setImpossible(S - 1);
      cinfo[(S - 1 - i) * S + 0].setImpossible(S);
      if (cinfo[(S - 1 - i) * S + 2].fixed == 3 && cinfo[(S - 1 - i) * S + 3].fixed == 4)
        cinfo[(S - 1 - i) * S + 0].setImpossible(1);
      break;
    case 4:
      Fixed((S - 1 - i) * S + 0, 1);
      Fixed((S - 1 - i) * S + 1, 2);
      Fixed((S - 1 - i) * S + 2, 3);
      Fixed((S - 1 - i) * S + 3, 4);
      break;
    default:
      break;
    }
  }
}

void LineCheck()
{
  for (int idx = 0; idx < cinfo.size(); ++idx)
  {
    if (cinfo[idx].fixed != -1)
      continue;

    int x = idx % S;
    int y = (idx - x) / S;

    for (int v = 1; v <= S; ++v)
    {
      int cnt = 0;
      int nIdx = -1;
      for (int i = 0; i < S; ++i)
      {
        int ni1 = i * S + x;
        if (cinfo[ni1].possible[v])
        {
          cnt++;
          nIdx = ni1;
        }

        if (cnt > 1)
          break;
      }

      if (cnt == 1)
      {
        Fixed(nIdx, v);
        break;
      }

      cnt = 0;
      nIdx = -1;
      for (int i = 0; i < S; ++i)
      {
        int ni2 = y * S + i;
        if (cinfo[ni2].possible[v])
        {
          cnt++;
          nIdx = ni2;
        }

        if (cnt > 1)
          break;
      }

      if (cnt == 1)
      {
        Fixed(nIdx, v);
        break;
      }
    }
  }
}

int** SolvePuzzle(int* clues) {
  cinfo.clear();
  cinfo.resize(S * S);
  fixCnt = 0;
  std::cout << "\n Clues \n";
  for (int i = 0; i < 16; ++i)
  {
    if (i % 4 == 0)
      std::cout << "\n";
    std::cout << clues[i] << ", ";

  }

  while (true)
  {
    ClueCheck(clues);
    LineCheck();

    if (fixCnt == S * S)
      break;
  }

  int** ret = (int**)calloc(S, sizeof(int*));
  for (int i = 0; i < S; ++i)
  {
    ret[i] = (int*)calloc(S, sizeof(int));
  }

  std::cout << "\n Sol \n";
  for (int i = 0; i < S; ++i)
  {
    std::cout << "\n";
    for (int j = 0; j < S; ++j)
    {
      int idx = i * S + j;
      ret[i][j] = cinfo[idx].fixed;
      std::cout << ret[i][j] << ", ";
    }
  }

  return ret;
}
