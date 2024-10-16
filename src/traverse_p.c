#include "main.h"

void traverse_p(struct plant *phead) 
{
    struct plant *temp_p = phead;

    if (phead == NULL)
    {
        printf("No plants available.\n");
        return;
    }

    while (temp_p != NULL)
    {
        printf("Plant ID: %d\n", temp_p->plant_id);
        printf("Plant Name: %s\n", temp_p->plant_name);

        temp_p = temp_p->plink; 
        printf("\n");
    }
}
