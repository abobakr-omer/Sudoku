#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BACKGROUND_RED     "\x1b[41m"
#define ANSI_BACKGROUND_GREEN   "\x1b[42m"
#define ANSI_BACKGROUND_YELLOW  "\x1b[43m"
#define ANSI_BACKGROUND_BLUE    "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN    "\x1b[46m"
#define ANSI_BACKGROUND_RESET   "\x1b[0m"

int soduku_base_easy(int row_num,int col_num)       //To differentiate between user numbers and basic game numbers
{
    int arr[9][9]= {{0, 1, 3, 8, 4, 0, 9, 7, 0},
        {7, 6, 0, 9, 0, 1, 5, 4, 8},
        {4, 0, 8, 7, 5, 2, 6, 0, 3},
        {1, 5, 4, 6, 9, 0, 2, 0, 7},
        {9, 0, 6, 0, 2, 7, 8, 5, 1},
        {2, 8, 0, 5, 1, 0, 4, 6, 0},
        {0, 7, 9, 2, 6, 5, 0, 8, 4},
        {8, 2, 5, 1, 0, 4, 3, 9, 0},
        {6, 0, 1, 0, 8,9,7,2,5}
    };

    int i,j;
    if(arr[row_num][col_num]==0)  // user can edit on this place
    {
        return 1;
    }
    else
    {
        return 0;                // user can't edit on this place this the game number
    }
}

int soduku_base_medium(int row_num,int col_num)       //To differentiate between user numbers and basic game numbers
{
    int arr[9][9]= {{2,0,9,0,0,0,6,0,0},
        {0,4,0,8,7,0,0,1,2},
        {8,0,0,0,1,9,0,4,0},
        {0,3,0,7,0,0,8,0,1},
        {0,6,5,0,0,8,0,3,0},
        {1,0,0,0,3,0,0,0,7},
        {0,0,0,6,5,0,7,0,9},
        {6,0,4,0,0,0,0,2,0},
        {0,8,0,3,0,1,4,5,0}
    };
    int i,j;
    if(arr[row_num][col_num]==0)  // user can edit on this place
    {
        return 1;
    }
    else
    {
        return 0;                // user can't edit on this place this the game number
    }
}
int soduku_base_hard(int row_num,int col_num)       //To differentiate between user numbers and basic game numbers
{
    int arr[9][9]= {{9, 0, 6, 0, 0, 0, 0, 7, 1},
        {0, 8, 3, 4, 0, 0, 9, 0, 0},
        {1, 0, 0, 0, 6, 0, 0, 0, 4},
        {0, 0, 0, 0, 7, 5, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 3, 8, 0, 0, 0, 0},
        {3, 0, 0, 0, 9, 0, 0, 0, 2},
        {0, 0, 8, 0, 0, 3, 1, 5, 0},
        {4, 1, 0, 0, 0,0,7,0,8}
    };
    int i,j;
    if(arr[row_num][col_num]==0)  // user can edit on this place
    {
        return 1;
    }
    else
    {
        return 0;                // user can't edit on this place this the game number
    }
}
void sodoku_print_easy(int arr[][9],int row,int col)   // function to print the game
{
    int i,j;
    for(j=0; j<9; j++) // Column numbering
    {
        if(j==2||j==5)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else if(j==0)
        {
            printf("\033[32m |\033[0m");

            printf("\033[31m%d  \033[0m",j);
        }
        else if(j==8)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else
        {
            printf("\033[31m%d  \033[0m",j);
        }

    }
    printf("\n");
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[31m%d\033[0m",i);   // Row numbering
        for(j=0; j<col; j++)
        {
            if(j==0)
            {
                printf("\033[32m|\033[0m");
            }


            if(soduku_base_easy(i,j)==0)       // print the game  number in default color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("%c",arr[i][j]);
                    }
                    else
                    {

                        printf("%c  ",arr[i][j]);

                    }
                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("%d",arr[i][j]);
                    }
                    else
                    {


                        printf("%d  ",arr[i][j]);

                    }


                }


            }
            else if(soduku_base_easy(i,j)==1)    // print the user's number in blue color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%c\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%c  \033[0m",arr[i][j]);
                    }

                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%d\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%d  \033[0m",arr[i][j]);


                    }


                }

            }
            if(j==2||j==5||j==8)
            {
                printf("\033[32m|\033[0m");
            }


        }

        printf("\n");
        if(i==2||i==5)
        {
            printf("\033[32m +-------+-------+-------+\n\033[0m");


        }
    }
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    printf("======================================================\n");

}

