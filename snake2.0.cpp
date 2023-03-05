#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
#define N 20
int x=N/2,y=N/2;
void Ready(int maze[][N], int mx[])
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==0||j==0||i==N-1||j==N-1){
                maze[i][j]=1; //1代表墙
            }
            else{
                maze[i][j]=0; //0代表路
            }
        }
    }
    maze[N/2][N/2]=2;//2代表蛇的位置
    srand((unsigned)time(NULL));//随机函数种子发生器（以时间做参数）
    mx[0]=rand()%(N-2)+1;
    mx[1]=rand()%(N-2)+1;
    maze[mx[0]][mx[1]]=3;//3代表食物的位置
}
void Draw(int maze[][N])
{
    int x,y;
    system("cls");//清屏
    cout<<endl;
    for(x=0;x<N;x++)
    {
        for(y=0;y<N;y++)
        {
            if(maze[x][y]==0){cout<<"  ";continue;}//通路
            if(maze[x][y]==1){cout<<"■";continue;}//墙
            if(maze[x][y]==2){cout<<"※";continue;}//当前蛇的位置
            if(maze[x][y]==3){cout<<"○";continue;}//食物位置
        }
        cout<<endl;
    }
}
void JudgeGo(int maze[][N],char ch, char flag[])
{
    switch(ch)
    {
        case 'L':
        case 'l':
            if(flag[0]=='R') break;
            if(maze[x][y-1]==0||maze[x][y-1]==3){
                maze[x][y]=0;
                y--;
                flag[0] = 'L';
            }
            break;
        case 'R':
        case 'r':
            if(flag[0]=='L') break;
            if(maze[x][y+1]==0||maze[x][y+1]==3){
                maze[x][y]=0;
                y++;
                flag[0] = 'R';
            }
            break;
        case 'U':
        case 'u':
            if(flag[0]=='D') break;
            if(maze[x-1][y]==0||maze[x-1][y]==3){
                maze[x][y]=0;
                x--;
                flag[0] = 'U';
            }
            break;
        case 'D':
        case 'd':
            if(flag[0]=='U') break;
            if(maze[x+1][y]==0||maze[x+1][y]==3){
                maze[x][y]=0;
                x++;
                flag[0] = 'D';
            }
            break;
    }
    maze[x][y]=2;
}
int main()
{
    int maze[N][N],mx[2];
    char ch;char flag[1]={'T'};
    Ready(maze, mx);
    ch = 'L';
    while(true)
    {
        Draw(maze);
        Sleep(50);
        while(kbhit()){
            ch = getch();
        }
        JudgeGo(maze,ch,flag);
        if(mx[0]==x && mx[1]==y) break;
    }
    cout<<"success!";
    return 0;
}

