#include <stdio.h>
#include "myBank.h"
int main(){
char c=0;;

while(c !='E')
{ 
 printf("O for open new account\n");
printf("B for check yours balance\n");
printf("D for deposit\n");
printf("W for withdraw\n");
printf("C for close yours account\n");
printf("I for add interest\n");
printf("P for priint all accounts\n");
printf("E to close all accounts\n");
scanf(" %c",&c);

switch(c)
    {
        case 'O':
            createAccount();
            break;
        case 'B':
            getBalance();
            break;
        case 'D':
            deposit();
            break;
        case 'W':
            withdraw();
            break;
        case 'C':
           closeAccount();
          break;
        case 'I':
           addInterest();
           break;
        case 'P':
            printAllAccount();
            break;
        //operator doesn't match any case constant /
        case 'E':
        closeAllAccount();
        
         return 0;
        default:
            printf("Error! operator is not correct\n");
            break;
    }

}
    
    return 0;
}