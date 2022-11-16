#include <stdio.h>
#include "stdlib.h"
#include <time.h>
#define row 12
#define col 12
int ab [row][col];
int thundera;//雷总数
char player [row][col];//玩家组
char test   [row][col];//测试组

/* 初始化雷阵 */
void thunder()
{
    int i=0,j=0;
    for ( i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            player[i][j] = '*';//玩家
            test  [i][j] = '0';//测试
            ab[i][j] = 0;//展开
        }
    }
}

/*  打印玩家  */
void players(){
    system("clear");
    int i=0,j=0;
    printf("   ");
    for (i = 1; i <row-1; i++)
    {
        printf("%d ", i);//打印横标（1--10）
    }
    printf("\n");
    for (i = 1; i <row-2; i++)
    {
        printf("%d  ", i);//打印竖标（1--9）
        for (j = 1; j < col-1; j++)
        {
            printf("%c ", player[i][j]);
        }
        printf("\n");
    }
    printf("10 ");//打印最后一行,为了控制间距单独打印
    for (i = 1; i < row-1; i++)
    {
        printf("%c ", player[10][i]);
    }
    printf("\n");
}

/*  打印测试  */
void tests(){
    int i=0,j=0;
    printf("   ");
    for (i = 1; i <row-1; i++)
    {
        printf("%d ", i);//打印横标（0--10）
    }
    printf("\n");
    for (i = 1; i <row-2; i++)//打印竖标（1--10）
    {
        printf("%d  ", i);
        for (j = 1; j < col-1; j++)
        {
            printf("%c ", test[i][j]);//玩家棋盘数组
        }
        printf("\n");
    }
    printf("10 ");//打印最后一行控制间距单独打印
    for (i = 1; i < row-1; i++)
    {
        printf("%c ", test[10][i]);
    }
    printf("\n");
}

/* 给测试棋盘布雷 */
void thunders(){
    srand(time(NULL));   //跟据日期获得不同的随机种子
      int a = thundera;  //雷总数
    while(a){
        int x = rand() % 10+1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
        int y = rand() % 10+1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
        if(test[x][y]=='0'){
            test[x][y]='1';
            a --;
        }
    }
}
/*检测周围八格的雷*/
int thunder_mine(int x,int y){
    int thunder = 0;
    if (test[x - 1][y - 1] == '1')
        thunder++;
    if (test[x - 1][y] == '1')
        thunder++;
    if (test[x - 1][y + 1] == '1')
        thunder++;
    if (test[x][y - 1] == '1')
        thunder++;
    if (test[x][y] == '1')
        thunder++;
    if (test[x][y + 1] == '1')
        thunder++;
    if (test[x + 1][y - 1] == '1')
        thunder++;
    if (test[x + 1][y] == '1')
        thunder++;
    if (test[x + 1][y + 1] == '1')
        thunder++;
    return thunder;
}

/*展开*/
void unfold(int x,int y){

    player[x][y] = thunder_mine(x,y) + '0';//显示该坐标周围雷数
    if(thunder_mine(x,y)==0) {
        ab[x][y]++;
        if (thunder_mine(x - 1, y - 1) == 0 ) {
            player[x - 1][y - 1] = '0';
            ab[x-1][y-1]++;

        } else if (thunder_mine(x - 1, y - 1) != 0){
            player[x - 1][y - 1] = thunder_mine(x - 1, y - 1) + '0';

        }
        if (thunder_mine(x - 1, y) == 0) {
            player[x - 1][y] = '0';
            ab[x-1][y]++;
        } else if (thunder_mine(x - 1, y) != 0){
            player[x - 1][y] = thunder_mine(x - 1, y) + '0';

        }
        if (thunder_mine(x - 1, y + 1) == 0) {
            player[x - 1][y + 1] = '0';
            ab[x-1][y+1]++;
        } else if (thunder_mine(x - 1, y + 1) != 0){
            player[x - 1][y + 1] = thunder_mine(x - 1, y + 1) + '0';

        }
        if (thunder_mine(x, y - 1) == 0) {
            player[x][y - 1] = '0';
            ab[x][y-1]++;
        } else if (thunder_mine(x, y - 1) != 0){
            player[x][y - 1] = thunder_mine(x, y - 1) + '0';

        }
        if (thunder_mine(x, y + 1) == 0) {
            player[x][y + 1] = '0';
            ab[x][y+1]++;
        } else if (thunder_mine(x, y + 1) != 0){
            player[x][y + 1] = thunder_mine(x, y + 1) + '0';

        }
        if (thunder_mine(x + 1, y - 1) == 0) {
            player[x + 1][y - 1] = '0';
            ab[x+1][y-1]++;
        } else if (thunder_mine(x + 1, y - 1) != 0){
            player[x + 1][y - 1] = thunder_mine(x + 1, y - 1) + '0';

        }
        if (thunder_mine(x + 1, y) == 0) {
            player[x + 1][y] = '0';
            ab[x+1][y]++;
        } else if (thunder_mine(x + 1, y) != 0){
            player[x + 1][y] = thunder_mine(x + 1, y) + '0';

        }
        if (thunder_mine(x + 1, y + 1) == 0) {
            player[x + 1][y + 1] = '0';
            ab[x+1][y+1]++;
        } else if (thunder_mine(x + 1, y + 1) != 0){
            player[x + 1][y + 1] = thunder_mine(x + 1, y + 1) + '0';

        }
    }
}

