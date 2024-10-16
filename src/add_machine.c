#include "main.h"

void add_machine()
{
    int p_id;
    int m_id;
    int m;
    struct plant* p_temp = p_start;

    printf("Enter the Plant ID where machine is to be added: ");
    scanf("%d", &p_id);

    // Find the plant with the given ID
    while (p_temp != NULL && p_temp->plant_id != p_id) {
        p_temp = p_temp->plink;
    }

    if (p_temp != NULL) {
        printf("Plant with ID %d found. Adding machines...\n", p_id);

        printf("Enter the number of machines to be added: ");
        scanf("%d", &m);

        for (int i = 0; i < m; i++) {
            struct machine* new_machine = (struct machine*)malloc(sizeof(struct machine));
            if (new_machine == NULL) {
                printf("Memory allocation failed!\n");
                return; // Exit if memory allocation fails
            }

            printf("Enter machine ID %d: ", i + 1);
            scanf("%d", &m_id);
            new_machine->machine_id = m_id;

            // Get additional attributes for the new machine
            printf("Enter machine name %d: ", i + 1);
            scanf("%s", new_machine->machine_name);
            printf("Enter start time (HH:MM) for machine %d: ", i + 1);
            scanf("%d:%d", &new_machine->start_time.hour, &new_machine->start_time.minute);
            printf("Enter stop time (HH:MM) for machine %d: ", i + 1);
            scanf("%d:%d", &new_machine->stop_time.hour, &new_machine->stop_time.minute);
            printf("Enter production for machine %d: ", i + 1);
            scanf("%d", &new_machine->production);
            new_machine->cycle_time = calculate_cycle_time(new_machine->start_time, new_machine->stop_time);

            new_machine->mlink = NULL; // Initialize link to NULL

            if (p_temp->mlink == NULL) {
                // If there are no machines, set the first machine
                p_temp->mlink = new_machine;
            } else {
                // Traverse to the end of the machine list
                struct machine* m_temp = p_temp->mlink;

                while (m_temp->mlink != NULL) {
                    m_temp = m_temp->mlink;
                }
                m_temp->mlink = new_machine; // Insert at the end
            }
        }
        printf("Machines added successfully!\n");
    } else {
        printf("Plant not found!\n");
    }
}
