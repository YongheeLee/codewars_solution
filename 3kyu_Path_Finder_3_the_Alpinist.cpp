//https://www.codewars.com/kata/576986639772456f6f00030c

#include <queue>
#include <math.h>

int path_finder(std::string maze)
{
  struct cellT
  {
    int cellId = 0;
    int wId = 0;
    int hId = 0;
    int fromCellId = 0;
    int alti = 0;
    int score = 0;
  };

  int N = (int)floor(sqrt(maze.size()));
  std::vector<cellT> cells(N* N);

  std::map<char, int> map{ {'0', 0},{'1', 1},{'2', 2},{'3', 3},{'4', 4},{'5', 5},{'6', 6},{'7', 7},{'8', 8},{'9', 9} };

  int cnt = 0;
  for (auto it = maze.begin(); it != maze.end(); ++it)
  {
    if (*it == '\n')
    {
      continue;
    }

    cells[cnt].cellId = cnt;
    cells[cnt].wId = cnt % N;
    cells[cnt].hId = (cnt - cells[cnt].wId) / N;
    cells[cnt].alti = map[*it];
    cnt++;
  }

  std::vector<bool> visit(N* N, false);
  visit[0] = true;

  std::queue<int> cand;
  cand.push(0);

  while (true)
  {
    int seedId = cand.front();
    cand.pop();

    cellT seedCell = cells[seedId];

    int dir[4][2] = { {-1,0}, {0,-1} , {1,0}, {0,1} };
    for (int d = 0; d < 4; ++d)
    {
      int nw = seedCell.wId + dir[d][0];
      int nh = seedCell.hId + dir[d][1];

      if (nw<0 || nw>N - 1 || nh<0 || nh>N - 1)
        continue;

      int nid = nh * N + nw;

      if (nid == seedCell.fromCellId)
        continue;

      int newScore = cells[nid].alti == seedCell.alti ? seedCell.score : seedCell.score + abs(cells[nid].alti - seedCell.alti);

      if (visit[nid] == false)
      {
        cells[nid].fromCellId = seedId;
        cells[nid].score = newScore;
        cand.push(nid);
        visit[nid] = true;
      }
      else
      {
        if (cells[nid].score > newScore)
        {
          cells[nid].score = newScore;
          cells[nid].fromCellId = seedId;
          cand.push(nid);
        }
      }
    }

    if (cand.size() == 0)
      break;
  }
  
  return cells.back().score;
}