/*判断剩余未知区域个数*/
int mine(){
    int  thunder = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i <= row - 2; i++)
    {
        for (j = 1; j <= col - 2; j++)
        {
            if (player[i][j] == '*')
            {
                thunder++;
            }
        }

    }
    return  thunder;
}

/*扫雷函数*/
int sweep(){
    int x = 0;
    int y = 0;
    printf("输入坐标扫雷，以空格隔开！\n");
    scanf("%d%d", &x, &y);
    if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))
    {
        if (test[x][y] == '0')//没踩到雷
        {
            unfold(x, y);
            for(int a =0;a<row;a++) {//判断该位置是否展开过
                for (int i = 1; i < row-1; i++) {
                    for (int j = 1; j < col-1; j++) {
                        if (ab[i][j] >0&&ab[i][j]<10) {
                            unfold(i, j);
                        }
                    }
                }
            }
        }
        else if (test[x][y]=='1')//踩到雷
        {
            return 1;
        }

    }
    else
    {
        printf("输入错误重新输入\n");
    }
    return 0;//没踩到雷
}

/*避免第一次被炸死*/
int fault(){
    int x = 0;
    int y = 0;
    int z = 1;
    printf("输入坐标扫雷，以空格隔开！\n");
    scanf("%d%d", &x, &y);
    if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))
    {
        if (test[x][y] == '0')//没踩到雷
        {
            //数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
            unfold(x, y);
            for(int a =0;a<row;a++) {
                for (int i = 1; i < row-1; i++) {
                    for (int j = 1; j < col-1; j++) {
                        if (ab[i][j] >0&&ab[i][j]<10) {
                            unfold(i, j);
                        }
                    }
                }
            }

        }
        else if (test[x][y]=='1')//踩到雷
        {
            test[x][y]='0';
            srand(time(NULL));
            while(z){
             int  a = rand() % 10+1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
             int  b = rand() % 10+1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
                if(test[a][b]=='0'){
                    test[a][b]='1';
                    z --;
                }
            }
            unfold(x, y);
            for(int a =0;a<row;a++) {
                for (int i = 1; i < row-1; i++) {
                    for (int j = 1; j < col-1; j++) {
                        if (ab[i][j] >0&&ab[i][j]<10) {
                            unfold(i, j);
                        }
                    }
                }
            }
        }

    }
    else
    {
        printf("输入错误重新输入\n");
    }
    return 0;//没踩到雷
}

int game(){
    printf("请选择难度：1-100\n");
    scanf("%d", &thundera);
    if(thundera>100||thundera<1){
        printf("这不是你能挑战的！\n");
        return 0;
    }
  int a = 0;
  thunder();
  thunders();
  //tests();//作弊代码
  printf("\n");
  players();
  fault();//避免第一次被炸死
    if(mine()==thundera){
        tests();
        printf("你赢了!\n");
        return 0;
    }
// tests();
  players();
  while(1){
      a = sweep();
      if(mine()==thundera){
          printf("你赢了!\n");
          tests();
          break;
      }
      if(a==1){
          printf("你爆炸了!\n");
          break;
      }
      players();
  }
    return 0;
}
int main(){
    int input = 0;
    do
    {
        printf("输入1开始游戏！输入0退出游戏\n");
        scanf("%d", &input);
        switch (input)
        {
            case 1:game();
                break;
            case 0:exit(0);//退出游戏
            default:
                printf("输入错误，重新输入\n");
                break;
        }
        printf("已重新开始\n");

    } while (1);//循环玩游戏



}