
#include <vector>

struct PeakData
{
    std::vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v)
{
    PeakData result;

    if(v.size() < 3)
        return result;

    int start = -1;
    for (int i = 1; i < v.size(); ++i)
    { 
        int pre = v[i-1];
        int cur = v[i];
        
        if(pre< cur)
        {
            start = i;
        }
        else if(start != -1)
        {
            if(pre> cur)
            {
                result.pos.push_back(start);
                result.peaks.push_back(v[start]);
                start = -1;
            }
        }
    }

    return result;
}

int main()
{
    pick_peaks(std::vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});

    return 0;
}