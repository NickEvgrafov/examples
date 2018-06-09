#include <iostream>

int getLeftBound5(int val)
{
  int k = (val - 5) / 10; 
  int bound = k * 10 + 5;
  return bound >= val ? bound : bound + 10;
}

int getRigthBound5(int val)
{
  int k = (val - 5) / 10;
  int bound = k * 10 + 5;
  return bound <= val ? bound : bound - 10;
}

int count5(int start, int end)
{
  int leftBound5 = getLeftBound5(start);
  int rightBound5= getRigthBound5(end);

  if (leftBound5 > rightBound5)
    return 0;

  return (rightBound5 - leftBound5) / 10 + 1;
}


int dontGiveMeFive(int start, int end)
{
  if (start > end)
    return 0;
  return (end - start + 1) - count5(start, end);
}

int main()
{
    int start = 1;
    int end = 7;

    int ret = dontGiveMeFive(start, end);
    std::cout << start << "-" << end << ": " << ret << std::endl;

    return 0;
}

