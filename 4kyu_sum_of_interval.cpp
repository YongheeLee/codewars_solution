//https://www.codewars.com/kata/52b7ed099cdc285c300001cd/cpp

#include <vector>
#include <utility>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{

    //find max
    int min = 1e+6, max = -1e+6;
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (min > intervals[i].first)
            min = intervals[i].first;

        if (max < intervals[i].second)
            max = intervals[i].second;
    }

    std::vector<bool> has(max - min, false);

    for (int i = 0; i < intervals.size(); ++i)
    {
        for (int s = intervals[i].first; s < intervals[i].second; ++s)
        {
            has[s - min] = true;
        }
    }

    int ret = 0;
    for (int i = 0; i < max - min; ++i)
    {
        if (has[i])
            ++ret;
    }

    return ret;
}

int main()
{
    std::vector<std::pair<int, int>> intervals0 = {{1, 4}, {7, 10}, {3, 5}};
    std::vector<std::pair<int, int>> intervals1 = {{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}};
    std::vector<std::pair<int, int>> intervals2 = {{250, 345}, {2, 104}, {-385, -373}, {179, 405}, {237, 401}, {52, 220}, {174, 446}, {252, 340}, {-184, 279}, {-141, -102}, {-293, 153}, {-237, 251}};

    //int ret0 = sum_intervals(intervals0);
    //int ret1 = sum_intervals(intervals1);
    int ret2 = sum_intervals(intervals2);

    return 0;
}
