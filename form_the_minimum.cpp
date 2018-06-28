#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

unsigned long long minValue(vector<int> values)
{
    if (values.empty())
        return 0;

    std::sort(values.begin(), values.end());

    unsigned long long result = values[0];
    int currentDigit = values[0];
    
    for (std::size_t i = 1; i < values.size(); ++i)
    {
        if (values[i] != currentDigit)
        {
            result *= 10;
            result += values[i];
            currentDigit = values[i];
        }
    }

    return result;
}

int main()
{
    assert(minValue({ 1,3,1 }) == 13);
    assert(minValue({ 4,7,5,7 }) == 457);
    assert(minValue({ 4,8,1,4 }) == 148);
    assert(minValue({ 5,7,9,5,7 }) == 579);
    assert(minValue({ 6,7,8,7,6,6 }) == 678);

    assert(minValue({ 5,6,9,9,7,6,4 }) == 45679);
    assert(minValue({ 1,9,1,3,7,4,6,6,7 }) == 134679);
    assert(minValue({ 3,6,5,5,9,8,7,6,3,5,9 }) == 356789);

    return 0;
}