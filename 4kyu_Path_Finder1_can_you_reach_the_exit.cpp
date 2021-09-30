//https://www.codewars.com/kata/5765870e190b1472ec0022a2

#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool path_finder(string maze) {
  
  int h = 1;
  int w = 0;

  string cvt;
  for (auto it = maze.begin(); it != maze.end(); ++it)
  {
    if (*it == '\n')
    {
      w = 0;
      h++;
    }
    else
    {
      cvt += *it;
      w++; 
    }
  }

  int pw = 0, ph = 0;
  std::queue<int> can;
  std::vector<bool> visit(cvt.length(), false);
  int final = w * h - 1;
  can.push(ph * w + pw);
  bool found = false;

  int dir[4][2] = { {-1,0}, {1,0}, {0,-1},{0,1} };

  while (true)
  {
    if (can.size() == 0)
      break;

    int seed = can.front();
    can.pop();

    pw = seed % w;
    ph = (seed - pw) / h;

    for (int i = 0; i < 4; ++i)
    {
      int nw = pw + dir[i][0];
      int nh = ph + dir[i][1];

      if (nw<0 || nw>w - 1 || nh<0 || nh>h - 1)
        continue;

      int nid = nh * w + nw;

      if (nid == final)
      {
        found = true;
        break;
      }

      if (!visit[nid] && cvt[nid] != 'W')
      {
        visit[nid] = true;
        can.push(nid);
      }
    }

  }

  return found;
}
