#include <stdio.h>
#include<conio.h>
#include <string.h>
struct cricket
{
     char name[50];
     char teamname[50];
     char sixers[50];
     char fours[50];
     char runs[50];
     float btavg;
};
 
int main()
{
struct cricket player[100];
int i,n;

char ch,team[100];

printf("How many player's Playing in a Match in both the Team's: \n");
scanf("%d",&n);

for (i=0;i<n;i++)
{
   printf("\nEnter Batsman/Player Name %d : ",i+1);
   scanf("%s",player[i].name);
   
   printf("\nEnter the team name of the Player %d : ",i+1);
   scanf("%s",player[i].teamname);
   
   printf("\n Enter Total Sixers Scored by the Batsman %d:",i+1);
   scanf("%s",player[i].sixers);
   
   printf("\n Enter Total Fours Scored by the Batsman %d :",i+1);
   scanf("%s",player[i].fours);
   
   printf("\n Enter Total Runs(1,2,3) Scored %d:",i+1);
   scanf("%s",player[i].runs);
   
   printf("\nINPUT THE BATTING AVERAGE OF PLAYER %d:",i+1);
   scanf("%f",&player[i].btavg);
   printf("\n\n");
}
 
 
      printf("=================================================================================================================\n");
      printf("PLAYER'S NAME      country          Sixers               Fours              runs              1BATTING AVERAGE\n");
      printf("=================================================================================================================\n");
      for (i=0; i<n; i++)
      {
	        printf("%-20s%-20s%-20s%-20s%-20s%f\n",player[i].name,player[i].teamname,player[i].sixers,player[i].fours,player[i].runs,player[i].btavg);
	  }
         
 
      read:
       printf("\n\nWant to see the List of the Players in a Team : ");
       scanf("%s",team);
 
      printf("\n               %s                 \n",team);
      printf("===============================================================================\n");
      printf("  PLAYER'S NAME \tSixers  \t     fours     \t         runs  \t\t BATTING AVERAGE\n");
      printf("===============================================================================\n");
      
      
      for (i=0; i<n; i++)
      {
      	if (strcmp(team,player[i].teamname)==0)
           printf("  %-20s %-20s %-20s %-20s %f\n",player[i].name,player[i].sixers,player[i].fours,player[i].runs,player[i].btavg);
	  }
          
 
      printf("\n\nWant to see the List of the Players in a Team Again..? (Y/N):\t ");
      ch = getche();
      if (ch == 'Y' || ch == 'y')
      goto read;
 
  getch();
}