void sodoku_print_medium(int arr[][9],int row,int col)   // function to print the game
{
    int i,j;
    for(j=0; j<9; j++) // Column numbering
    {
        if(j==2||j==5)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else if(j==0)
        {
            printf("\033[32m |\033[0m");

            printf("\033[31m%d  \033[0m",j);
        }
        else if(j==8)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else
        {
            printf("\033[31m%d  \033[0m",j);
        }

    }
    printf("\n");
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[31m%d\033[0m",i);   // Row numbering
        for(j=0; j<col; j++)
        {
            if(j==0)
            {
                printf("\033[32m|\033[0m");
            }


            if(soduku_base_medium(i,j)==0)       // print the game  number in default color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("%c",arr[i][j]);
                    }
                    else
                    {

                        printf("%c  ",arr[i][j]);

                    }
                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("%d",arr[i][j]);
                    }
                    else
                    {


                        printf("%d  ",arr[i][j]);

                    }


                }


            }
            else if(soduku_base_medium(i,j)==1)    // print the user's number in blue color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%c\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%c  \033[0m",arr[i][j]);
                    }

                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%d\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%d  \033[0m",arr[i][j]);


                    }


                }

            }
            if(j==2||j==5||j==8)
            {
                printf("\033[32m|\033[0m");
            }


        }

        printf("\n");
        if(i==2||i==5)
        {
            printf("\033[32m +-------+-------+-------+\n\033[0m");


        }
    }
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    printf("======================================================\n");

}
void sodoku_print_hard(int arr[][9],int row,int col)   // function to print the game
{
    int i,j;
    for(j=0; j<9; j++) // Column numbering
    {
        if(j==2||j==5)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else if(j==0)
        {
            printf("\033[32m |\033[0m");

            printf("\033[31m%d  \033[0m",j);
        }
        else if(j==8)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else
        {
            printf("\033[31m%d  \033[0m",j);
        }

    }
    printf("\n");
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[31m%d\033[0m",i);   // Row numbering
        for(j=0; j<col; j++)
        {
            if(j==0)
            {
                printf("\033[32m|\033[0m");
            }


            if(soduku_base_hard(i,j)==0)       // print the game  number in default color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("%c",arr[i][j]);
                    }
                    else
                    {

                        printf("%c  ",arr[i][j]);

                    }
                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("%d",arr[i][j]);
                    }
                    else
                    {


                        printf("%d  ",arr[i][j]);

                    }


                }


            }
            else if(soduku_base_hard(i,j)==1)    // print the user's number in blue color
            {
                if(arr[i][j]==0||arr[i][j]==' ')
                {
                    arr[i][j]=' ';
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%c\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%c  \033[0m",arr[i][j]);
                    }

                }
                else
                {
                    if(j==2||j==5||j==8)
                    {
                        printf("\033[34m%d\033[0m",arr[i][j]);
                    }
                    else
                    {
                        printf("\033[34m%d  \033[0m",arr[i][j]);


                    }


                }

            }
            if(j==2||j==5||j==8)
            {
                printf("\033[32m|\033[0m");
            }


        }

        printf("\n");
        if(i==2||i==5)
        {
            printf("\033[32m +-------+-------+-------+\n\033[0m");


        }
    }
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    printf("======================================================\n");

}

