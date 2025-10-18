#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int breshenham(int x1,int y1,int x2,int y2){
    int dx = abs(x1-x2);
    int dy = abs(y2-y1);
    int x= x1;
    int y= y1;
    cout<<"plot: "<<x<<","<<y<<endl;
    //slope<=1
    if(dx>=dy){
        int p = ((2*dy)-dx);
        while(x!=x2){
            if(p<0){
                x= x+1;
                y = y;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dy);
            }
            else{
                x= x+1;
                y= y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dy) - (2*dx);
            }
        }
    }
    else{
        int p = ((2*dx)- dy);
        while(y!=y2){
              if(p<0){
                x= x;
                y = y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dx);
            }
            else{
                x= x+1;
                y= y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dx) - (2*dy);
            }
        }
    }
}
int main()
{
    int a,b,c,d;
    cout<<"(x1,y1) & (x2,y2)"<<endl;
    cin>>a>>b>>c>>d;
    breshenham(a,b,c,d);
    return 0;
}
