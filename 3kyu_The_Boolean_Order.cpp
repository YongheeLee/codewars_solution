//https://www.codewars.com/kata/59eb1e4a0863c7ff7e000008/cpp

#include <iostream>
#include <string>
#include <map>

struct tfCount
{
    int64_t tCnt = 0;
    int64_t fCnt = 0;
};

tfCount count(const std::string &s, const std::string &ops, std::map<std::string, tfCount> &visit)
{
    tfCount cnt;

    std::string sum = s + ops;
    if(visit.find(sum) != visit.end())
    {
        cnt = visit[sum];
        return cnt;
    }

    size_t len = s.size();
    size_t opLen = ops.size();

    if(len == 1)
    {
        bool isTrue = s == "t";
        cnt.tCnt = isTrue ? 1 : 0;
        cnt.fCnt = isTrue ? 0 : 1;
        return cnt;
    }

    for (size_t o = 0; o < opLen; ++o)
    {
        char op = ops[o];
        std::string lhs = s.substr(0, o+1);
        std::string rhs = s.substr(o+1, len - o-1);
        std::string lho = ops.substr(0, o);
        std::string rho = ops.substr(o + 1, len - o - 1);

        tfCount lh = count(lhs, lho, visit);
        tfCount rh = count(rhs, rho, visit);

        if(op == '&')
        {
            cnt.tCnt += lh.tCnt * rh.tCnt;
            cnt.fCnt += lh.tCnt * rh.fCnt;
            cnt.fCnt += lh.fCnt * rh.tCnt;
            cnt.fCnt += lh.fCnt * rh.fCnt;
        }
        else if(op == '|')
        {
            cnt.tCnt += lh.tCnt * rh.tCnt;
            cnt.tCnt += lh.tCnt * rh.fCnt;
            cnt.tCnt += lh.fCnt * rh.tCnt;
            cnt.fCnt += lh.fCnt * rh.fCnt;
        }
        else if(op == '^')
        {
            cnt.fCnt += lh.tCnt * rh.tCnt;
            cnt.tCnt += lh.tCnt * rh.fCnt;
            cnt.tCnt += lh.fCnt * rh.tCnt;
            cnt.fCnt += lh.fCnt * rh.fCnt;
        }
    }

    visit.insert(std::make_pair(sum, cnt));

    return cnt;
}

int64_t solve(const std::string &s, const std::string &ops)
{
    std::cout << s << "," << ops << "\n";
    //if(s.length()>50)
    //      return 0;

    std::map<std::string, tfCount> visit;
    tfCount cnt = count(s, ops, visit);

    return cnt.tCnt;
}

int main()
{
    //int64_t ret0 = solve("tft", "^&");               // Equals(2));
    //int64_t ret1 = solve("ttftff", "|&^&&");         // Equals(16));
    //int64_t ret2 = solve("ttftfftf", "|&^&&||");     // Equals(339));
    //int64_t ret3 = solve("ttftfftft", "|&^&&||^");   // Equals(851));
    //int64_t ret4 = solve("ttftfftftf", "|&^&&||^&"); // Equals(2434));
    int64_t ret5 = solve("ttftfftftffttfftftftfftft","|&^&&||^&&^^|&&||^&&||&^"); // Equals(945766470799));

    return 0;
}
