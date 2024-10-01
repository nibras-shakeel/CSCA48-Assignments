#include<stdio.h>
#include<stdlib.h>
int magicsquare_thingie(int square[6][6])
{
    int mt = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(square[i][j] == -1)
            {
                mt = 0;
                break;
            }
            else
            {
                mt += square[i][j];
            }
        }
        if(mt > 0){break;}
    }
    if(!(mt > 0))
    {
        for(int j = 0; j < 6; j++)
        {
            for(int i = 0; i < 6; i++)
            {
                if(square[i][j] == -1)
                {    
                    mt = 0;
                    break;
                }
                else
                {
                    mt += square[i][j];
                }
            }
        if(mt > 0){break;}
        }
    }
    return mt;
}
void solveMagicSquare(int square[6][6])
{
    int mt = magicsquare_thingie(square);
    int no_count = 0;
    int sum = 0;
    int index = 0;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(square[i][j] == -1)
            {
                no_count++;
                index = j;
            }
            else
            {
                sum += square[i][j];
            }
        }
        if(no_count == 1)
        {
            square[i][index] = mt - sum;
        }
        no_count = 0;
        sum = 0;
        index = 0;
        
    }
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            if(square[i][j] == -1)
            {
                no_count++;
                index = i;
            }
            else
            {
                sum += square[i][j];
            }
        }
        if(no_count == 1)
        {
            square[index][j] = mt - sum;
        }
        no_count = 0;
        sum = 0;
        index = 0;
        
    }
}
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6
   int i,j,sum;
   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }
   printf("---------------------------\n");
   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}
#ifndef __testing   
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},
{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};
    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);
    return 0;
}
#endif