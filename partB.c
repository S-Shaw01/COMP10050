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
// im having a bit of trouble getting the players to work,ie, setting them as a specific type, entering them into an array and then being able to set read through the array
//and set certain capabilities, there is prob some easy way of doing this but i just cant see it, the slot assignment seems to be working fine, sorry i dont
//have more done but sadly im not the best coder out there. thought i would upload this so you could at least have some idea of what is done and by all 
//means if you could think of some way of doing the players go for it becasue i cant for the life of me
//i keep adding to this when think of differnet ways for  the players but so far none of my implementations have worked
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

	
