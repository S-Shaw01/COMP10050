#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define TYPE 3
#define DESCRIPTION 30
char Slot_Type[TYPE][DESCRIPTION] = {"Ground", "Hill", "City"};//sd array of the type of slots
struct Players//struct of players
{
	char name[50];//stores players name
	char type[50];//stores players types
	int lifepoints;//stores lifepoints
	int smartness;//stores the smartness figure
	int strength;//stores the strength figure
	int magic;//stores the magic figure
	int luck;//stores the luck figure
	int dexterity;//stores the dexterity figure
	int position;//stores the players position in the slot array
	int slotNum;//number representation of the slot
}players[6];

struct Slots//struct of slots
{
	char TypeofSlot[50];//stores type of slot
	int slotNum;//the position of the slot ie 0 = the first position in the slot
	int typeNum;//stores the slot type as a number between 1-3
	int player;//player occupying the slot position
	bool taken;//depending on whether the position is taken or not
	int free;
}slots[20];
void human(struct Players *player);//function to determine the capabilities of the human players by pointing to the struct
void ogre(struct Players *player);//function to determine the capabilities of the ogre players by pointing to the struct
void elf(struct Players *player);//function to determine the capabilities of the elf players by pointing to the struct
void wizard(struct Players *player);//function to determine the capabilities of the wizard players by pointing to the struct
void SlotAssign(int NumberofPlayers, int SizeofSlots, struct Players player[], struct Slots slot[]);//assign players to slots

