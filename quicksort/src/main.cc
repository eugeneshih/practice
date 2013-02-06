#include <iostream>
#include <cstdlib>

void quicksort(int *input, int nelem);

bool
isEqual(const int &input, const int &output)
{
    for(int i = 0; i < sizeof(input)/sizeof(int); i++) {
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
    // find pivot
    int pivot = input[0];

    // two temporary arrays (should be able to do in place)
    int less[nelem];
    int greater[nelem];
    int l = 0;
    int g = 0;

    for(int k = 1; k < nelem; k++) {
        if(input[k] < nelem) {
            less[l] = input[k];
            l++;
        } else {
            greater[g] = input[k];
            g++;
        }
    }
    less[k] = pivot;    
    for(int k = l + 1; k < nelem; k++) {
        less[k] = greater[nelem - l + k];
    }
}


