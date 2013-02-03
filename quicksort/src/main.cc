#include <iostream>

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

    quicksort(input);

    assert(isEqual(input, output));
    
    return 0;
}

void
quicksort(int &)
{

}


