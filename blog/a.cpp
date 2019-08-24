#include <iostream>
using namespace std;

struct point{
    int x,y;
}src,dest;

struct warmhole{
    int sx,sy,ex,ey,cost;
}warm[1000];

int ans;
bool visited[1001] = {false};
 
int abs(int a){
    return (a>0? a:-a);
}

//a functioni to calculate distance bwtween two points
int finddist(point a, point b){
    return (abs(a.x-b.x) + abs(a.y-b.y));
}


void minDist(point curPoint, int distance, int n){
    if(curPoint.x==dest.x && curPoint.y==dest.y) return;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i]=true;

            point p;
            p.x=warm[i].sx ; p.y=warm[i].sy;

            int temp1=finddist(curPoint,p);
            int temp2=finddist(warm[i].cost);

            p.x=warm[i].ex; p.y=warm[i].ey;

            minDist(p, distance + temp1 + temp2, n-1);

            //backtrack
            visited[i]=false;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        
        cin>>src.x>>src.y;      //enter the starting point
        cin>>dest.x>>dest.y;   //enter the destination point/
        
        cin>>n;       ///enter no of warmholes
        for(int i=0; i<n; i++)
            cin>>warm[i].sx>>warm[i].sy>>warm[i].ex>>warm[i].ey>>warm[i].cost;

        ans=finddist(src,dest);

        minDist(src,0,n);        // passing source point, distance travelled and no of warmholes left
    }
}
