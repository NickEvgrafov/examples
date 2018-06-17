//h = 3, bounce = 0.66, window = 1.5, result is 3

//h * (bounce)^n > window
//(bounce) ^ n > (window / h);
//n > log_bounce(window/h), log_bounce(x) = log(x) / log(bounce)

//testequal(Bouncingball::bouncingBall(3, 0.66, 1.5), 3);
//testequal(Bouncingball::bouncingBall(30, 0.66, 1.5), 15);

#include <cmath>
#include <iostream>

int num_watches(float h, float bounce, float window)
{
    if ((h <= 0) || (bounce < 0 || bounce > 1) || (window >= h))
        return -1;


    int result = 1;

    double nexth = h;
    do
    {
        nexth = nexth * double(bounce);
        if (nexth > double(window))
            result += 2;
    }
    while (nexth > double(window));

    return result;
}

int main()
{
    std::cout << num_watches(3.0, 0.66, 1.5) << std::endl; // 3
    std::cout << num_watches(30, 0.66, 1.5) << std::endl; // 15

    return 0;
}
