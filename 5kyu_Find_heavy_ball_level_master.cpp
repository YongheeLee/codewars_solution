//https://www.codewars.com/kata/544034f426bc6adda200000e

#include<vector>

unsigned int findBall(Scales scales) {
  int w = scales.getWeight({ 0, 1, 2 }, { 3, 4, 5 });

  if (w < 0)
  {
    w = scales.getWeight({ 0 }, { 1 });
    if (w < 0)
      return 0;
    else if (w > 0)
      return 1;
    else
      return 2;
  }
  else if (w > 0)
  {
    w = scales.getWeight({ 3 }, { 4 });
    if (w < 0)
      return 3;
    else if (w > 0)
      return 4;
    else
      return 5;
  }
  else
  {
    w = scales.getWeight({ 6 }, { 7 });
    if (w < 0)
      return 6;
    else
      return 7;
  }
  return 0;
  
}

