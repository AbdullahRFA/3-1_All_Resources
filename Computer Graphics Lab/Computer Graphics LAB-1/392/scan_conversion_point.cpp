#include<iostream>
using namespace std;
char screen[80][25]={};
void scanConvertPoint(int x,int y)
{
    screen[x][y]='*';
}
int main()
{
    int x,y;
    cout<<"Enter X axis point: ";
    cin>>x;
    cout<<"\nEnter Y axis point: ";
    cin>>y;
    scanConvertPoint(x,y);
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<80;j++)
        {
            cout<<screen[j][i];
        }
        cout<<endl;
    }
    return 0;


}