int sodoku_End(int arr[][9],int row,int col)
{
    int i,j,flag=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(arr[i][j]==0)
            {
                flag=0;
                return 0;
            }
        }
    }
    if(flag==1)
    {
        return 1;
    }
}
int sodoku_Solve(int arr[][9],int row,int col)
{
    int i,j;
    for(j=0; j<9; j++) // Column numbering
    {
        if(j==2||j==5)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else if(j==0)
        {
            printf("\033[32m |\033[0m");

            printf("\033[31m%d  \033[0m",j);
        }
        else if(j==8)
        {
            printf("\033[31m%d\033[0m",j);
            printf("\033[32m|\033[0m");
        }
        else
        {
            printf("\033[31m%d  \033[0m",j);
        }

    }
    printf("\n");
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    for(i=0; i<row; i++)
    {
        printf("\033[31m%d\033[0m",i);   // Row numbering
        for(j=0; j<col; j++)
        {
            if(j==0)
            {
                printf("\033[32m|\033[0m");
            }

            if(arr[i][j]==0||arr[i][j]==' ')
            {
                arr[i][j]=' ';
                if(j==2||j==5||j==8)
                {
                    printf("\033[34m%c\033[0m",arr[i][j]);
                }
                else
                {
                    printf("\033[34m%c  \033[0m",arr[i][j]);
                }

            }
            else
            {
                if(j==2||j==5||j==8)
                {
                    printf("\033[34m%d\033[0m",arr[i][j]);
                }
                else
                {
                    printf("\033[34m%d  \033[0m",arr[i][j]);


                }

            }

            if(j==2||j==5||j==8)
            {
                printf("\033[32m|\033[0m");
            }

        }

        printf("\n");
        if(i==2||i==5)
        {
            printf("\033[32m +-------+-------+-------+\n\033[0m");


        }
    }
    printf("\033[32m +-------+-------+-------+\n\033[0m");

    printf("======================================================\n");

}
void sodoku_set_easy(int arr[][9],int row,int col,int row_num,int col_num,int num)
{
    int i,j,flag=0;
    //printf("base222:%d\n",soduku_base(row_num,col_num));

    if(soduku_base_easy(row_num,col_num))
    {
        if(num>0&&num<=9)
        {
            for(j=0; j<col; j++)
            {
                i=row_num;
                if(arr[i][j]==num)
                {
                    flag=1;
                }
            }
            for(i=0; i<row&&flag==0; i++)
            {
                j=col_num;
                if(arr[i][j]==num)
                {
                    flag=2;
                }
            }
            if(flag==0&&num>0&&num<=9)
            {
                arr[row_num][col_num]=num;

            }
            else if(flag==1)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same row\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }
            else if(flag==2)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same column\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }



        }
        else
        {
            printf("\x1b[1m\x1b[4m\x1b[31m");
            printf("\033[31mPlease enter a number from 1 to 9\033[0m\n");
            printf("\x1b[0m");
            sleep(1);

        }
    }
    else
    {
        //
        printf("\x1b[1m\x1b[4m\x1b[31m");  // Bold, Underline, Red
        printf("\033[31myou can't replace a basic number\033[0m\n");
        printf("\x1b[0m");  // Reset all text attributes

        sleep(1);

    }




}
void sodoku_set_medium(int arr[][9],int row,int col,int row_num,int col_num,int num)
{
    int i,j,flag=0;
    //printf("base222:%d\n",soduku_base(row_num,col_num));

    if(soduku_base_medium(row_num,col_num))
    {
        if(num>0&&num<=9)
        {
            for(j=0; j<col; j++)
            {
                i=row_num;
                if(arr[i][j]==num)
                {
                    flag=1;
                }
            }
            for(i=0; i<row&&flag==0; i++)
            {
                j=col_num;
                if(arr[i][j]==num)
                {
                    flag=2;
                }
            }
            if(flag==0&&num>0&&num<=9)
            {
                arr[row_num][col_num]=num;

            }
            else if(flag==1)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same row\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }
            else if(flag==2)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same column\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }



        }
        else
        {
            printf("\x1b[1m\x1b[4m\x1b[31m");
            printf("\033[31mPlease enter a number from 1 to 9\033[0m\n");
            printf("\x1b[0m");
            sleep(1);

        }
    }
    else
    {
        printf("\x1b[1m\x1b[4m\x1b[31m");
        printf("\033[31myou can't replace a basic number\033[0m\n");
        printf("\x1b[0m");
        sleep(1);

    }




}
void sodoku_set_hard(int arr[][9],int row,int col,int row_num,int col_num,int num)
{
    int i,j,flag=0;
    //printf("base222:%d\n",soduku_base(row_num,col_num));

    if(soduku_base_hard(row_num,col_num))
    {
        if(num>0&&num<=9)
        {
            for(j=0; j<col; j++)
            {
                i=row_num;
                if(arr[i][j]==num)
                {
                    flag=1;
                }
            }
            for(i=0; i<row&&flag==0; i++)
            {
                j=col_num;
                if(arr[i][j]==num)
                {
                    flag=2;
                }
            }
            if(flag==0&&num>0&&num<=9)
            {
                arr[row_num][col_num]=num;
//\033[31m       \033[0m
            }
            else if(flag==1)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same row\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }
            else if(flag==2)
            {
                printf("\x1b[1m\x1b[4m\x1b[31m");
                printf("\033[31mThis number is in the same column\033[0m\n");
                printf("\x1b[0m");
                sleep(1);


            }



        }
        else
        {
            printf("\x1b[1m\x1b[4m\x1b[31m");
            printf("\033[31mPlease enter a number from 1 to 9\033[0m\n");
            printf("\x1b[0m");
            sleep(1);

        }
    }
    else
    {
        printf("\x1b[1m\x1b[4m\x1b[31m");
        printf("\033[31myou can't replace a basic number\033[0m\n");
        printf("\x1b[0m");
        sleep(1);

    }




}

