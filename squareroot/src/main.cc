#include <iostream>
#include <cmath>

float squareroot(float in);

int
main(void)
{
    float vals[] = {9, 16, 0.388378, 1000.10};
    
    for(int i = 0;
        i < sizeof(vals)/sizeof(float);
        i++) {
        float val = sqrt(vals[i]);
        std::cout << "sqrt(" << vals[i] << "): " << val << std::endl;
//        assert(squareroot == val);
    }
        
    return 0;
}

float squareroot(float in)
{
    
}
