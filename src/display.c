#include "main.h"

void display(struct plant* head)
{
	int choice;

	printf("1.Display plants\n");
	printf("2.Display machines\n");
	printf("3.Display all\n\n");

	printf("Enter the choice :");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			traverse_p(head);
			break;

		case 2:
			struct plant *current_plant = head;
    			while (current_plant != NULL)
    			{
        			printf("Machines for Plant ID %d (%s):\n", current_plant->plant_id, current_plant->plant_name);
        			traverse_m(current_plant->mlink);  // Display machines for this specific plant

			        current_plant = current_plant->plink;  // Move to the next plant
    			}
			break;

		case 3:
			traverse(head);
			break;

		default:
			printf("Invalid choice!!\n");
	}
	printf("\n");
}
