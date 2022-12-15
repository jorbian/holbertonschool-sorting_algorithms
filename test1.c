#include "sort.h"

int main()
{
    int i = 0;
    int current_value[2];
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    for (i = 0; (i <= n - 2); i++)
    {
        current_value[0] = array[i];
        current_value[1] = array[i + 1];

        if (current_value[0] < current_value[1])
        {
            array[i] = current_value[1];
            array[i + 1] = current_value[0];
        }

        print_array(array, n);
    }
    return (0);
}