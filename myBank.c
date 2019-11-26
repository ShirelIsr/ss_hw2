#include <stdio.h>
#include "myBank.h"

int isAccount(int num)
{
     if((num<ID) || (num>(ID+SIZE)))
    {
        printf("The account number is not Exisest in the system (901-950)\n ");
        return 0;
    }
      if(!(int)ServicePoint[num-ID][COL0])
    {
        printf("account dons't exist");
        return 0;
    }
    return 1;
}
void createAccount(){
    double sum=0;
   
        for (int i = 0; i < SIZE; i++)
        {
            if((int)ServicePoint[i][COL0]==0)
            {
                 printf("Enter your amount?\n");
                 if(!scanf("%lf",&sum))
                 {
                        printf("ERR,invalid input\n");
                        return;
                 }
                  
                      if(sum<0)
                  {
                      printf("ERRE,invalid input\n");
                      return;
                  }   
                ServicePoint[i][COL0] = COL1;
                ServicePoint[i][COL1] = sum;
                printf("Your account number is: %d\n",(i+ID));
                return;
            }
        }
        printf("All the accounts are used\n"); 
}

void getBalance()
{
    int accNum=0;
    printf("Enter your account number :");
    if(scanf(" %d",&accNum)!=1) 
    {
        printf("ERR,invalid input\n");
        return;
    }
    if(!isAccount(accNum)) {return;}
    accNum-=ID;
    if(ServicePoint[(accNum)][COL0])
    {
        printf("yours balance is:%.2lf\n",ServicePoint[(accNum)][1]);
        return;
    }
        printf("this account is closed\n");
        return;
}
void deposit()
{
  int accNum=0;
  double sum=0;
  printf("Enter your account number \n");
 if(!scanf("%d",&accNum)) 
 {
        printf("ERR,invalid input\n");
        return;
 }
   if(!isAccount(accNum)) return;
     accNum=accNum-ID;
    printf("Enter amount to deposit?");
    if(!scanf("%lf",&sum)) 
    {
        printf("ERR,invalid input\n");
        return;
    }
      if(sum<=0) 
       {
         printf("ERRE,invalid input\n");
         return;  
          }
   ServicePoint[accNum][COL1] += sum;
        printf("Your new balance is: %.2lf\n",ServicePoint[accNum][COL1]);
        return ;
}

void withdraw()
{
  int accNum=0;
  double sum=0;
  printf("Enter your account number \n");
  if(scanf("%d",&accNum)!=1) 
  {
      printf("ERR,invalid input\n");
      return;
  }
  if(!isAccount(accNum)) return;
  accNum-=ID;
    printf("Enter amount to withdraw?");
    if(scanf("%lf",&sum)!=1)  
    {
        printf("ERR,invalid input\n");
        return;
    }
      if(sum<=0)  {
         printf("ERRE,invalid input\n");
          return;
                  }
    if(sum<ServicePoint[accNum][COL1]) 
   {
       ServicePoint[accNum][COL1] -= sum;
        printf("new balance is: %.2lf\n",ServicePoint[accNum][COL1]);
        return ;
   }
   printf("the withdroe is not allowd\n");

}
void addInterest()
{ 
    double interest=0;
    printf("Enter the Insterest \n");
    if(scanf("%lf",&interest)!=1) 
    {
        printf("ERR,invalid input\n");
        return;
    }
    if(interest<=0)
    {
        printf("ERR,the interest should be bigger then zero\n");
        return;
    }
    for(int i=0;i<SIZE;i++)
    {
        if( ServicePoint[i][COL0])
       { 
           ServicePoint[i][1]=ServicePoint[i][COL1]*(interest/100);
       }
    }
}
void closeAccount()
{
    int accNum=0;
    printf("Enter your account number :");
      if(scanf("%d",&accNum)!=1) 
  {
      printf("ERR,invalid input\n");
      return;
  }
    if(!isAccount(accNum)) {return;}
    accNum-=ID;
    if(!ServicePoint[accNum][COL0])
    {
        printf("the account is allredy close\n");
        return;
    }
    if(ServicePoint[accNum][COL1]>0)
    {
        printf("Ther is %lf,in the account ",ServicePoint[accNum][COL1]);
    }
    ServicePoint[accNum][COL1]=0;
        ServicePoint[accNum][COL0]=0;
    }
void printAllAccount()
{
   int j=1;
    for(int i=0;i<SIZE;i++)
    {
        if(ServicePoint[i][COL0])
        {
            printf( "%d) Number account : %d",j,(i+ID));
            printf("Ther is %.2lf in the account\n",ServicePoint[i][COL1]);
            j++;
        }
    }
    if(j==1)
    {
        printf("Ther is no accounts open in the bank\n");
    }

}
void closeAllAccount()
{ 
  printf("All the acconts are closed , have a great day!");
}