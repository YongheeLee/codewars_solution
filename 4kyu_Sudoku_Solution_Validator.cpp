//https://www.codewars.com/kata/529bf0e9bdf7657179000008

bool validSolution(unsigned int board[9][9]){
  bool valid = true;
  std::vector<bool> check = { false, false, false, false, false, false, false, false, false };

  for (int s = 0; s < 9; ++s)
  {
    int sX = (s % 3) * 3;
    int sY = ((s - (s % 3)) / 3) * 3;

    std::fill(check.begin(), check.end(), false);

    //check subCell
    int comCnt = 0;
    for (int i = 0; i < 9; ++i)
    {
      int iX = sX + (i % 3);
      int iY = sY + ((i - (i % 3)) / 3);

      if (board[iX][iY] == 0)
        continue;

      if (check[board[iX][iY] - 1] == false)
        check[board[iX][iY] - 1] = true;
      else
      {
        valid = false;
        break;
      }

      comCnt++;
    }

    if (!valid)
      break;

    comCnt = 0;
    for (int i = 0; i < 9; ++i)
    {
      int iX = sX + (i % 3);
      int iY = sY + ((i - (i % 3)) / 3);

      std::fill(check.begin(), check.end(), false);
      for (int j = 0; j < 9; ++j)
      {
        if (board[iX][j] == 0)
          continue;

        if (check[board[iX][j] - 1] == false)
          check[board[iX][j] - 1] = true;
        else
        {
          valid = false;
          break;
        }
      }

      if (!valid)
        break;

      std::fill(check.begin(), check.end(), false);
      for (int j = 0; j < 9; ++j)
      {
        if (board[j][iY] == 0)
          continue;

        if (check[board[j][iY] - 1] == false)
          check[board[j][iY] - 1] = true;
        else
        {
          valid = false;
          break;
        }
      }

      if (!valid)
        break;
      

      comCnt++;
    }

    if (!valid)
      break;

  }

  return valid;
}
