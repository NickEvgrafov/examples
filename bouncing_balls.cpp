//h = 3, bounce = 0.66, window = 1.5, result is 3

//h * (bounce)^n > window
//(bounce) ^ n > (window / h);
//n > log_bounce(window/h), log_bounce(x) = log(x) / log(bounce)

#include <cmath>
#include <iostream>

int num_watches(float h, float bounce, float window)
{
    if ((h <= 0) || (bounce < 0 || bounce > 1) || (window >= h))
        return -1;

    float ratio = (window / h);
    float n = log(ratio) / log(bounce);

    return ceil(n) + 1;
}

int main()
{
    std::cout << num_watches(3.0, 0.66, 1.5) << std::endl;
    return 0;
}