int main()
{
    int i,j,i2,j2,num,mode,c=1,s,c_easy=5,c_medium=5,c_hard=5;
    int arr_medium[9][9]= {{2,0,9,0,0,0,6,0,0},
        {0,4,0,8,7,0,0,1,2},
        {8,0,0,0,1,9,0,4,0},
        {0,3,0,7,0,0,8,0,1},
        {0,6,5,0,0,8,0,3,0},
        {1,0,0,0,3,0,0,0,7},
        {0,0,0,6,5,0,7,0,9},
        {6,0,4,0,0,0,0,2,0},
        {0,8,0,3,0,1,4,5,0}
    };

    int arr_medium_solve[9][9]= {{2,1,9,5,4,3,6,7,8},
        {5,4,3,8,7,6,9,1,2},
        {8,7,6,2,1,9,3,4,5},
        {4,3,2,7,6,5,8,9,1},
        {7,6,5,1,9,8,2,3,4},
        {1,9,8,4,3,2,5,6,7},
        {3,2,1,6,5,4,7,8,9},
        {6,5,4,9,8,7,1,2,3},
        {9,8,7,3,2,1,4,5,6}
    };

    int arr_hard[9][9]=  {{9, 0, 6, 0, 0, 0, 0, 7, 1},
        {0, 8, 3, 4, 0, 0, 9, 0, 0},
        {1, 0, 0, 0, 6, 0, 0, 0, 4},
        {0, 0, 0, 0, 7, 5, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 3, 8, 0, 0, 0, 0},
        {3, 0, 0, 0, 9, 0, 0, 0, 2},
        {0, 0, 8, 0, 0, 3, 1, 5, 0},
        {4, 1, 0, 0, 0,0,7,0,8}
    };


    int arr_hard_solve[9][9]=  {{9, 4, 6, 5, 3, 8, 2, 7, 1},
        {7, 8, 3, 4, 1, 2, 9, 6, 5},
        {1, 2, 5, 9, 6, 7, 3, 8, 4},
        {6, 9, 4, 1, 7, 5, 8, 2, 3},
        {8, 3, 1, 6, 2, 4, 5, 9, 7},
        {5, 7, 2, 3, 8, 9, 4, 1, 6},
        {3, 5, 7, 8, 9, 1, 6, 4, 2},
        {2, 6, 8, 7, 4, 3, 1, 5, 9},
        {4, 1, 9, 2, 5,6,7,3,8}
    };

    int arr_easy[9][9]= {{0, 1, 3, 8, 4, 0, 9, 7, 0},
        {7, 6, 0, 9, 0, 1, 5, 4, 8},
        {4, 0, 8, 7, 5, 2, 6, 0, 3},
        {1, 5, 4, 6, 9, 0, 2, 0, 7},
        {9, 0, 6, 0, 2, 7, 8, 5, 1},
        {2, 8, 0, 5, 1, 0, 4, 6, 0},
        {0, 7, 9, 2, 6, 5, 0, 8, 4},
        {8, 2, 5, 1, 0, 4, 3, 9, 0},
        {6, 0, 1, 0, 8,9,7,2,5}
    };

    int arr_easy_solve[9][9]= {{5, 1, 3, 8, 4, 6, 9, 7, 2},
        {7, 6, 2, 9, 3, 1, 5, 4, 8},
        {4, 9, 8, 7, 5, 2, 6, 1, 3},
        {1, 5, 4, 6, 9, 8, 2, 3, 7},
        {9, 3, 6, 4, 2, 7, 8, 5, 1},
        {2, 8, 7, 5, 1, 3, 4, 6, 9},
        {3, 7, 9, 2, 6, 5, 1, 8, 4},
        {8, 2, 5, 1, 7, 4, 3, 9, 6},
        {6, 4, 1, 3, 8,9,7,2,5}
    };

    system("COLOR 0A");
    /*printf("\033[31m       \033[0m\n"); This is red text.
    printf("\033[32m         \033[0m\n");This is green text.
    printf("\033[34m.        \033[0m\n");This is blue text
    Black: \x1b[30m
    Red: \x1b[31m
    Green: \x1b[32m
    Yellow: \x1b[33m
    Blue: \x1b[34m
    Magenta: \x1b[35m
    Cyan: \x1b[36m
    White: \x1b[37m*/


    printf("                   \033[37m 00000  0    0   0000         000      0    0  0    0\033[0m\n");
    printf("                   \033[36m0       0    0   0   0       0   0     0   0   0    0\033[0m\n");
    printf("                   \033[35m0       0    0   0    0     0     0    0  0    0    0\033[0m\n");
    printf("                    \033[34m0000   0    0   0     0   0       0   000     0    0\033[0m\n");
    printf("                   \033[33m    0   0    0   0    0     0     0    0  0    0    0\033[0m\n");
    printf("                   \033[32m    0   0    0   0   0       0   0     0   0   0    0\033[0m\n");
    printf("                   \033[31m0000     0000    0000         000      0    0   0000\033[0m\n");
    printf("\033[32m                                Welcome to the game of legends\033[0m\n");

    printf("\033[31m                                        Choose the mode\033[0m\n");
    printf("                                       1-Beginner\n");
    printf("                                       2-Professional\n");
    printf("                                       3-Legendary\n\t\t\t\t");


    scanf("%d",&mode);
    while(mode>3||mode<=0)
    {
        printf("\033[31m                           Please enter a valid number from the options in front of you\033[0m");
        sleep(2.5);
        system("cls");
         printf("                   \033[37m 00000  0    0   0000         000      0    0  0    0\033[0m\n");
    printf("                   \033[36m0       0    0   0   0       0   0     0   0   0    0\033[0m\n");
    printf("                   \033[35m0       0    0   0    0     0     0    0  0    0    0\033[0m\n");
    printf("                    \033[34m0000   0    0   0     0   0       0   000     0    0\033[0m\n");
    printf("                   \033[33m    0   0    0   0    0     0     0    0  0    0    0\033[0m\n");
    printf("                   \033[32m    0   0    0   0   0       0   0     0   0   0    0\033[0m\n");
    printf("                   \033[31m0000     0000    0000         000      0    0   0000\033[0m\n");
    printf("\033[32m                                Welcome to the game of legends\033[0m\n");

    printf("\033[31m                                        Choose the mode\033[0m\n");
    printf("                                       1-Beginner\n");
    printf("                                       2-Professional\n");
    printf("                                       3-Legendary\n\t\t\t\t");
    scanf("%d",&mode);
    }
    int barWidth = 40;

    for (i2 = 0; i2 <= barWidth; ++i2)
    {
        printf("                             [");

        // Set the text and background color based on the progress
        if (i2 <= barWidth / 3)
            printf(ANSI_COLOR_RED);  // Red text color
        else if (i2 <= (2 * barWidth) / 3)
            printf(ANSI_COLOR_RED);  // Yellow text color
        else
            printf(ANSI_COLOR_RED);  // Green text color

        // Set the background color based on the progress
        if (i2 <= barWidth / 3)
            printf(ANSI_BACKGROUND_GREEN);  // Blue background color
        else if (i2 <= (2 * barWidth) / 3)
            printf(ANSI_BACKGROUND_GREEN);  // Magenta background color
        else
            printf(ANSI_BACKGROUND_GREEN);  // Cyan background color

        for (int j2 = 0; j2 < i2; ++j2)
            printf("=");

        printf(">");
        for (int j2 = i2 + 1; j2 <= barWidth; ++j2)
            printf(" ");

        printf(ANSI_COLOR_RESET ANSI_BACKGROUND_RESET);  // Reset text and background colors
        printf("] %d%%", (i2 * 100) / barWidth);
        fflush(stdout);  // Flush the output to ensure it is displayed

        usleep(59999);  // Sleep for 100 milliseconds (0.1 second)

        // Move the cursor back to the beginning of the line
        printf("\r");
    }
    printf("\nLoading complete!\n");

    system("cls");

    switch(mode)
    {
    case 1:
        while(1)
        {
            while(c)
            {
                sodoku_print_easy(arr_easy,9,9);
                c--;
            }
            printf("\033[31mTO know the solution enter 10 then 10 you have only %d of 5 attempts\033[0m\n",c_easy);
            printf("\033[32mEnter the location of the number Row then Column\033[0m\n");
            scanf("%d %d",&i,&j);
            if(i>=0&&i<=8&&j>=0&&j<=8)
            {
                printf("\033[32mEnter the number between 1 to 9\033[0m\n");
                scanf("%d",&num);
                sodoku_set_easy(arr_easy,9,9,i,j,num);
                sodoku_print_easy(arr_easy,9,9);
                system("cls");
                sodoku_print_easy(arr_easy,9,9);
                if(sodoku_End(arr_easy,9,9))
                {
                    printf("\033[31mCongratulation\033[0m\n");
                    break;
                }

            }
            else if(i==10&&j==10&&c_easy>0)
            {
                c_easy--;
                system("cls");
                sodoku_Solve(arr_easy_solve,9,9);
                printf("\033[31mYou only have %d attempts left from 5\033[0m\n",c_easy);
                printf("\x1b[1m\x1b[4m\x1b[32m");
                printf("\033[32m1-Back to the game \n2-To close the game\033[0m\n");
                printf("\x1b[0m");
                scanf("%d",&s);
                if(s==2)
                {
                    return ;
                }
                else if(s==1)
                {
                    system("cls");
                    sodoku_print_easy(arr_easy,9,9);
                }

            }
            else if(i==10&&j==10&&c_easy<=0)
            {
                printf("\033[31m You have run out of attempts and Good luck\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_easy(arr_easy,9,9);

            }
            else if(i>8||i<0||j>8||j<0)
            {
                printf("\033[31m Please enter a valid number from 0 to 8\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_easy(arr_easy,9,9);
            }

        }
        break;
    case 2:
       while(1)
        {
            while(c)
            {
                sodoku_print_medium(arr_medium,9,9);
                c--;
            }
            printf("\033[31mTO know the solution enter 10 then 10 you have only %d of 5 attempts\033[0m\n",c_medium);
            printf("\033[32mEnter the location of the number Row then Column\033[0m\n");
            scanf("%d %d",&i,&j);
            if(i>=0&&i<=8&&j>=0&&j<=8)
            {
                printf("\033[32mEnter the number between 1 to 9\033[0m\n");
                scanf("%d",&num);
                sodoku_set_medium(arr_medium,9,9,i,j,num);
                sodoku_print_medium(arr_medium,9,9);
                system("cls");
                sodoku_print_medium(arr_medium,9,9);
                if(sodoku_End(arr_medium,9,9))
                {
                    printf("\033[31mCongratulation\033[0m\n");
                    return;
                }

            }
            else if(i==10&&j==10&&c_medium>0)
            {
                c_medium--;
                system("cls");
                sodoku_Solve(arr_medium_solve,9,9);
                printf("\033[31mYou only have %d attempts left from 5\033[0m\n",c_medium);
                printf("\x1b[1m\x1b[4m\x1b[32m");
                printf("\033[32m1-Back to the game \n2-To close the game\033[0m\n");
                printf("\x1b[0m");
                scanf("%d",&s);
                if(s==2)
                {
                    return ;
                }
                else if(s==1)
                {
                    system("cls");
                    sodoku_print_medium(arr_medium,9,9);
                }

            }
            else if(i==10&&j==10&&c_medium<=0)
            {
                printf("\033[31m You have run out of attempts and Good luck\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_medium(arr_medium,9,9);

            }
            else if(i>8||i<0||j>8||j<0)
            {
                printf("\033[31m Please enter a valid number from 0 to 8\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_medium(arr_medium,9,9);
            }

        }
        break;
    case 3:
       while(1)
        {
            while(c)
            {
                sodoku_print_hard(arr_hard,9,9);
                c--;
            }
            printf("\033[31mTO know the solution enter 10 then 10 you have only %d of 5 attempts\033[0m\n",c_hard);
            printf("\033[32mEnter the location of the number Row then Column\033[0m\n");
            scanf("%d %d",&i,&j);
            if(i>=0&&i<=8&&j>=0&&j<=8)
            {
                printf("\033[32mEnter the number between 1 to 9\033[0m\n");
                scanf("%d",&num);
                sodoku_set_hard(arr_hard,9,9,i,j,num);
                sodoku_print_hard(arr_hard,9,9);
                system("cls");
                sodoku_print_hard(arr_hard,9,9);
                if(sodoku_End(arr_easy,9,9))
                {
                    printf("\033[31mCongratulation\033[0m\n");
                    break;
                }

            }
            else if(i==10&&j==10&&c_hard>0)
            {
                c_hard--;
                system("cls");
                sodoku_Solve(arr_hard_solve,9,9);
                printf("\033[31mYou only have %d attempts left from 5\033[0m\n",c_hard);
                printf("\x1b[1m\x1b[4m\x1b[32m");
                printf("\033[32m1-Back to the game \n2-To close the game\033[0m\n");
                printf("\x1b[0m");
                scanf("%d",&s);
                if(s==2)
                {
                    return ;
                }
                else if(s==1)
                {
                    system("cls");
                    sodoku_print_hard(arr_hard,9,9);
                }

            }
            else if(i==10&&j==10&&c_hard<=0)
            {
                printf("\033[31m You have run out of attempts and Good luck\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_hard(arr_hard,9,9);

            }
           else if(i>8||i<0||j>8||j<0)
            {
                printf("\033[31m Please enter a valid number from 0 to 8\033[0m");
                sleep(1.5);
                system("cls");
                sodoku_print_hard(arr_hard,9,9);
            }
        }
        break;


    }
    return 0;
}
