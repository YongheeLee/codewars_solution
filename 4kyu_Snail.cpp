//https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map) {
  std::vector<int> ret;

  size_t h = snail_map.size();
  size_t w = snail_map[0].size();

  if (h == 0 || w == 0)
    return ret;

  size_t oh = h;
  size_t ow = w;

  size_t iw = 0, ih = 0;
  
  while (true)
  {
    bool isStop = false;
    for (int i = iw; i < w; ++i)
    {
      if (ret.size() < oh * ow)
        ret.push_back(snail_map[ih][i]);
    }

    for (int i = ih + 1; i < h; ++i)
    {
      if (ret.size() < oh * ow)
        ret.push_back(snail_map[i][w - 1]);
    }

    if (w > 1)
    {
      for (int i = w - 2; i>=0 && i >= iw; --i)
      {
        if (ret.size() < oh * ow)
          ret.push_back(snail_map[h - 1][i]);
      }
    }
    
    if (h > 1)
    {
      for (int i = h - 2; i >= 0 && i >= ih + 1; --i)
      {
        if (ret.size() < oh * ow)
          ret.push_back(snail_map[i][iw]);
      }
    }
    

    if(ret.size()==oh*ow)
      break;

    iw++;
    ih++;
    w--;
    h--;
  }

  return ret;
}