int main(void)
{
printf("-------------------------------------------------\n");
printf("-----------    Player Information    ------------\n");
printf("-------------------------------------------------\n");
setbuf(stdout,NULL);
srand(time(NULL));//seeds the random numbers
int NumberofPlayers,i=0,j,y;
struct Players *player;//pointer to struct players
const char Player_type_human[10] = "Human";//used to compare types
const char Player_type_elf[10] = "Elf";//used to compare types
const char Player_type_ogre[10] = "Ogre";//used to compare types
const char Player_type_wizard[10] = "Wizard";//used to compare types
struct Slots slot[20];//calling on the struct slots
do{
printf("please enter the amount of players (max of 6)\n");
scanf("%d", &NumberofPlayers);
	if(NumberofPlayers <=0 || NumberofPlayers>6)
	{
		printf("\nMax number of players is 6,please enter a valid number\n\n");//scans in the number of players within the range 1-6
	}
}
while(NumberofPlayers<=0 || NumberofPlayers>6);
printf("please enter the name of each player\n");
for(i=0;i<NumberofPlayers;i++)
{
	scanf("%s", &player[i].name); //enter the names of each player
}
printf("please enter the type of each player\n");
for(i=0;i<NumberofPlayers;i++)
{
	printf("human\togre\telf\twizard\t\n");
	scanf("%s", &player[i].type); //scans the types of players into player[i].type
	player[i].lifepoints = 100;
}
printf("\n");
printf("-------------------------------------------\n");
printf("------------    Player Stats    -----------\n");
printf("-------------------------------------------\n");
for(i=0;i<NumberofPlayers;i++)
{
	if(strstr(player[i].type,Player_type_human)==0)//if player[i].type contains the word Humans, enter the if statement
	{
		human(&player[i]);
	}
	else if(strstr(player[i].type,Player_type_ogre)==0)//if player[i].type contains the word Ogre, enter the if statement
	{
		ogre(&player[i]);
	}
	else if(strstr(player[i].type,Player_type_elf)==0)//if player[i].type contains the word Elf, enter the if statement
	{
		elf(&player[i]);
	}
	else if(strstr(player[i].type,Player_type_wizard)==0)//if player[i].type contains the word Wizard, enter the if statement
	{
		wizard(&player[i]);
	}

}
for(i=0;i<NumberofPlayers;i++)
	{
		printf("\n -Player %d -\n", i+1);
		printf("Name:\t\t%s\n", player[i].name);
		printf("Type:\t\t%s\n", player[i].type);
		printf("Lifepoints:\t\t%d\n", player[i].lifepoints);
		printf("Smartness:\t\t%d\n", player[i].smartness);//prints out the stats of all players entered
		printf("Strength:\t\t%d\n", player[i].strength);
		printf("Magic:\t\t%d\n", player[i].magic);
		printf("Luck:\t\t%d\n", player[i].luck);
		printf("Dexterity:\t\t%d\n", player[i].dexterity);
		printf("\n");
	}
printf("----------------------------------------------------\n");
printf("--------------    Slot Information    --------------\n");
printf("----------------------------------------------------\n");
int SizeofSlots;
do
{
	printf("enter the number of slots you wish to use(Max of 20)\n");
	scanf("%d",&SizeofSlots);//scan in the size of the slots(the number of slots)
	if(SizeofSlots<=0 || SizeofSlots >20)
	{
		printf("\nMax number of slots is 20,please enter a valid number\n\n");
	}
}
while(SizeofSlots<1 || SizeofSlots>20);
printf("\n");
	for(i=0;i<SizeofSlots;i++)
	{
		j = 1+rand()%3;//randomly chooses a number between 1-3
		if(j == 1)
		{
			strcpy(slot[i].TypeofSlot, "Ground");//if number == 1 then copy GROUND into slot[i].TypeofSlot
		}
		if(j == 2)
		{
			strcpy(slot[i].TypeofSlot, "City");//if number == 2 then copy CITY into slot[i].TypeofSlot
		}
		if(j == 3)
		{
			strcpy(slot[i].TypeofSlot, "Hill");//if number == 3 then copy HILL into slot[i].TypeofSlot
		}
	}
	for(i=0;i<SizeofSlots;i++)
	{
		if(slots[i].player > -1)
		{
			j=slots[i].player;
			printf("%d\t%s\t\t%s\n",i+1,slot[i].TypeofSlot,player[i].name);// prints the slot number,type and if there is a player there
		}
		if(slots[i].player == -1)
		{
			printf("%d\t%s\t\t--\n",i+1,slot[i].TypeofSlot);//if there is no player then it doesn't print out a player
		}
	}
SlotAssign(NumberofPlayers,SizeofSlots,players,slots);
return 0;
}
void human(struct Players *player)
{
	int stats[5], sum, i;//stats array,filled wth numbers between 1-100 that gets distributed between the human stats

	do
	{
		sum = 0;
		for(i=0; i<5; i++)
		{
			stats[i] = rand() % 100 + 1;
			sum += stats[i];
		}
	}
	while(sum >= 300);//makes sure that the the total sum of stats isnt above 300

	player->smartness = stats[0];
	player->strength = stats[1];
	player->magic = stats[2];
	player->luck = stats[3];
	player->dexterity = stats[4];

}
void ogre(struct Players *player)
{
	int stats[2],total;//same as human but only with smartness and luck
	do
	{
		total=0;
		stats[0]=rand()%(21);//sets the range of possible values
		stats[1]=rand()%(101);//sets the range of possible values
		total = stats[1]+stats[0];
	}
	while(total>50);
	{
		player->smartness = stats[0];
		player->strength = (rand()%(100-80))+80;//range of possible values
		player->magic = 0;
		player->luck = stats[1];
		player->dexterity = (rand()%(100-80))+80;
	}
}
void elf(struct Players *player)
{
	player->smartness = (rand()%(100-70))+70;
	player->strength = rand()%50;
	player->magic = (rand()%(80-50))+50;
	player->luck = (rand()%(100-60))+60;
	player->dexterity = rand()%100;
}
void wizard(struct Players *player)
{
	player->smartness = (rand()%(100-90))+90;
	player->strength = rand()%20;
	player->magic = (rand()%(100-80))+80;
	player->luck = (rand()%(100-50))+50;
	player->dexterity = rand()%100;
}
void SlotAssign(int NumberofPlayers, int SizeofSlots, struct Players player[], struct Slots slot[])
{
	int i,j;
	for(i=0;i<NumberofPlayers;i++)
	{
		j=rand()%SizeofSlots;//j is assigned a random value based on the size of the slot array
		while(slot[j].taken==true)//if the slot is taken, j is assigned another random value
		{
			j=rand()%SizeofSlots;
		}
		player[i].position = j;// if the position isnt taken then the player takes that position
		slot[j].taken = true;
	}
}
