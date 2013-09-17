/*

Given a n by m matrix of bits find the largest X that is formed in the matrix and return the size of the diagonal of that X. 
An X is defined as 2 equally sized diagonals that share a single 1. 

For instance, the matrix: 

00100001 
00010010 
00001100 
00001100 
00010010 
00100001 

Will return a size of 1, because the given X is invalid as the middle part does not share a single 1. On the other hand, the following matrix 

101 
010 
101 

Will return a value of 3, as the diagonal is 3. Write such program,
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > matrix;

int get_x_size(const matrix& a, int i0, int j0)
{
  if (!a[i0][j0])
    return 0;
  int n = a.size();
  int m = a[0].size();
  int s = 1;

  while (1) {
    if (i0 - s < 0 || i0 + s >= n || j0 - s < 0 || j0 + s >= m)
      return 2*s - 1;
    for(int di = -1; di <= 1; di += 2)
      for(int dj = -1; dj <= 1; dj += 2) {
//cout << "*1";
        if (!a[i0 + di*s][j0 + dj*s])
          return 2*s - 1;
        if (dj > 0)
          for(int j = j0 - dj*s + 1; j < j0 + dj*s; j += dj) 
            if (a[i0 + di*s][j])
              return 2*s - 1;
//cout << "*2";
        if (di > 0)
          for(int i = i0 - di*s + 1; i < i0 + di*s; i += di) 
            if (a[i][j0 + dj*s])
              return 2*s - 1;
//cout << "*3";
      }
    ++s;
  }
  return 2*s - 1;
}

int get_max_cross(const matrix& a)
{
  if (a.size() == 0)
    return 0;

  int n = a.size();
  int m = a[0].size();

  int max_size = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) {
      int s = get_x_size(a, i, j);
      if (s > max_size)
        max_size = s;
    }

  return max_size;
}


void print_matrix(const matrix& a)
{
  int n = a.size();
  int m = a[0].size();

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) 
      cout << a[i][j] << ' ';
    cout << "\n";
  }
}

int main()
{
  int a1[] = { 1, 0, 1,
               0, 1, 0,
               1, 0, 1 };

  matrix m1( 3, vector <int> (3, 0) );

  for(int i = 0; i < sizeof(a1)/sizeof(a1[0]); ++i)
    m1[i/3][i%3] = a1[i];

  print_matrix(m1);

  cout << get_max_cross(m1) << endl;
  
  int a2[] = { 1, 0, 0, 1, 0,
               0, 1, 1, 0, 0, 
               0, 1, 1, 0, 0,
               1, 0, 0, 1, 0 };

  matrix m2( 4, vector <int> (5, 0) );

  for(int i = 0; i < sizeof(a2)/sizeof(a2[0]); ++i)
    m2[i/5][i%5] = a2[i];

  print_matrix(m2);

  //cout << get_x_size(m2, 1, 1) << endl;
  cout << get_max_cross(m2) << endl;

  int a3[] = { 1, 1, 0, 1, 0,
               0, 0, 1, 0, 0, 
               0, 1, 0, 1, 0,
               1, 0, 0, 1, 1 };

  matrix m3( 4, vector <int> (5, 0) );

  for(int i = 0; i < sizeof(a3)/sizeof(a3[0]); ++i)
    m3[i/5][i%5] = a3[i];

  print_matrix(m3);

  cout << get_max_cross(m3) << endl;

  return 0;
}