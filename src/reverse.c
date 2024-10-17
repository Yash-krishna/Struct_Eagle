#include "main.h"

// Function to traverse and print plants and machines in reverse order
void traverse_reverse(struct plant *head)
{
    if (head == NULL) {
        return; // Base case: if the plant list is empty, return
    }

    // Recursive call to traverse the next plant
    traverse_reverse(head->plink);

    // Print the current plant's information
    int mprod = 0;
    printf("Plant ID: %d, Plant Name: %s\n", head->plant_id, head->plant_name);

    struct machine *temp_m = head->mlink;

    // Print each machine's information
    while (temp_m != NULL)
    {
        printf("   Machine ID: %d, Machine Name: %s, Start Time: %02d:%02d, Stop Time: %02d:%02d, Cycle Time: %.2f hours, Production: %d\n",
               temp_m->machine_id,
               temp_m->machine_name,
               temp_m->start_time.hour, temp_m->start_time.minute,
               temp_m->stop_time.hour, temp_m->stop_time.minute,
               temp_m->cycle_time, temp_m->production);

        mprod += temp_m->production;
        temp_m = temp_m->mlink;
    }

    // Print total production for the current plant
    printf("\nPlant %s production is %d\n", head->plant_name, mprod);
}
