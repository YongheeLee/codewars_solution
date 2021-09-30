//https://www.codewars.com/kata/58e24788e24ddee28e000053

#include <string>
#include <unordered_map>

void parse(const std::string& str, std::vector<std::string>& fields)
{
  auto cstr = str.c_str();

  std::string field;
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] == ' ')
    {
      fields.push_back(field);
      field.clear();
    }
    else
    {
      field += str[i];
    }
  }
  if (field.size() != 0)
    fields.push_back(field);

}

struct command
{
  std::string method;
  std::string reg;
  std::string num;
};

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
  std::unordered_map<std::string, int> ret;

  std::vector<command> commands;
  for (const std::string& s : program)
  {
    std::cout << s << "\n";

    std::vector < std::string> strcmd;
    parse(s, strcmd);
    command cmd = { strcmd[0], strcmd[1] };
    if (strcmd.size() > 2) {
      cmd.num = strcmd[2];
    }

    commands.push_back(cmd);
  }

  int cnt = 0;

  while (cnt < commands.size())
  {
    command cmd = commands[cnt];

    if (cmd.method == "mov")
    {
      if (ret.find(cmd.reg) == ret.end())
        ret.insert(std::make_pair(cmd.reg, 0));

      if (ret.find(cmd.num) == ret.end())
        ret[cmd.reg] = atoi(cmd.num.c_str());
      else
        ret[cmd.reg] = ret[cmd.num];
    }
    else if (cmd.method == "inc")
    {
      ret[cmd.reg]++;
    }
    else if (cmd.method == "dec")
    {
      ret[cmd.reg]--;
    }
    else if (cmd.method == "jnz")
    {
      if (ret.find(cmd.reg) == ret.end()) {
        if (atoi(cmd.reg.c_str()) != 0)
        {
          cnt += atoi(cmd.num.c_str());
          continue;
        }
      }
      else
      {
        if (ret[cmd.reg] != 0)
        {
          cnt += atoi(cmd.num.c_str());
          continue;
        }
      }
    }

    cnt++;
  }

  return ret;
}
