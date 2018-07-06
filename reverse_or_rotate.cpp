#include <string>
#include <cassert>

class RevRot
{
public:
    static std::string revRot(const std::string &strng, unsigned int sz);
};

const int cubes[] = { 0, 1, 8, 27, 64, 125, 216, 343,  512, 729 };

bool NeedToReverse(const char* begin, const char* end)
{
    int sumOfCubes = 0;
    for (const char* it = begin; it < end; ++it)
        sumOfCubes += cubes[static_cast<std::size_t>(*it - '0')];
    return sumOfCubes % 2 == 0;
}

std::string Reverse(const char* begin, const char* end)
{
    std::string result;
    result.reserve(static_cast<std::size_t>(end - begin));
    for (const char* rit = end - 1; rit >= begin; --rit)
        result.push_back(*rit);
    return result;
}

std::string Rotate(const char* begin, const char* end)
{
    std::string result;
    result.reserve(static_cast<std::size_t>(end - begin));
    for (const char* it = begin + 1; it != end; ++it)
        result.push_back(*it);
    result.push_back(*begin);

    return result;
}

std::string processChunk(const char* begin, const char* end)
{
    if (NeedToReverse(begin, end))
        return Reverse(begin, end);
    return Rotate(begin, end);
}

std::string RevRot::revRot(const std::string &str, unsigned int sz)
{
    if (sz <= 0 || str.empty())
        return "";
    if (sz > str.size())
        return "";

    std::string result;
    result.reserve(str.length());

    for (std::size_t beg = 0; beg + sz <= str.length(); beg += sz)
        result.append(processChunk(str.c_str() + beg, str.c_str() + beg + sz));
    
    return result;
}

void testequal(std::string ans, std::string sol)
{
    assert(ans == sol);
}
static void dotest(std::string s, unsigned int sz, std::string expected)
{
    testequal(RevRot::revRot(s, sz), expected);
}

int main()
{
    std::string s = "1234";
    dotest(s, 0, "");
    s = "";
    dotest(s, 0, "");
    s = "733049910872815764";
    dotest(s, 5, "330479108928157");
    s = "73304991087281576455176044327690580265896";
    dotest(s, 8, "1994033775182780067155464327690480265895");

    dotest("123456987654", 6, "234561876549");
    dotest("123456987653", 6, "234561356789");
    dotest("66443875", 4, "44668753");
    dotest("66443875", 8, "64438756");
    dotest("664438769", 8, "67834466");
    dotest("123456779", 8, "23456771");
    dotest("", 8, "");
    dotest("123456779", 0, "");
    dotest("563000655734469485", 4, "0365065073456944");

    return 0;
}