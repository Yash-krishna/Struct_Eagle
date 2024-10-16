#include "main.h"

void delete_plant() {
    	int p_id;
    	struct plant* p_temp = p_start;
    	struct plant* p_prev = NULL;

    	printf("Enter the Plant ID to delete: ");
    	scanf("%d", &p_id);

    
    	while (p_temp != NULL && p_temp->plant_id != p_id) 
	{
        	p_prev = p_temp;  
        	p_temp = p_temp->plink;  
    	}

       if (p_temp != NULL) 
       {   
	       if (p_temp == p_start && p_temp->plink == NULL) 
	       {
	   	       free(p_temp);
		       p_start = NULL;  
	   	       printf("Plant with ID %d deleted successfully.\n", p_id);
       	       } 
	       else 
	       {	         
		       if (p_temp == p_start) 
		       {
	       		       p_start = p_temp->plink;  
	   	       } 
		       else 
		       {
     			       p_prev->plink = p_temp->plink;
	   	       }
		       free(p_temp); // Free the memory
	               printf("Plant with ID %d deleted successfully.\n", p_id);
       	       }
       } 
       else 
       {     
	       printf("Plant with ID %d not found.\n", p_id);
       }
}
