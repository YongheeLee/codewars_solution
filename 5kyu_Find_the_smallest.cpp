//https://www.codewars.com/kata/573992c724fc289553000e95

class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n)
      {
      std::cout<<n<<"\n";
      
std::vector<long long> ret;

    std::string str = std::to_string(n);
    int num = str.size();
    
    long long minVal = n;
    int minI = num, minJ = num;
    for (int i = 0; i < num; ++i)
    {
      int min = 10;
      int minIdx;

      for (int j = 0; j < num; ++j)
      {
        if (i == j)
          continue;

        std::string tmp(str);

        tmp.erase(tmp.begin() + i);
        tmp.insert(tmp.begin() + j, str[i]);

        long long val = atoll(tmp.c_str());

        if (val > minVal)
          continue;

        if (val < minVal)
        {
          minVal = val;
          minI = i;
          minJ = j;
        }
      }
    }

    ret.push_back(minVal);
    ret.push_back(minI);
    ret.push_back(minJ);

    return ret;
    }
};
