#include <cassert>
#include <iostream>

static bool binary_search(int *sorted_array, int sz, int value);
static bool binary_search_with_idx(int *sorted_array,
                                   int sz, int value, int *val_idx);

int
main(void)
{
    int test_input1[] = {0, 1, 2, 3, 4, 5}; // size 6
    int test_input2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int test_input3[] = {0, 1};
    int test_input4[] = {};
    
    int index;

    // success
    bool result = binary_search(test_input1,
                                sizeof(test_input1)/sizeof(int),
                                0);
    assert(result == true);
    std::cout << "done" << std::endl;
    
    // failure
    result = binary_search(test_input1,
                           sizeof(test_input1)/sizeof(int),
                           6);
    assert(result == false);
    std::cout << "done" << std::endl;

    // success
    result = binary_search(test_input3,
                           sizeof(test_input3)/sizeof(int),
                           0);
    assert(result == true);
    std::cout << "done" << std::endl;
    
    // success
    result = binary_search(test_input2,
                           sizeof(test_input2)/sizeof(int),
                           11);
    assert(result == true);
    std::cout << "done" << std::endl;
    
    // failure
    result = binary_search(test_input3,
                           sizeof(test_input3)/sizeof(int),
                           -1);
    assert(result == false);
    std::cout << "done" << std::endl;
    
    // failure
    result = binary_search(test_input4,
                           0,
                           0);
    assert(result == false);
    std::cout << "done" << std::endl;

    return 0;
}


static bool binary_search_with_idx(int *sorted_array,
                                   int array_sz,
                                   int value,
                                   int *val_idx)
{
    return false;
}

static bool binary_search(int *sorted_array,
                          int array_sz,
                          int value)
{
    // print out sorted array
    for(int i = 0; i < array_sz; i++) {
        std::cout << sorted_array[i] << " ";
    }
    std::cout << std::endl;

    if (array_sz == 0) {
        return false;
    }
    
    int new_sz = array_sz / 2;
    int median = sorted_array[new_sz-1];
    
    if(median == value) {
        return true;
    } else if(new_sz == 1) {
        return false;
    } else if (value < median) {
        return binary_search(sorted_array,
                             new_sz,
                             value);
    } else {
        return binary_search(&sorted_array[new_sz],
                             array_sz - new_sz,
                             value);
    }
}
