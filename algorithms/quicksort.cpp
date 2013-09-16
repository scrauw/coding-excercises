#include <iostream>

using namespace std;

void swap(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int partition(int a[], int b, int e)
{
  int j = b;
  for (int i = b + 1; i < e; ++i) {
    if (a[i] < a[b]) {
      if (i - j > 1) 
        swap(a, i, j + 1);
      ++j;
    }
  }
  if (j != b)
    swap(a, b, j);

  return j;
}

void qs(int a[], int b, int e)
{
  if (e - b <= 1)
    return;

  int j = partition(a, b, e);
  qs(a, b, j + 1);
  qs(a, j + 1, e);
}

int main()
{
  int a[] = { 3, 1, 4, 2, 5 };
  for(int i = 0; i < 5; ++i)
    cout << a[i] << " ";
  cout << "\n";

  qs(a, 0, 5);

  for(int i = 0; i < 5; ++i)
    cout << a[i] << " ";
  cout << "\n";
 
  return 0;
}