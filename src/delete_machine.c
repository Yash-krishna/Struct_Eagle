#include "main.h"

void delete_machine()
{
	int p_id;
	int m_id;
	
	struct plant* p_temp = p_start;

	printf("Enter the plant ID:");
	scanf("%d",&p_id);

	while(p_temp != NULL && p_temp->plant_id != p_id)
	{
		p_temp = p_temp->plink;
	}

	//if there is only 1 machine
	if(p_temp != NULL)
	{
		struct machine* m_current = p_temp->mlink;

		printf("Enter the machine ID to be deleted:");
		scanf("%d",&m_id);

		if(m_current == NULL)
		{
			printf("No machines available in plant with ID %d.\n", p_id);
//			return;
		}

		if(m_current->mlink == m_current && m_current->machine_id == m_id)
		{
			free(m_current);
			p_temp->mlink = NULL;
			printf("Machine with ID %d removed from plant %d.\n", m_id, p_id);
			return;
		}

		//more than1 machine
		struct machine* m_prev = NULL;
		do
		{
			if (m_current->machine_id == m_id)
			{
				if(m_prev == NULL)
				{
					struct machine* m_last = m_current;
					while (m_last->mlink != p_temp->mlink)
					{
						m_last = m_last->mlink;
					}
					p_temp->mlink = m_current->mlink;
					m_last->mlink = p_temp->mlink;
				}
				else
				{
					m_prev->mlink = m_current->mlink;
				}
				free(m_current);
				printf("Machine with ID %d removed from plant %d.\n", m_id, p_id);
				return;
			}
			m_prev = m_current;
			m_current = m_current->mlink;
		}while(m_current != p_temp->mlink);
		printf("Machine with ID %d not found in plant %d.\n", m_id, p_id);
    	}
	else
		printf("Plant with ID %d not found\n",p_id);
}

