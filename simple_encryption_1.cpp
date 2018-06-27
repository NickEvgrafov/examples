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
    std::string result = text;

    for (int i = 0; i < n; ++i)
        result = encrypt_once(result);

    return result;
}

std::string decrypt(std::string encryptedText, int n)
{
    encryptedText;
    n;
    return std::string();
}

int main()
{
    std::string str = "This is a test!";

    std::string encrypted_once = encrypt(str, 1);
    std::cout << "Encrypted once: " << encrypted_once << std::endl;
    assert(encrypted_once == "hsi  etTi sats!");

    std::string encrypted_twice = encrypt(str, 2);
    std::cout << "Encrypted twice: " << encrypted_twice << std::endl;
    assert(encrypted_twice == "s eT ashi tist!");

    return 0;
}