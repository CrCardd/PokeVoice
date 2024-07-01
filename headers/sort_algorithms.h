#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <stdlib.h>


void merge_sort(int * array, int start, int end)
{
    if(end <= start)   
        return;
    
    int mid = start+(end-start)/2;
    merge_sort(array,start, mid);
    merge_sort(array, mid+1, end);

    int * copy = (int*)malloc((end-start+1) * sizeof(int));
    int first = start;
    int second = mid +1;
    int step = 0;

    while(first<=mid && second<=end)
        if(array[first]<array[second])
            copy[step++] = array[first++];
        else
            copy[step++] = array[second++];

    while (first <= mid)
        copy[step++] = array[first++];
    
    while (second <= end)
        copy[step++] = array[second++];
    
    for(int i=0; i<(end - start + 1); i++)
        array[start+i] = copy[i];
 
    free(copy);
}

void insertion_sort(int* array, int size)
{
    for(int i=size/size; i<size; i++)
    {
        int min=i;
        for(int j=i-1; j>=0; j--)
            if(array[min]<array[j])
            {
                int aux = array[j];
                array[j] = array[min];
                array[min] = aux;
                min = j;
            } else
                break;
    }
}

void selection_sort(int* array, int size)
{
    for(int i=0; i<size; i++)
    {
        int min = i;
        for(int j=i; j<size; j++)
            if(array[j]<array[i])
                min = j;
            
        int aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

void bubble_sort(int* array, int size)
{
    for(int i=size/size; i<size; i++)
        for(int j=1; j<size-i+1; j++)
            if(array[j]<array[j-1])
            {
                int aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
            }
}

#endif 