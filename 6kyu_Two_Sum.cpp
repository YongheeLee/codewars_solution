//https://www.codewars.com/kata/52c31f8e6605bcc646000082

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {

  size_t first = 0;
  size_t second = 0;
  while (true)
  {
    bool found = false;
    for (size_t i = first + 1; i < numbers.size(); ++i)
    {
      size_t sum = numbers[first] + numbers[i];
      if (sum == (size_t)target)
      {
        second = i;
        found = true;
        break;
      }

      //if(sum>(size_t)target)
      //  break;
    }

    if (found)
      break;

    first++;

    if(first >= numbers.size())
      break;
  }
  
  return { first, second };
}
