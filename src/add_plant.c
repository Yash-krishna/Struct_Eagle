#include "main.h"

void add_plant(struct plant* head)
{
    int pos, id, np;
    char name[20];
  //  struct plant* p_start = NULL;

    printf("Enter the number of plants to be added: ");
    scanf("%d", &np);

    for (int i = 0; i < np; i++)
    {
	printf("\n");
        printf("Enter the position to add plant %d: ", i + 1);
        scanf("%d", &pos);

        printf("Enter Plant ID: ");
        scanf("%d", &id);

        printf("Enter Plant Name: ");
        scanf("%s", name);

        struct plant *new_plant = (struct plant *)malloc(sizeof(struct plant));
        new_plant->plant_id = id;
        strcpy(new_plant->plant_name, name);
        new_plant->mlink = NULL;
        new_plant->plink = NULL;

        if (pos < 1)
        {
            printf("Invalid position!\n");
            free(new_plant);
            return;
        }

        if (pos == 1)
        {
            new_plant->plink = p_start;
            p_start = new_plant;
        }
        else
        {
            struct plant *temp = p_start;
            int current_position = 1;

            while (temp != NULL && current_position < pos - 1)
            {
                temp = temp->plink;
                current_position++;
            }

            if (temp == NULL)
            {
                printf("Position is out of bounds!\n");
                free(new_plant);
                return;
            }

            new_plant->plink = temp->plink;
            temp->plink = new_plant;
        }
        printf("Plant added successfully\n");
    }
}
