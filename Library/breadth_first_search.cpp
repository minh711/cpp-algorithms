#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define is_uppercase(x) (x) >= 65 && (x) <= 90
#define is_lowercase(x) (x) >= 97 && (x) <= 122

#define f first
#define s second;
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

int main()
{
  vi dx = {0, 0, -1, 1};
  vi dy = {-1, 1, 0 , 0};
  int n;
  int m;
  cin >> n;
  cin >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  F0R(i, n)
  {
    F0R(j, m)
    {
      cin >> matrix[i][j];
    }
  }
  vector<vector<int>> vis(n, vector<int>(m));
  queue<pi> q;
  if (matrix[0][0] != 1 && matrix[n - 1][m - 1] != 1)
  {
    vis[0][0] = 1;
    q.push({0, 0});
  }
  else
  {
    cout << "No" << endl;
    return 0;
  }

  auto is_inside = [&](int x, int y)
  {
    return 0 <= x && x < n && 0 <= y && y < m;
  };

  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    int x = p.f;
    int y = p.s;
    F0R(k, 4)
    {
      int tx = x + dx[k];
      int ty = y + dy[k];

      if (tx == (n - 1) && ty == (m - 1))
      {
        cout << "Yes" << endl;
        return 0;
      }

      if (is_inside(tx, ty) && matrix[tx][ty] != 1 && vis[tx][ty] != 1)
      {
        vis[tx][ty] = 1;
        q.push({tx, ty});
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
