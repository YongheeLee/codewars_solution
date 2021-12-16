//https://www.codewars.com/kata/55b7bb74a0256d4467000070/cpp

#include <vector>
#include <chrono>
#include <math.h>

struct rgnT
{
    int level = -1;
    long long mulVal = 1;
    long long divVal;
    std::vector<bool> indices;
};

long long factorial(long long n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return factorial(n - 1) * n;
}

void primeFactor(const long long &n, std::vector<long long> &ret)
{
    ret.clear();

    long long t = n;
    long long d = 2;
    float sqrtT = sqrt(float(t));
    while (true)
    {
        if (n != d && t % d == 0)
        {
            t /= d;
            sqrtT = sqrt(float(t));
            ret.push_back(d);

            while (true)
            {
                if (t % d == 0)
                {
                    t /= d;
                }
                else
                    break;
            }
        }
        else
        {
            d++;

            if (d % 2 == 0)
                d++;
        }

        if ((float)d > sqrtT || t < 2 * d || n < d * 2)
        {
            if ((ret.size() > 0 && ret.back() < t) && t != n)
                ret.push_back(t);
            break;
        }
    }
}

void recus(rgnT uRgn, std::vector<std::vector<rgnT>> &list)
{
    for (size_t l = uRgn.level - 1; l > 0; --l)
    {
        for (size_t r = 0; r < list[l].size(); ++r)
        {
            rgnT &rg = list[l][r];

            bool included = true;
            for (size_t i = 0; i < rg.indices.size(); ++i)
            {
                if (!uRgn.indices[i] && rg.indices[i])
                {
                    included = false;
                    break;
                }
            }

            if (!included)
                continue;

            rg.divVal -= uRgn.divVal;
        }
    }
}

long long properFractions(long long n)
{
    if (n < 2)
        return 0;

    std::vector<long long> pf;
    primeFactor(n, pf);

    size_t sz = pf.size();

    if (sz == 0)
        return n - 1;

    std::vector<std::vector<rgnT>> list;
    list.resize(sz + 1);

    long long u = factorial(sz);
    rgnT last;
    for (size_t i = 1; i <= sz; ++i)
    {
        long long b1 = factorial(i);
        long long b2 = factorial(sz - i);
        long long c = u / b1 / b2;

        std::vector<int> dd;
        for (int t = 0; t < i; ++t)
        {
            dd.push_back(t);
        }
        std::vector<std::vector<int>> itemlist;

        itemlist.push_back(dd);

        int idx = dd.size() - 1;
        while (true)
        {
            if (idx < 0)
                break;

            int cnt = itemlist.size();
            for (int t = 0; t < cnt; ++t)
            {
                std::vector<int> item = itemlist[t];
                for (int e = item.back(); e < sz; ++e)
                {
                    for (int si = idx; si < dd.size(); ++si)
                    {
                        item[si]++;
                    }
                    if (item.back() < sz)
                        itemlist.push_back(item);
                }
            }
            --idx;
        }

        for (size_t s = 0; s < itemlist.size(); ++s)
        {
            rgnT sub;
            sub.level = i;
            sub.indices.resize(sz, false);

            for (int m = 0; m < itemlist[s].size(); ++m)
            {
                sub.indices[itemlist[s][m]] = true;
                sub.mulVal *= pf[itemlist[s][m]];
            }

            sub.divVal = n / sub.mulVal;

            list[i].push_back(sub);
            last = sub;
        }
    }

    for (int l = sz; l > 1; --l)
    {
        int rsz = list[l].size();
        for (int r = 0; r < rsz; ++r)
        {
            recus(list[l][r], list);
        }
    }

    long long ret = n;
    for (size_t l = 0; l <= sz; ++l)
    {
        for (size_t r = 0; r < list[l].size(); ++r)
        {
            long long rgnNum = list[l][r].divVal;
            ret -= rgnNum;
        }
    }

    return ret;
}

int main()
{
    long long a1 = properFractions((long long)410260288732206488); //200310807950265600

    return 0;
}