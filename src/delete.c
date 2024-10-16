#include "main.h"

void deletee()
{
        int choice;

        printf("1.Delete plant\n");
        printf("2.Delete machine\n\n");

        printf("Enter the choice:");
        scanf("%d",&choice);

        switch(choice)
        {
                case 1:
                        delete_plant();
                        break;

                case 2:
                        delete_machine();
                        break;

                default:
                        printf("Invalid choice!\n");
        }
        printf("\n");

}
