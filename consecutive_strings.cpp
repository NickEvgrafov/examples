#include <string>
#include <vector>
#include <numeric>

#include <cassert>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
};

std::string consec(const std::vector<std::string> strarr, std::size_t fromIndex, int k, std::size_t summOfLengths)
{
    std::string result;
    result.reserve(summOfLengths);

    std::size_t maxIndex = fromIndex + k - 1;
    for (std::size_t i = fromIndex; i <= maxIndex; ++i)
        result.append(strarr[i]);

    return result;
}

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
    if (strarr.empty() || strarr.size() < static_cast<std::size_t>(k))
        return "";

    if (strarr.size() == k)
        return consec(strarr, 0, k, 0);

    std::vector<std::size_t> lengths;
    
    std::size_t maxIndex = strarr.size();
    for (int i = strarr.size() - 1; i >= static_cast<int>(strarr.size() - k); --i)
    {
        lengths.push_back(strarr[i].size());
        --maxIndex;
    }

    std::size_t maxSummOfLengths = std::accumulate(lengths.begin(), lengths.end(), 0);
    std::size_t insertPosition = 0;
    std::size_t currentIndex = maxIndex - 1;

    for (int i = static_cast<int>(currentIndex); i >= 0; --i)
    {
        lengths[insertPosition] = strarr[i].size();
        insertPosition = (insertPosition + 1) % k;

        std::size_t currentSummOfLengths = std::accumulate(lengths.begin(), lengths.end(), 0);
        if (currentSummOfLengths >= maxSummOfLengths)
        {
            maxIndex = i;
            maxSummOfLengths = currentSummOfLengths;
        }
    }
    
    return consec(strarr, maxIndex, k, maxSummOfLengths);
}

void testequal(std::string ans, std::string sol) {
    assert(ans == sol);
}
void dotest(std::vector<std::string> arr, int k, std::string expected)
{
    testequal(LongestConsec::longestConsec(arr, k), expected);
}



int main()
{
    std::vector<std::string> arr = { "aaa" };
    dotest(arr, 1, "aaa");

    arr = { "aaa", "bbb" };
    dotest(arr, 2, "aaabbb");

    arr = { "zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail" };
    dotest(arr, 2, "abigailtheta");

    arr = { "ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh" };
    dotest(arr, 1, "oocccffuucccjjjkkkjyyyeehh");
    
    arr = { "aaa", "bbbbbbbb", "cccccccccc", "ddd", "12345678", "12345678" };
    dotest(arr, 2, "bbbbbbbbcccccccccc");

    return 0;
}