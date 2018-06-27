#include <iostream>


int getRigthBound5(int val)
{
  int k = (val - 5) / 10;
  int bound = k * 10 + 5;
  return  (bound > val) ? bound : bound + 10;
}

const int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int getNextCountOf5(int num, int& next)
{
    int maxPower = 0;
    bool found = false;

    for (int base = (num > 0) ? num : -num, power = 0; base != 0; base /= 10, ++power)
    {
        if (base % 10 == 5)
        {
            found = true;
            maxPower = power;
        }
    }

    if (!found)
    {
        next = num + 1;
        return 0;
    }

    if (num > 0)
        next = num / pow10[maxPower] * pow10[maxPower] + pow10[maxPower];
    else
        next = num / pow10[maxPower] * pow10[maxPower] + 1;
        
    return next - num;
}

int dontGiveMeFive(int start, int end)
{
    if (start > end)
       return 0;

    int num = start;
    int totalCount5 = 0;

    while (num <= end)
    {
        int next = 0;
        int count5 = getNextCountOf5(num, next);
        totalCount5 += count5;
        num = next;
    }
    
    return (end - start + 1) - totalCount5;
}

int main()
{    
    int start = 1;
    int end = 90;
    int i = 49;
//for (int i = end - 1; i >= start; --i)
    //{
    
        std::cout << "[" << i << ";" << end <<" ]: " << dontGiveMeFive(i, end)  << std::endl;
        //}

    return 0;
}

