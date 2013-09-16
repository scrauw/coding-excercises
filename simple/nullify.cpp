#include <iostream>
#include <vector>

using namespace std;

// *this is from microsoft coding interview*
// In a two dimensional array of integers of size m x n, for each element which value is zero, 
// set to zero the entire row and the column where this element is located, and leave the 
// rest of the elements untouched. 

void nullify(int **a, size_t n, size_t m)
{
  vector<bool> rows_to_nullify(n, false);
  vector<bool> cols_to_nullify(m, false);

  for(size_t i = 0; i < n; ++i) {
    for(size_t j = 0; j < m; ++j) {
      if (!a[i][j]) {
        rows_to_nullify[i] = true;
        cols_to_nullify[j] = true;
      }
    }
  }


  for(size_t i = 0; i < n; ++i)
    for(size_t j = 0; j < m; ++j)
      if (rows_to_nullify[i] || cols_to_nullify[j])
        a[i][j] = 0;
}

void print(int **a, size_t n, size_t m)
{
  for(size_t i = 0; i < n; ++i) {
    for(size_t j = 0; j < m; ++j)
      cout << a[i][j] << " ";
    cout << "\n";
  }
}

int main()
{
  int x[] = { 
	1,0,3,4,
	1,2,3,4,
	1,2,3,0
  };

  int **a = new int *[3];
  for(int i = 0; i < 3; ++i)
    a[i] = new int[4];

   
  for(int i = 0; i < 12; ++i)
    a[i/4][i%4] = x[i];

  print(a, 3, 4);

  cout << endl;

  nullify(a, 3, 4);

  print(a, 3, 4);

  cout << endl;

  return 0;
}