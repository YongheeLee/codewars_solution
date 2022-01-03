//https://www.codewars.com/kata/52a382ee44408cea2500074c/cpp

#include <vector>

long long determinant(std::vector<std::vector<long long>> m) 
{
    size_t sz = m.size();

    if (sz == 1)
        return m[0][0];

    long long sum = 0;
    long long s = 1;
    for (int i = 0; i < sz; ++i)
    {
        std::vector<std::vector<long long>> sub;

        for (int r = 1; r < sz; ++r)
        {
            sub.push_back(std::vector<long long>());
            for (int c = 0; c < sz; ++c)
            {
                if(c == i)
                    continue;

                sub.back().push_back(m[r][c]);
            }
        }

        long long e = m[0][i];
        long long subD = determinant(sub);
        long long val = s * e * subD;
        sum += val;
        s *= -1;
    }

    return sum;
}

int main()
{
    std::vector<std::vector<long long>> data = {{1, 2},{3, 4}};
    double vas = determinant(data);
    return 0;
}
