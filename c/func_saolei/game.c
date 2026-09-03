// #include "game.h"
// void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
// {
//     int i = 0;
//     for(i=0;i<rows;i++)
//     {
//         int j = 0;
//         for(j=0;j<cols;j++)
//         {
//             board[i][j] = set;
//         }
//     }
// }
// void DisplayBoard(char board[ROWS][COLS],int row,int col)
// {
//     int i = 0;
//     printf("___________sao lei___________\n");
//     for(i=0;i<=col;i++)
//     {
//         printf("%d ",i);
//     }
//     printf("\n");
//     for(i=1;i<=row;i++)
//     {
//         printf("%d ",i);
//         int j = 0;
//         for(j = 1;j<= col;j++)
//         {
//             printf("%c ",board[i][j]);
//         }
//         printf("\n");
//     }
// }
// void SetMine(char board[ROWS][COLS],int row,int col)
// {
//     int count = EASY_COUNT;
//     while(count)
//     {
//         int x = rand()%row + 1;
//         int y = rand()%col + 1;
//         if (board[x][y] == '0')
//         {
//             board[x][y] = '1';
//             count--;
//         }

//     }
// }
// int GetMineCount(char mine[ROWS][COLS],int x,int y)
// {
//     return (mine[x-1][y]+mine[x-1][y-1]+mine[x][y - 1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]+mine[x][y+1]+mine[x-1][y+1] - 8 * '0');
// }
// void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
// {
//     int x = 0;
//     int y = 0;
//     int win = 0;
//     while(win < row * col - EASY_COUNT)
//     {
//         printf("choose:>");
//         scanf("%d%*c%d",&x,&y);
//         while(getchar() != '\n');
//         if(x >= 1 && x <= row && y >= 1 && y <= col)
//         {
//             if(mine[x][y] == '1')
//             {
//                 printf("sorry,you are lose");
//                 DisplayBoard(mine,ROW,COL);
//                 break;
//             }
//             else
//             {//该位置不是雷数出来周围有几个雷
//                 int count = GetMineCount(mine,x,y);
//                 show[x][y] = (char)(count + '0');
//                 DisplayBoard(show,ROW,COL);
//                 win++;

//             }
//         }
//         else
//         {
//             printf("it is not ok,again\n");
           
//         }
        
        
//     }
//     if (win == row * col - EASY_COUNT)
//     {
//             printf("success\n");
//             DisplayBoard(mine,ROW,COL);
//     }
// }