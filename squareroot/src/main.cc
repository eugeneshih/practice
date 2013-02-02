#include <iostream>
#include <cmath>
#include <cassert>
// there is a defined somewhere
#define EPS 0.000001

float squareroot(float in);

int
main(void)
{
    float vals[] = {9, 16, 0.388378, 1000.10};
    
    for(int i = 0; i < sizeof(vals)/sizeof(float); i++) {
        float val = sqrt(vals[i]);
        std::cout << "sqrt(" << vals[i] << "): " << val << std::endl;
        std::cout << "squareroot(" << vals[i] << "): "
                  << squareroot(vals[i]) << std::endl;        
        assert(std::abs(squareroot(vals[i]) - val) <= EPS);
    }
        
    return 0;
}

float squareroot(float in)
{
    float low = 0, high = 1;
    while(std::abs(high*high - low*low) > EPS) {
//        std::cout << "(" << low << "," << high << ")" << std::endl;
        if (in > low*low) {
            if (in < (high*high)) {
                high = (low + high) / 2;
            } else {
                low = high;
                high = high * 2;
            }
        } else if (in == low * low) {
            return low;
        } else {
            assert(false);
        }
    }
    return low;
}
