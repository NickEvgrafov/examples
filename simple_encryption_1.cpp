#include <string>
#include <iostream>
#include <cassert>

//For building the encrypted string :
//Take every 2nd char from the string, then the other chars, that are not every 2nd char, and concat them as new String.
//Do this n times!

//"This is a test!", 1 -> "hsi  etTi sats!"
//"This is a test!", 2 -> "hsi  etTi sats!" -> "s eT ashi tist!"

std::string encrypt_once(std::string text)
{
    std::string result;
    result.reserve(text.size());

    for (std::size_t i = 1; i < text.size(); i += 2)
        result.push_back(text[i]);
    for (std::size_t i = 0; i < text.size(); i += 2)
        result.push_back(text[i]);

    return result;
}

std::string encrypt(std::string text, int n)
{
    if (text.empty() || n <= 0)
        return text;

    std::string result = text;

    for (int i = 0; i < n; ++i)
        result = encrypt_once(result);

    return result;
}

std::string decrypt_once(std::string text)
{
    std::string result;
    result.reserve(text.size());

    std::size_t boundPos = text.size() / 2;
    std::size_t pos2 = 0;

    for (std::size_t i = boundPos; i < text.size(); ++i)
    {
        result.push_back(text[i]);
        if (pos2 < boundPos)
            result.push_back(text[pos2++]);
    }

    return result;
}

std::string decrypt(std::string text, int n)
{
    if (text.empty() || n <= 0)
        return text;

    std::string result = text;

    for (int i = 0; i < n; ++i)
        result = decrypt_once(result);

    return result;
}

void test(const std::string& str)
{
    std::cout << "======================================" << std::endl;
    std::cout << "text=" << str << std::endl;
    std::string encrypted_once = encrypt(str, 1);
    std::cout << "Encrypted once: " << encrypted_once << std::endl;

    std::string encrypted_twice = encrypt(str, 2);
    std::cout << "Encrypted twice: " << encrypted_twice << std::endl;

    std::string decrypted_once_once = decrypt(encrypted_once, 1);
    std::cout << "Decrypted from encrypted_once: " << decrypted_once_once << std::endl;
    assert(decrypted_once_once == str);

    std::string decrypted_twice_twice = decrypt(encrypted_twice, 2);
    std::cout << "Dectypted from encrypted_twice: " << decrypted_twice_twice << std::endl;
    assert(decrypted_twice_twice == str);
}

int main()
{
    test("This is a test!");
    test("");
    test("1");
    test("12");
    test("123");
    test("1234");
    test("12345");
    test("123456");

    return 0;
}