#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TYPE 3
#define DESCRIPTION 30
char Slot_Type[TYPE][DESCRIPTION] = {"Ground", "Hill", "City"};
struct Players
{
	char name[50];
	char type[50];
	char slotType[50];
	int slotNum;
	int numType;
	int num;
	int lifepoints;
	int smartness;
	int strength;
	int magic;
	int luck;
	int dexterity;
}players[6];

struct Slots
{
	char TypeofSlot[50];
	int slotNum;
	int typeNum;
	char type[DESCRIPTION];
	int player;
}slots[20];

int main(void)
{
printf("------------------Player Information---------------\n");
srand(time(NULL));
int NumberofPlayers,i,j;
struct Slots slot[20];
struct Players player[6];
struct Players name[50];
struct Players type[50];
printf("please enter the amount of players (max of 6)\n");
scanf("%d", &NumberofPlayers);
printf("please enter the name of each player (Ogre,Human,Ogre or Wizard)\n");
for(i=0;i<NumberofPlayers;i++)
{
	scanf("%s", &name[i]);
}
printf("please enter a type for each player\n");
for(i=0;i<NumberofPlayers;i++)
{
	scanf("%s",&type[i]);
}
printf("------------------Slot Information------------------\n");
int SizeofSlots;
printf("enter the number of slots you wish to use(Max of 20)\n");
scanf("%d", &SizeofSlots);
printf("\n");
	for(i=0;i<SizeofSlots;i++)
	{
		j = 1+rand()%3;
		if(j == 1)
		{
			strcpy(slot[i].TypeofSlot, "Ground");
		}
		if(j == 2)
		{
			strcpy(slot[i].TypeofSlot, "City");	
		}
		if(j == 3)
		{
			strcpy(slot[i].TypeofSlot, "Hill");
		}
	}
	for(i=0;i<SizeofSlots;i++)
	{
		printf("(%d, %s)->",i+1,slot[i].TypeofSlot);
	}


return 0;
}

	