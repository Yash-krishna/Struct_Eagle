#include "main.h"

struct machine* m_start = NULL;
struct plant* p_start = NULL;

int main()
{
	int choice;
	struct plant* result = NULL;

	while(1)
	{
		display_menu();

		printf("Enter the choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				p_start = create_plant();
				break;

			case 2:
				add();
				break;

			case 3:
				deletee();
				break;

			case 5:
				display(p_start);
				break;

			case 8:
				exit(0);

			default:
				printf("Invalid choice!!\n");
		}
	}
}
