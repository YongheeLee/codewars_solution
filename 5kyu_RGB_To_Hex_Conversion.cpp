//https://www.codewars.com/kata/513e08acc600c94f01000001

#include <string>

class RGBToHex {
private: 
    static std::string hex(int v) {
    if (v > 255)
      v = 255;
    else if (v < 0)
      v = 0;

    int s = v % 16;
    int f = (v - s) / 16;

    return con(f) + con(s);
  }

  static std::string con(int v) {
    switch (v) {
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
    default:
      return std::to_string(v);
    }
  }

public:
  static std::string rgb(int r, int g, int b) { return hex(r) + hex(g) + hex(b); }
};
