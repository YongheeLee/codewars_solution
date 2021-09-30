//https://www.codewars.com/kata/514b92a657cdc65150000006

int solution(int number)
{
  std::vector<bool> visit(number, false);

  if (number < 0)
    return 0;

  int m3 = number - 1;
  int m5 = number - 1;

  int r3 = 0, r5 = 0;
  while (true)
  {
    if (m3 % 3 == 0)
    {
      m3 -= 3;
      r3 += 3;
      if (visit[r3] == false)
        visit[r3] = true;
    }
    else
      --m3;

    if(m3<=0)
      break;
  }

  while (true)
  {
    if (m5 % 5 == 0)
    {
      m5 -= 5;
      r5 += 5;
      if (visit[r5] == false)
        visit[r5] = true;
    }
    else
      --m5;

    if (m5 <= 0)
      break;
  }

  int ret = 0;
  for (int i = 0; i < number; ++i)
  {
    if (visit[i])
      ret += i;
  }

  return ret;
}
