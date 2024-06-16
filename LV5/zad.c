#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *V, int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && V[left] > V[largest])
        largest = left;

    if (right < n && V[right] > V[largest])
        largest = right;

    if (largest != i) {
        swap(&V[i], &V[largest]);

        heapify(V, n, largest);
    }
}

void heap_sort(int *V, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(V, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&V[0], &V[i]);

        heapify(V, i, 0);
    }
}

void bubble_sort(int *V, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (V[j] > V[j + 1]) {
                swap(&V[j], &V[j + 1]);
            }
        }
    }
}

void generate_random_array(int *V, int n) {
    for (int i = 0; i < n; i++) {
        V[i] = rand() % 1000; 
    }
}


int main() {
    int n = 1000;  
    int *V = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    generate_random_array(V, n);
    int *V_copy = (int *)malloc(n * sizeof(int));
    memcpy(V_copy, V, n * sizeof(int));

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    heap_sort(V, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort vrijeme: %f sekundi\n", cpu_time_used);

    start = clock();
    bubble_sort(V_copy, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort vrijeme: %f sekundi\n", cpu_time_used);

    free(V);
    free(V_copy);

    return 0;
}
