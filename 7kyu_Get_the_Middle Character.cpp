//https://www.codewars.com/kata/56747fd5cb988479af000028

std::string get_middle(std::string input) 
{
  if (input.size() % 2 == 0)
  {
    return input.substr(input.size() / 2 - 1, 2);
  }
  else
  {
    return input.substr((input.size() - 1) / 2, 1);
  }
}
