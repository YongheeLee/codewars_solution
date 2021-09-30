//https://www.codewars.com/kata/54ff3102c1bad923760001f3

#include <string>

using namespace std;

int getCount(const string& inputStr) {
  int num_vowels = 0;
  
  for (int i = 0; i < inputStr.size(); ++i)
  {
    if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'o' || inputStr[i] == 'u')
      num_vowels++;
  }

  return num_vowels;
}
