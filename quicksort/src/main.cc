#include <iostream>
#include <cstdlib>
#include <cassert>

void quicksort(int *input, int nelem);

bool
isEqual(const int *input, const int *output)
{
    for(unsigned int i = 0; i < sizeof(input)/sizeof(int); i++) {
        if (input[i] != output[i]) {
            return false;
        }
    }
    return true;
}

int
main(void)
{
    // test case
    int input[] = {10, 4, 6, 2, 8, 3, 9, 1, 7, 5};
    int output[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // initializing vector?
    quicksort(input, 10);

    assert(isEqual(input, output));
    
    return 0;
}

void
quicksort(int *input, int nelem)
{
    std::cout << "nelem: " << nelem << std::endl;
// find pivot
    if (nelem <= 1) {
        return;
    }
    int pivot = input[0];

    int small = 0, big = nelem-1;
    for(int k = 1; k < nelem; k++) {
        if(input[k] < pivot) {
            input[small++] = input[k];
        } else if (input[k] >= pivot) {
            input[big--] = input[k];
        }
        std::cout << small << ", " << big << std::endl;
    }
    input[small] = pivot;
    quicksort(&input[0], small - 1);
    std::cout << "branch other" << std::endl;
    quicksort(&input[small+1], nelem - small);
}


