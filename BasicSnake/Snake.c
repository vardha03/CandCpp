/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>
#define SNAKE '~'
#define BOARD '-' 

char a[10][10];
int xpos=5,ypos=5;
void initgraph(char a[10][10]);
void printgraph(char a[10][10]);
int userinterface(char opt);

int main()
{
    int rc=0,counter=0;
    char opt='\0';
    initgraph(a);
    printgraph(a);
    while (counter<5)
    {
        opt = getch();
        if ( (opt != 'w') && (opt!= 's') && (opt != 'a') && (opt!='d') )
        {
            printf("Invalid choice...Quitting!!!\n"
                    "w - Up\n"
                    "s - Down\n"
                    "a - Right\n"
                    "d - Left\n");
            break;
        }
        rc=userinterface(opt);
        clrscr();
        printgraph(a);
        counter++;
    }
    return 0;
}

int userinterface(char opt)
{
    a[xpos][ypos]=' ';
    switch(opt)
    {
        case 'w': xpos--;
          break;
        case 'a': ypos--;
          break;        
        case 's': xpos++;
          break;        
        case 'd': ypos++;
          break;
    }
    a[xpos][ypos]=SNAKE;
    return 0;
}

void printgraph(char a[10][10])
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
          printf("%c",a[i][j]);   
        }
          printf("\n");
    }
}

void initgraph(char a[10][10])
{
    for(int i=0;i<10;i++)
    {
        /*Top end*/
      a[0][i]=BOARD;  
       /*Bottom end*/
      a[9][i]=BOARD;
        /*Left end*/
      a[i][0]=BOARD;
       /*Right end*/
      a[i][9]=BOARD;
    }
    for (int i=1;i<9;i++)
      for (int j=1;j<9;j++)
        a[i][j]=' ';
    a[xpos][ypos]=SNAKE;
}
