#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int input1();
int input2();

void remainingInput(int s, int d,int Max_array[10][10],int alloc_array[10][10],int avail_array[])
{
	printf("\n\nEnter the Max Matrix for each Process : \n");
    for(int i=0;i<s;i++)
    {
    	printf("\nFor Process %d :\n",i+1);
        for(int j=0;j<d;j++)
        {
        	scanf("%d",&Max_array[i][j]);
		}        
	}
	
	printf("\n\nEnter the Allocation for each Process : \n");
	for(int i=0;i<s;i++)
	{
		printf("\nFor Process %d :\n",i+1);
        for(int j=0;j<d;j++)
        {
        	scanf("%d",&alloc_array[i][j]);
		}
	}
	
	printf("\n\nEnter the Available Resources :\n");
	for(int i=0;i<d;i++)
	{
		scanf("%d\n",&avail_array[i]);
	}
}

int main()
{
	int p,r,i,j,process,count=0;
	int avail[10],completed[10],safeSequence[10];
	int Max[10][10],need[10][10],alloc[10][10];
	
	p=input1();
	r=input2();	
	
	for(i=0;i<p;i++)
	{
		completed[i]=0;
	}
	    
    remainingInput(p,r,Max,alloc,avail);
    
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=Max[i][j]-alloc[i][j];
		}
	}
	
	
	do
	{
		printf("\n Max matrix:\tAllocation Matrix:\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			{
				printf("%d ",Max[i][j]);
			}
			printf("\t\t");
			for( j=0;j<r;j++)
			{
				printf("%d ",alloc[i][j]);				
			}
			printf("\n");
        }
        
        process = -1;
        for(i=0;i<p;i++)
        {
            if(completed[i] == 0)
            {
            	process=i;
                for(j=0;j<r;j++)
                {
                	if(avail[j]<need[i][j])
                	{
                		process=-1;
                		break;
					}
				}
            }
 
            if(process != -1)
            {
            	break;
			}
        }
		
        if(process != -1)
        {
            printf("\nProcess %d runs to Completion!",process+1); 
            safeSequence[count]=process+1;
            count++;
            for(j=0;j<r;j++)
            {
                avail[j]+=alloc[process][j];
                alloc[process][j]=0;
                Max[process][j]=0;
                completed[process]=1;
            }
        }
    }while(count != p && process != -1);
    
    
if(count==p)
{
    printf("\nThe System is in a Safe State!!\n");
    printf("Safe Sequence : <");
    for(i=0;i<p;i++)
    {
    	printf("%d",safeSequence[i]);
	}
	printf(">\n");
}
else
{
	printf("\nThe System is in an Unsafe State!!");
	printf("\nSorry...!!!!");
}
}

int input1()
{
	int a1;
	printf("Enter the Number of Processes: ");
	scanf("%d",&a1);
	return a1;
}

int input2()
{
	int a2;
	printf("Enter the Number of Resourses: ");
	scanf("%d",&a2);
	return a2;
}
