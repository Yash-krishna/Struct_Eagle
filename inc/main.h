#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct time{
	int hour;
	int minute;
};

struct plant {
	int plant_id;
	char plant_name[20];
	struct machine *mlink;
	struct plant *plink;
};

struct machine {
	int machine_id;
	char machine_name[20]; 
	struct time start_time; 
	struct time stop_time;
	float cycle_time;
	int production;
	struct machine *mlink;
};


extern struct machine* m_start;
extern struct plant* p_start;

void traverse_m(struct machine* head);
void traverse_p(struct plant* head);
void display_menu();
void display(struct plant* head);
struct plant *create_plant(void);
void traverse(struct plant *head);
float calculate_cycle_time(struct time start, struct time stop);

void add();
void add_plant(struct plant* head);
void add_machine();
void deletee();
void delete_machine();
void delete_plant();
