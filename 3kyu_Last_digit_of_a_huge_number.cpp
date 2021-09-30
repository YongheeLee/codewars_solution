//https://www.codewars.com/kata/5518a860a73e708c0a000027

#include <list>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
int last_digit(list<int> array) {
  std::vector<int> vec;
  vec.insert(vec.end(), array.begin(), array.end());

  if (vec.size() == 0)
    return 1;

  int f = vec[0] % 10;
  
  for(int i= 0;i<vec.size();++i )
    {
    std::cout<<vec[i]<< " ";
}
  std::cout<<"|\n";
  
  if (vec.size() == 1)
    return f;
  
  int arrSz = vec.size();
  int b = vec[arrSz - 1];
  for (int i = arrSz - 2; i > 0; --i)
  {
    int a = vec[i];

    if (b == 0)
    {
      b = 1; continue;
    }

    if (a == 0)
    {
      b = 0; continue;
    }

    a = a > 4 ? (a % 4) + 4 : a;
    b = b > 4 ? (b % 4) + 4 : b;

    size_t t = (size_t)std::pow(a, b);
    b = t > 4 ? (t % 4) + 4 : t;
  }

  if (f == 0 && b==0)
    return 1;
  
  if (f == 0)
    return 0;
  

  if (b == 0)
    return 1;

  b = (b % 4) + 4;
  
  size_t t = (size_t)std::pow(f, b);

  f = t % 10;
  return f;
}
