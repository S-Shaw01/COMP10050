#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define NO_PLAYER -1

struct Players
{
	char name[50];//structs for players
	char type[50];
	char currentSlot[20];
	int lifepoints;	//stats
	int smartness;
	int strength;
	int magic;
	int luck;
	int dexterity;
	int position;
}players[6];

struct Slots//struct for slots
{
	char TypeofSlot[50];
	int SizeofSlots;
	int typeNum;
	int player;
	bool taken;
}slots[20];

void human(struct Players *player);
void ogre(struct Players *player);
void elf(struct Players *player);
void wizard(struct Players *player);
void SlotAssign(int NumberofPlayers, int SizeofSlots, struct Players player[], struct Slots slot[]);
void playerAttack(struct Players player[], struct Slots slot[], int *c, int i, int NumberofPlayers, int SizeofSlots);

int main(void)
{
printf("-------------------------------------------------\n");
printf("-----------    Player Information    ------------\n");
printf("-------------------------------------------------\n");
setbuf(stdout,NULL);
srand(time(NULL));
int NumberofPlayers,i=0,j,n,b,c,x,y,a;

struct Players *player;
const char Player_type_human[10] = "Human";
const char Player_type_elf[10] = "Elf";
const char Player_type_ogre[10] = "Ogre";
const char Player_type_wizard[10] = "Wizard";
char *Slot_Type[3]={"Ground","Hill","City"};
struct Slots slot[20];



do{
printf("please enter the amount of players (max of 6)\n");
scanf("%d", &NumberofPlayers);
	if(NumberofPlayers <=0 || NumberofPlayers>6)//enter number of players
	{
		printf("\nMax number of players is 6,please enter a valid number\n\n");
	}
}
while(NumberofPlayers<=0 || NumberofPlayers>6);
printf("please enter the name of each player\n");
for(i=0;i<NumberofPlayers;i++)
{
	scanf("%s", &player[i].name);//scan in names and store them in player[i].name
}
printf("please enter the type of each player\n");
for(i=0;i<NumberofPlayers;i++)
{
	printf("human\togre\telf\twizard\t\n");
	scanf("%s", &player[i].type);//scan in the types
	player[i].lifepoints = 100;//sets all players lifepoints to 100
}
printf("\n");
printf("-------------------------------------------\n");
printf("------------    Player Stats    -----------\n");
printf("-------------------------------------------\n");
for(i=0;i<NumberofPlayers;i++)
{
	if(strstr(player[i].type,Player_type_human)==0)
	{
		human(&player[i]);// if what is types is simialr to human,call function
	}
	else if(strstr(player[i].type,Player_type_ogre)==0)
	{
		ogre(&player[i]);// if what is types is simialr to ogre,call function
	}
	else if(strstr(player[i].type,Player_type_elf)==0)
	{
		elf(&player[i]);//if what is typed is similar to elf,call function
	}
	else if(strstr(player[i].type,Player_type_wizard)==0)
	{
		wizard(&player[i]);//if what is typed is similar to wizard,call function
	}
	
}
for(i=0;i<NumberofPlayers;i++)
	{
		printf("\n -Player %d -\n", i+1);//prints each players stats
		printf("Name:\t\t%s\n", player[i].name);
		printf("Type:\t\t%s\n", player[i].type);
		printf("Lifepoints:\t\t%d\n", player[i].lifepoints);
		printf("Smartness:\t\t%d\n", player[i].smartness);
		printf("Strength:\t\t%d\n", player[i].strength);
		printf("Magic:\t\t\t%d\n", player[i].magic);
		printf("Luck:\t\t\t%d\n", player[i].luck);
		printf("dexterity:\t\t%d\n", player[i].dexterity);	
		printf("\n");
	}
printf("----------------------------------------------------\n");
printf("--------------    Slot Information    --------------\n");
printf("----------------------------------------------------\n");
int SizeofSlots;
do
{
	printf("enter the number of slots you wish to use(Max of 20)\n");
	scanf("%d",&SizeofSlots);
	if(SizeofSlots<=0 || SizeofSlots >20)//number of slots
	{
		printf("\nMax number of slots is 20,please enter a valid number\n\n");
	}
}
while(SizeofSlots<1 || SizeofSlots>20);


printf("\n");
	for(i=0;i<SizeofSlots;i++)
	{
		j = 1+rand()%3;//chooses random number between 1=3
		if(j == 1)
		{
			strcpy(slot[i].TypeofSlot, "Ground");// if 1, type = ground
		}
		if(j == 2)
		{
			strcpy(slot[i].TypeofSlot, "City");	//if 2, type = city
		}
		if(j == 3)
		{
			strcpy(slot[i].TypeofSlot, "Hill");//if 3, type = hill
		}
	}
	for(i=0;i<SizeofSlots;i++)
	{
		printf("%d\t%s\n",i+1, slot[i].TypeofSlot);//prints slots
	}
	SlotAssign(NumberofPlayers,SizeofSlots,players,slots);//assign players to slots
	for(i=0;i<NumberofPlayers;i++)
	{//prints the slot each player is in
	printf("=== SLOTS ===\nPlayer:%s\nPosition: %d\n",player[i].name, players[i].position + 1);
	}
	printf("\n");
	printf("\n-----Begin-----\n");
	
int choice,choice2;
for(i=0;i<NumberofPlayers;i++)
{
	printf("Player %d %s\n", i, player[i].name);//moves players
	printf("enter 1 to move, 2 to attack");
	scanf("%d", &choice);
	if(choice == 1)
	{
		printf("choice 1 to move forward\nChoice 2 to move backwards\n");
		scanf("%d",&choice2);
		if(choice2 == 1)
		{
			players[i].position +=2;
		}
		if(choice2 == 2)
		{
			players[i].position -= 1;
		}
		if(strcmp(slot[i].TypeofSlot, "Hill")==0)//if player is on this slot, change stats
		{
			if(player[i].dexterity <  50)
			{
				player[i].strength = player[i].strength - 10;
			}
			if(player[i].strength<0)
			{
				player[i].strength = 0;//if stat falls below 0,set to 0
			}
	
		}
		if(player[i].dexterity >= 60)
		{
			player[i].strength = player[i].strength + 10;
			if(player[i].strength>100)
			{
				player[i].strength = 100;//if strenght is over 100,set to 100
			}
		}
	}
	if(strcmp(slot[i].TypeofSlot, "City")==0)//if player is on this type, change stats
	{
		if(player[i].smartness > 60)
		{
			player[i].magic = player[i].magic + 10;
			if(player[i].magic > 100)
			{
				player[i].magic = 100;
			}
		}
		if(player[i].smartness <= 50)
		{
			player[i].dexterity = player[i].dexterity - 10;
			if(player[i].dexterity<0)
			{
				player[i].dexterity=0;//if dex falls below 0,set to 0
			}
		}
	}//prints each players new location
	printf("new location of %s = %d\n", player[i].name, players[i].position);
}
if(choice == 2)
{
	playerAttack(player,slot,&c,a,NumberofPlayers,SizeofSlots);
	if(c == 234)
	{
		i--;
	}
	else
	{
		printf("invalid choice, please choose again\n");
	}
	c-=1;
}
printf("the game is over \n---- Final Stats----\n");
for(i=0;i<NumberofPlayers;i++)//prints the players name,type and remaining lifepoints
{
	printf("%s (%s, %d)\n", player[i].name, player[i].type, player[i].lifepoints);
}

return 0;
}
void human(struct Players *player)
{
	int stats[5], sum, i;		//sets stats for humans
	do
	{										
		sum = 0;							
		for(i=0; i<5; i++)
		{					
			stats[i] = 1+rand() % 100;	
			sum += stats[i];				
		}
	}
	while(sum >= 300);//while total stats are lower than 300
											
	player->smartness = stats[0];			
	player->strength = stats[1];			
	player->magic = stats[2];		
	player->luck = stats[3];				
	player->dexterity = stats[4];
	
}
void ogre(struct Players *player)
{
	int stats[2],total;
	do//stats for ogres
	{
		total=0;
		stats[0]=1+(rand()%20);
		stats[1]=1+(rand()%100);
		total = stats[1]+stats[0];
	}
	while(total>50);
	
		player->smartness = stats[0];
		player->strength = 80+(rand()%21);
		player->magic = 0;
		player->luck = stats[1];
		player->dexterity = 80+(rand()%21);
	
}
void elf(struct Players *player)
{
	player->smartness = 70+(rand()%31);//stats for elves
	player->strength = rand()%50;
	player->magic = 50+(rand()%29);
	player->luck = 60+(rand()%41);
	player->dexterity = rand()%100;
}
void wizard(struct Players *player)
{//stats for wizards
	player->smartness = 90+(rand()%11);
	player->strength = rand()%20;
	player->magic = 80+(rand()%21);
	player->luck = 50+(rand()%51);
	player->dexterity = rand()%100;
}
void SlotAssign(int NumberofPlayers, int SizeofSlots, struct Players player[], struct Slots slot[])
{
	int i,j;
	for(i=0;i<SizeofSlots;i++)//assigns players to slots
	{
		slot[i].taken = false;
	}
	for(i=0;i<NumberofPlayers;i++)
	{
		j=rand()%SizeofSlots;
		while(slot[j].taken == true)
		{
			j=rand()%SizeofSlots;
		}
		player[i].position = j;
		slot[j].taken = true;
	}
}
void playerAttack(struct Players player[], struct Slots slot[], int *c, int i, int NumberofPlayers, int SizeofSlots)
{//couldnt actually get the attacking to work but this is my attempt
	int b, ch=-1;
	bool leftSlot=false, rightSlot=false;

	if(slot[players[i].position-1].taken==true) // If a player is to the left of you
	{
		leftSlot=true;
	}
	if(slot[players[i].position+1].taken==true) // If a player is to the right of you
	{
		rightSlot=true;
	}
	if(players[i].position==0) // Stop player from attacking to the left in slot 0
	{
		leftSlot=false;
	}
	if(players[i].position==SizeofSlots-1) // Stop player from attacking to the right in the max slot
	{
		rightSlot=false;
	}

	if(leftSlot && !rightSlot) // If there is a player to the left only
	{
		printf("You are attacking the player to your left in slot %d.\n", players[i].position);
		for(b=0; b<NumberofPlayers; b++) // Checking which player is beside the attacker
		{
			if(players[i].position-1==players[b].position)
			{
				if(player[b].strength<=70) // Case 1
				{
					player[b].lifepoints-=(player[b].strength*5)/10;
				}
				if(player[b].strength>70) // Case 2
				{
					player[i].lifepoints-=(player[b].strength*3)/10;
				}
			}
		}
	}

	if(!leftSlot && rightSlot) // If there is a player to the right only
	{
		printf("You are attacking the player to your right in slot %d.\n", players[i].position+2);
		for(b=0; b<NumberofPlayers; b++)
		{
			if(players[i].position+1==players[b].position)
			{
				if(player[b].strength<=70)
				{
					player[b].lifepoints-=(player[b].strength*5)/10;
				}
				if(player[b].strength>70)
				{
					player[i].lifepoints-=(player[b].strength*3)/10;
				}
			}
		}
	}

	if(leftSlot && rightSlot)
	{
		while(ch<0) // Error checking
		{
			printf("Do you want to attack the player to your left[1] (slot %d) or the right[2] (slot %d)?\n", players[i].position, players[i].position+2); // Add nothing and 2 to the position to allow the natural number system can be used (1,2....n)
			scanf("%d", &ch);
			if(ch==1)
			{
				printf("You are attacking the player to your left in slot %d.\n", players[i].position);
				for(b=0; b<NumberofPlayers; b++)
				{
					if(players[i].position-1==players[b].position)
					{
						if(player[b].strength<=70)
						{
							player[b].lifepoints-=(player[b].strength*5)/10;
						}
						if(player[b].strength>70)
						{
							player[i].lifepoints-=(player[b].strength*3)/10;
						}
					}
				}
			}
			else if(ch==2)
			{
				printf("You are attacking the player to your right in slot %d.\n", players[i].position+2);
				for(b=0; b<NumberofPlayers; b++)
				{
					if(players[i].position+1==players[b].position)
					{
						if(player[b].strength<=70)
						{
							player[b].lifepoints-=(player[b].strength*5)/10;
						}
						if(player[b].strength>70)
						{
							player[i].lifepoints-=(player[b].strength*3)/10;
						}
					}
				}
			}
			else
			{
				printf("Invalid option, please try again.\n");
				ch=-1;
			}
		}
	}

	if(!leftSlot && !rightSlot) // If there are no adjacent players
	{
		printf("There are no players beside you to attack, you have to move.\n");
		*c=234; // Allow person to choose again, using garbage value so user doesn't input accidentally
	}
}