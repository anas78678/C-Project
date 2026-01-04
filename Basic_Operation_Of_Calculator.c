#include<stdio.h>

void add(int n1 , int n2)
{
    int add = n1 + n2 ;
    printf("\nAddition is = %d ", add);
}

void sub(int n1 , int n2)
{
    int sub = n1 - n2 ;
    printf("\nSubtraction is = %d", sub);
}

void multi(int n1 ,int n2)
{
    int multi = n1 * n2 ;
    printf("\nMultiplication is = %d", multi); 
}

void div(int n1 ,int n2)
{
      float divi =(float)n1 / n2 ;
   printf("\nDivision is =  %f",divi);
}

int main()
{ 
    int n1, n2, ch;

    printf(" Enter first number : ");
    scanf("%d",&n1);
    printf("\n Enter second nubmer : ");
    scanf("%d",&n2);

    do
    {
    printf("\n\n---Operations---\n");

    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n"); 
    printf("4. Division \n");
    printf("5. Exit \n");

    printf("\n Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        add(n1 ,n2);
        break ;

        case 2:
        sub(n1 ,n2);
        break ; 
         
        case 3:
        multi(n1 ,n2);
        break ; 
        
        case 4:
        div(n1 ,n2);
        break ;
        
        default : 
        printf("\nEXIT");
        break ;

    }

} while(ch!=5);

    return 0;
}