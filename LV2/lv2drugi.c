#include <stdio.h>

#define RAM_SIZE_GB 16 
#define RESERVED_MEMORY_GB 2 
#define AVAILABLE_MEMORY_GB (RAM_SIZE_GB - RESERVED_MEMORY_GB) 
#define BYTES_PER_INT 4 

int maksimalni_broj_elemenata_niza() {
    long long available_memory_bytes = (long long)AVAILABLE_MEMORY_GB * 1024 * 1024 * 1024;
    int max_elements = available_memory_bytes / BYTES_PER_INT; 
    return max_elements;
}

int maksimalni_broj_elemenata_povezanog_popisa() {
    int size_of_pointer = sizeof(void*); 
    int size_of_node = BYTES_PER_INT + size_of_pointer;
    long long available_memory_bytes = (long long)AVAILABLE_MEMORY_GB * 1024 * 1024 * 1024;
    int max_elements = available_memory_bytes / size_of_node; 
    return max_elements;
}

int main() {
    int max_elements_array = maksimalni_broj_elemenata_niza();
    printf("Maksimalni broj elemenata za niz: %d\n", max_elements_array);

    int max_elements_linked_list = maksimalni_broj_elemenata_povezanog_popisa();
    printf("Maksimalni broj elemenata za povezani popis: %d\n", max_elements_linked_list);

    return 0;
}
