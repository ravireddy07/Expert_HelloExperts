import java.util.*;
import java.io.*;
import java.lang.*;

public class Bankers
{
    private int need[][],allocate[][],max[][],avail[][],numproces,numrecorce;
     
    private void inumprocesut()
	{
     Scanner sc=new Scanner(System.in);
     System.out.print("Enter no. of processes and Respective Resources : ");
     numproces=sc.nextInt();             
     numrecorce=sc.nextInt();            
	 
     need=new int[numproces][numrecorce];  
	 
     max=new int[numproces][numrecorce];
	 
     allocate=new int[numproces][numrecorce];
	 
     avail=new int[1][numrecorce];
      
     System.out.println("Enter the Allocation Matrix: ");
     for(int i=0;i<numproces;i++)
          for(int j=0;j<numrecorce;j++)
         allocate[i][j]=sc.nextInt();         //allocation matrix
       
     System.out.println("Enter the Max Matrix : ");
     for(int i=0;i<numproces;i++)
          for(int j=0;j<numrecorce;j++)
         max[i][j]=sc.nextInt();              //max matrix
       
        System.out.println("Enter the Available Matrix : ");
        for(int j=0;j<numrecorce;j++)
         avail[0][j]=sc.nextInt();              //available matrix
         
        sc.close();
    }
     
    private int[][] calc_need()
    {
       for(int i=0;i<numproces;i++)
         for(int j=0;j<numrecorce;j++) 
          need[i][j]=max[i][j]-allocate[i][j];
        
       return need;
    }
  
    private boolean check(int i)
    {
       for(int j=0;j<numrecorce;j++) 
       if(avail[0][j]<need[i][j])
          return false;
    
    return true;
    }
 
    public void isSafe()
	{
       inumprocesut();
       calc_need();
       boolean done[]=new boolean[numproces];
       int j=0;
 
       while(j<numproces)
	   { 
       boolean allocated=false;
       for(int i=0;i<numproces;i++)
        if(!done[i] && check(i))
		{  
            for(int k=0;k<numrecorce;k++)
            avail[0][k]=avail[0][k]-need[i][k]+max[i][k];
            System.out.println("Allocated process : "+i);
            allocated=done[i]=true;
               j++;
        }
          if(!allocated) break;  
       }
       if(j==numproces)  //If all processes are allocated,Then
        System.out.println("\nSafely allocated");
       else
        System.out.println("All proceess cant be allocated safely");
    }
     
	
    public static void main(String args[])
	{
       new Bankers().isSafe();
    }
}
