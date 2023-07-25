#include<vector>
#include<queue>
using namespace std;
//col : x, row : y
void dfs(vector<vector<int>> maps, int x, int y,int count, int& answer){
    maps[y][x] = 0;
    //도착하면
    if(y == maps.size() - 1 && x == maps[0].size() - 1){
        if(answer != -1)
            answer = answer > count ? count : answer;
        else
            answer = count;
        return;
    } 
    if(answer != -1 && answer <= count) return;
    //up, down, left, right
    if(y != 0 && maps[y - 1][x] != 0)
        dfs(maps, x, y-1, count +1, answer);
    if(y != maps.size() - 1 && maps[y + 1][x] != 0)
        dfs(maps, x, y+1, count +1, answer);
    if(x != 0 && maps[y][x - 1] != 0)
        dfs(maps, x - 1, y, count +1, answer);
    if(x != maps[0].size() - 1 && maps[y][x + 1] != 0)
        dfs(maps, x+1, y, count +1, answer);
}
struct node{
    int x;
    int y;
    int count = 0;
    node(int x, int y, int num): x(x), y(y), count(num){};
};

void bfs(vector<vector<int> > maps, int& answer){
    queue<node> q;
    node temp = node(0,0,1);
    q.push(temp);
    while(!q.empty()){
        node n = q.front();
        maps[n.y][n.x] = 0;
        //도착
        if(n.y == maps.size() - 1 && n.x == maps[0].size() - 1){
            answer = n.count;
            break;
        }
        else{
            //up
            if(n.y != 0 && maps[n.y-1][n.x] != 0){
                q.push(node(n.x, n.y - 1, n.count +1));
                maps[n.y-1][n.x] = 0;
            }
            //down
            if(n.y != maps.size() - 1 && maps[n.y + 1][n.x] != 0){
                q.push(node(n.x, n.y + 1, n.count + 1));
                maps[n.y + 1][n.x] = 0;
            }
            //left
            if(n.x != 0 && maps[n.y][n.x -1] != 0){
                q.push(node(n.x - 1, n.y , n.count + 1));
                maps[n.y][n.x -1] = 0;
            }
            //right
            if(n.x != maps[0].size() - 1 && maps[n.y][n.x + 1] != 0){
                q.push(node(n.x + 1, n.y, n.count + 1));
                maps[n.y][n.x + 1] = 0;
            }
        }
        q.pop();
    }
}
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    //dfs(maps, 0, 0, 1, answer);
    bfs(maps,answer);
    return answer;
}
