#include <iostream>

using namespace std;

int n;
bool visited[101][101] = {false};
string picture[101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx > n || ny < 0 || ny > n)
      continue;
    if (!visited[nx][ny] && picture[nx][ny] == picture[x][y]) {
      visited[nx][ny] = true;
      dfs(nx, ny);
    }
  }
}

int main() 
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> picture[i];
  }
  int normal = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        normal++;
        visited[i][j] = true;
        dfs(i, j);
      }
    }
  }
  cout << normal << ' ';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (picture[i][j] == 'G')
        picture[i][j] = 'R';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      visited[i][j] = false;
  }
  int colorblind = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        colorblind++;
        visited[i][j] = true;
        dfs(i, j);
      }
    }
  }
  cout << colorblind;
}
