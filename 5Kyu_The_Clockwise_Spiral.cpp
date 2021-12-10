//https://www.codewars.com/kata/536a155256eb459b8700077e/cpp

#include <vector>

std::vector<std::vector<int>> create_spiral(int n)
{
    std::vector<std::vector<int>> ret;

    if (n < 1)
        return ret;

    std::vector<int> flat(n * n, 0);

    std::vector<bool> visit(n * n, false);
    std::vector<std::pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dirD = 4;
    int dirC = 0;

    int x = 0, y = 0;
    for (int i = 0; i < n * n; ++i)
    {
        int idx = y * n + x;
        flat[idx] = i + 1;
        visit[idx] = true;

        std::pair<int, int> next = dir[dirC % dirD];

        int nx = x + next.first;
        int ny = y + next.second;
        int nIdx = ny * n + nx;

        if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || nIdx < 0 || nIdx > n * n - 1 || visit[nIdx])
        {
            dirC++;
            nx = x + dir[dirC % dirD].first;
            ny = y + dir[dirC % dirD].second;
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; ++i)
    {
        std::vector<int> row(flat.begin() + i * n, flat.begin() + (i + 1) * n);
        ret.push_back(row);
    }

    return ret;
}

int main()
{
    create_spiral(4);

    return 0;
}