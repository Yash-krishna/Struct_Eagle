#include "main.h"

void traverse_m(struct machine *mhead) 
{
    struct machine *temp_m = mhead;

    if (mhead == NULL)
    {
        printf("No machines available.\n");
        return;
    }

    while (temp_m != NULL)
    {
        printf("Machine ID: %d\n", temp_m->machine_id);
        printf("Machine Name: %s\n", temp_m->machine_name);
        printf("Start Time: %02d:%02d\n", temp_m->start_time.hour, temp_m->start_time.minute);
        printf("Stop Time: %02d:%02d\n", temp_m->stop_time.hour, temp_m->stop_time.minute);
        printf("Cycle Time: %lf minutes\n", temp_m->cycle_time);
        printf("Production: %d\n", temp_m->production);

        temp_m = temp_m->mlink;  // Move to the next machine
        printf("\n");
    }
}
