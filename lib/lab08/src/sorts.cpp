#include "../inc/sorts.h"



int partition(std::vector<unsigned> & a, int s, int e) {
    unsigned int pivot = a[s];
    unsigned int l = s+1;
    unsigned int r = e;
    unsigned int tmp;


    while (l != r) {
        if (a[l]  <= pivot) l++;
        else {
            while (( l != r)  && (pivot < a[r])) r--;

            tmp =  a[r];
            a[r] = a[l];
            a[l] = tmp;
        }
    }

    if (a[l]>pivot) l--;
    a[s] = a[l];
    a[l] = pivot;


    return (l);
}
void quickSort(std::vector <unsigned> & a, int p, int r) {
    if (p < r) {
        unsigned q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}


lab6::doubly_linked_list sorts::insertion_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;

    for (int i = 0; i < iterations+1; i++) {

        for(int j=i; j>0 && working_list.get_data(j)<working_list.get_data(j-1); j--)
        {
            working_list.swap(j-1, j);
        }

    }

    return working_list;
}

lab6::doubly_linked_list sorts::selection_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;


    std::vector<unsigned> v;
    v = working_list.get_set(0,working_list.get_size()-1);

    int min, j, i, temp;

    for(i=0; i<iterations; i++)
    {
        min = i;
        for(j= i+1; j<iterations+1;j++)
        {
            if(v[j]<v[min])
            {
                min = j;
                temp = v[min];
                v[min]= v[i];
                v[i] = temp;
            }
        }
    }


    lab6::doubly_linked_list v_list(v);
    working_list = v_list;

    return working_list;
}

lab6::doubly_linked_list sorts::bubble_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    int i, j, flag_swap=1;
    int temp;

    for(i=0; i<iterations+1; ++i)
    {
        for(j=0; j<(iterations); j++)
        {
            if(working_list.get_data(j)>working_list.get_data(j+1))
            {
                working_list.swap(j, j+1);
            }
        }
    }

    return working_list;

}

lab6::doubly_linked_list sorts::cocktail_sort(lab6::doubly_linked_list input, int iterations) {
    lab6::doubly_linked_list working_list = input;
    bool swap= true;
    int i, j;

    while(swap) {
        swap = false;
        for (i = 0; i < iterations+4; i++) {
            if(working_list.get_data(i)>working_list.get_data(i+1))
            {
                working_list.swap(i, i + 1);
                swap = true;
            }

        }

        if (!swap) break;

        swap = false;

        for (j = iterations+4; j >= 0; j--) {
            if (working_list.get_data(j) > working_list.get_data(j+1)) {
                working_list.swap(j, j+1);
                swap = true;
            }
        }
    }

    return working_list;

    return working_list;
}

lab6::doubly_linked_list sorts::quick_sort(lab6::doubly_linked_list input) {
    std::vector<unsigned> v;
    v = input.get_set(0, input.get_size()-1);
    quickSort(v,0,v.size()-1);
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::merge_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}

lab6::doubly_linked_list sorts::radix_sort(lab6::doubly_linked_list input) {
    return lab6::doubly_linked_list();
}
