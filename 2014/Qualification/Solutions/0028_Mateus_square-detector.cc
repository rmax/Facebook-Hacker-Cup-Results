#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

char mapa[30][30];
bool visited[30][30];
int n, area;

void fill_white( int x, int y ){
  if( x <= 0 || x > n || y <= 0 || y > n ) return;
  if( mapa[x][y] != '.' ) return;
  if( visited[x][y] ) return;
  visited[x][y] = true;
  fill_white(x+1,y);
  fill_white(x,y+1);
  fill_white(x-1,y);
  fill_white(x,y-1);
}

void fill_black( int x, int y, int &min_x, int &min_y, int &max_x, int &max_y){
  if( x <= 0 || x > n || y <= 0 || y > n ) return;
  if( mapa[x][y] != '#' ) return;
  if( visited[x][y] ) return;
  area++;
  visited[x][y] = true;
  min_x = min(min_x,x);
  min_y = min(min_y,y);
  max_x = max(max_x,x);
  max_y = max(max_y,y);
  fill_black(x+1,y,min_x,min_y,max_x,max_y);
  fill_black(x,y+1,min_x,min_y,max_x,max_y);
  fill_black(x-1,y,min_x,min_y,max_x,max_y);
  fill_black(x,y-1,min_x,min_y,max_x,max_y);
}

int main(){
  /* freopen("square_detector.txt","r",stdin);
     freopen("square_output.txt","w",stdout);*/
  int t;
  scanf("%d", &t);
  int tt = 1;
  while(t--){
    scanf("%d", &n);
    for( int i = 1; i <= n; i++)
      for( int j = 1; j <= n; j++)
	scanf(" %c", &mapa[i][j]);
    memset(visited,false,sizeof(visited));
    int white_regions = 0;
    int black_regions = 0;
    int max_x, max_y, min_x, min_y;
    max_x = max_y = -1;
    min_x = min_y = 30;
    area = 0;
    for( int i = 1; i <= n; i++)
      for( int j = 1; j <= n; j++){
	if(!visited[i][j]){
	  if( mapa[i][j] == '.' ){
	    white_regions++;
	    fill_white(i,j);
	  }else{
	    black_regions++;
	    fill_black(i,j,min_x,min_y,max_x,max_y);
	  }
	}
      }
    printf("Case #%d: ", tt++);
    if( black_regions > 1 || white_regions > 1 || ((max_y - min_y) != (max_x - min_x)) || (area != ((max_y - min_y + 1)*(max_x - min_x + 1))) ){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
  }
  return 0;
}
