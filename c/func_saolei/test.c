#include "game.h"
//存在缺陷 展开空白 标记地雷 游戏计时为实现
//2026 09 02 由于脑子不清醒 暂时搁置进行之后的部分内容 学完指针回来再看




void menu()
{
    printf("*******************************\n");
    printf("****************1.play*********\n");
    printf("****************0.exit*********\n");
    printf("*******************************\n");

}
void game()
{
    char mine[ROWS][COLS];  //存放布置好的雷
    char show[ROWS][COLS];  // 存放排查出雷的个数
    //先初始化棋盘 mine 全'0' show 全'*'
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,COLS,ROWS,'*');
    //打印棋盘
    DisplayBoard(show,ROW,COL);
    //布置雷
    SetMine(mine,ROW,COL);
    //排查雷
    FindMine(mine,show,ROW,COL);


}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do{
        menu();
        printf("please choose:>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("game over\n");
                break;
            default:
                printf("error\n");
                break;
        }

    }while(input);
    return 0;
}