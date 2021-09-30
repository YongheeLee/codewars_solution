//https://www.codewars.com/kata/554ca54ffa7d91b236000023

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  std::map<int, int> map;
  std::vector<int> ret;

  for (size_t i = 0; i < arr.size(); ++i)
  {
    int item = arr[i];

    if (map.find(item) == map.end())
      map.insert(std::make_pair(item, 0));

    map[item]++;

    if(map[item]>n)
      continue;

    ret.push_back(item);
  }
  

  return ret;

}
