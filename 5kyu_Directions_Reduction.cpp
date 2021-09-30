//https://www.codewars.com/kata/550f22f4d758534c1100025a

class DirReduction
{
public:
  static std::vector<std::string> dirReduc(std::vector<std::string>& arr)
  {
std::vector<std::string> ret;
    
    size_t num = arr.size();

    for (int e = 0; e < 1000; ++e)
    {
      bool found = false;
      for (size_t i = 0; i < num - 1; ++i)
      {
        if (i < 0 || i + 1 >= arr.size())
          break;
        
        if ((arr[i] == "NORTH" && arr[i + 1] == "SOUTH") ||
          (arr[i] == "SOUTH" && arr[i + 1] == "NORTH") ||
          (arr[i] == "EAST" && arr[i + 1] == "WEST") ||
          (arr[i] == "WEST" && arr[i + 1] == "EAST"))
        {
          arr.erase(arr.begin() + i, arr.begin() + i + 2);
          found = true;
          break;;
        }
      }

      num = arr.size();

      if (!found)
        break;
    }
    
    
    ret.insert(ret.end(), arr.begin(), arr.end());
    return ret;
  }
};
