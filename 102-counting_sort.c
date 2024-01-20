#include "sort.h"

/**
 * get_max - Gets the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The max integer in the array.
 */
int get_max(int *array, int size)
{
    int max, i;

    if (array == NULL || size <= 0)
        return 0;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    int max, i;

    if (array == NULL || size < 2)
        return;

    max = get_max(array, size);
    count_array = malloc(sizeof(int) * (max + 1));

    if (count_array == NULL)
        return;

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_array[array[i]] += 1;

    print_array(count_array, max + 1);

    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    for (i = (int)size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(count_array);
}

