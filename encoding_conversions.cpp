#include <iostream>
#include <vector>
#include <cassert>

#include <boost/locale.hpp>


std::string Utf16toUtf8(const char16_t* utf16)
{
    return boost::locale::conv::utf_to_utf<char>(utf16);
}

std::u32string Utf16toUtf32(const std::u16string& utf16String)
{
    return boost::locale::conv::utf_to_utf<char32_t>(utf16String);
}

#if !defined(WIN32) && !defined(_WIN32)
std::wstring Utf16toWideString(const std::u16string& utf16String)
{
    return boost::locale::conv::utf_to_utf<wchar_t>(utf16String);
}
#endif

std::u16string Utf32toUtf16(const std::u32string& utf32String)
{
    return boost::locale::conv::utf_to_utf<char16_t>(utf32String);
}

#if !defined(WIN32) && !defined(_WIN32)
std::u16string WideStringtoUtf16(const std::wstring& wideString)
{
    return boost::locale::conv::utf_to_utf<char16_t>(wideString);
}
#endif

std::u16string Utf8ToUtf16(const std::string& str)
{
    return boost::locale::conv::utf_to_utf<char16_t>(str);
}

int main()
{
    std::vector<uint8_t> sample32 = {
        61, 00, 00, 00,  62, 00, 00, 00,  63, 00, 00, 00,  64, 00, 00, 00,
        65, 00, 00, 00,  66, 00, 00, 00,  67, 00, 00, 00,  68, 00, 00, 00 };
    std::vector<uint8_t> sample16 = { 61, 00, 62, 00, 63, 00, 64, 00, 65, 00, 66, 00, 67, 00, 68, 00 };
    std::u32string u32str = U"abcdefgh";
    std::u16string u16str = u"abcdefgh";
    std::wstring wstr = L"abcdefgh";
    std::string str = u8"abcdefgh";

    assert(memcmp(&sample16[0], u16str.c_str(), sample16.size()));
    assert(memcmp(&sample32[0], u32str.c_str(), sample32.size()));
#if defined(WIN32) || defined(_WIN32)
    assert(memcmp(u16str.c_str(), wstr.c_str(), wstr.size() * sizeof(wchar_t)) == 0);
#else
    assert(memcmp(u32str.c_str(), wstr.c_str(), wstr.size() * sizeof(wchar_t)) == 0);
    auto tmpUtf32 = Utf16toUtf32(u16str);
    auto tmpWstr = Utf16toWideString(u16str);
    assert(memcmp(tmpUtf32.c_str(), tmpWstr.c_str(), tmpUtf32.size() * sizeof(char32_t)) == 0);
    assert(WideStringtoUtf16(wstr) == u16str);
#endif
    assert(Utf16toUtf8(u16str.c_str()) == str);
    assert(Utf16toUtf32(u16str) == u32str);
    assert(Utf32toUtf16(u32str) == u16str);
    assert(Utf8ToUtf16(str) == u16str);

    std::vector<uint8_t> sample32Rus = {
        30, 04, 00, 00,  31, 04, 00, 00,  32, 04, 00, 00,  33, 04, 00, 00,
        34, 04, 00, 00,  35, 04, 00, 00,  36, 04, 00, 00,  37, 04, 00, 00 };
    std::vector<uint8_t> sample16Rus = { 30, 4, 31, 4, 32, 4, 33, 4, 34, 4, 35, 4, 36, 4, 37, 4 };
    std::u32string u32strRus = U"абвгдежз";
    std::u16string u16strRus = u"абвгдежз";
    std::wstring wstrRus = L"абвгдежз";
    std::string strRus = u8"абвгдежз";

    assert(memcmp(&sample16Rus[0], u16strRus.c_str(), sample16Rus.size()));
    assert(memcmp(&sample32Rus[0], u32strRus.c_str(), sample32Rus.size()));
#if defined(WIN32) || defined(_WIN32)
    assert(memcmp(u16strRus.c_str(), wstrRus.c_str(), wstrRus.size() * sizeof(wchar_t)) == 0);
#else
    assert(memcmp(u32strRus.c_str(), wstrRus.c_str(), wstrRus.size() * sizeof(wchar_t)) == 0);
    auto tmpUtf32Rus = Utf16toUtf32(u16strRus);
    auto tmpWstrRus = Utf16toWideString(u16strRus);
    assert(memcmp(tmpUtf32Rus.c_str(), tmpWstrRus.c_str(), tmpUtf32Rus.size() * sizeof(char32_t)) == 0);
    assert(WideStringtoUtf16(wstrRus) == u16strRus);
#endif
    assert(Utf16toUtf8(u16strRus.c_str()) == strRus);
    assert(Utf16toUtf32(u16strRus.c_str()) == u32strRus);
    assert(Utf32toUtf16(u32strRus) == u16strRus);
    assert(Utf8ToUtf16(strRus) == u16strRus);
}
