#include <iostream>
using namespace std;
int main()
{
    int x=1,y=2,mx=10,my=9;
    char ch;
    char flag;
    cout<<"ready!\n";
    while(true)
    {
        cout<<"draw!\n";
        cin>>ch;
        switch(ch)
        {
            case 'L':
            case 'l':
                if(flag=='R') continue;
                y--;
                cout<<"turn left:"<<x<<" "<<y<<endl;
                flag = 'L';
                break;
            case 'R':
            case 'r':
                if(flag=='L') continue;
                y++;
                cout<<"turn right:"<<x<<" "<<y<<endl;
                flag = 'R';
                break;
            case 'U':
            case 'u':
                if(flag=='D') continue;
                x--;
                cout<<"turn up:"<<x<<" "<<y<<endl;
                flag = 'U';
                break;
            case 'D':
            case 'd':
                if(flag=='U') continue;
                x++;
                cout<<"turn down:"<<x<<" "<<y<<endl;
                flag = 'D';
                break;
            default:
                cout<<"press error:"<<x<<" "<<y<<endl;
        }
        if(mx==x && my==y) break;
    }
    cout<<"success!";
    return 0;
}

