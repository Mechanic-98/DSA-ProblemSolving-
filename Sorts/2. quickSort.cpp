int partition(int input[], int start, int end)
{
    int pivot = input[start];
    int count_smaller_elements = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (input[i] <= pivot)
            count_smaller_elements++;
    }

    int pivot_point = start + count_smaller_elements;
    // swap(input[pivot_point], input[start]);
    int temp = input[pivot_point];
    input[pivot_point] = input[start];
    input[start] = temp;
    int i = start, j = end;

    while (i < pivot_point && j > pivot_point)
    {
        while (input[i] <= pivot)
            i++;
        while (input[j] > pivot)
            j--;
        if (i < pivot_point && j > pivot_point)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }

    return pivot_point;
}

void quickSortHelper(int input[], int start, int end)
{
    if (start >= end)
        return;

    int pivot_point = partition(input, start, end);
    quickSortHelper(input, start, pivot_point - 1);
    quickSortHelper(input, pivot_point + 1, end);
}

void quickSort(int input[], int size)
{

    quickSortHelper(input, 0, size - 1);
}