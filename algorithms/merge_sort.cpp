#include <vector>
#include <iostream>

void merge_sort(int *a, int n, int *b)
{
  if (n == 1) {
    *b = *a;
    return;
  }    

  merge_sort(a, n/2, b);
  merge_sort(a + n/2, n - n/2, b + n/2);

  int i = 0, j = n/2, k = 0;
  while (i < n/2 && j < n) {
    if (a[i] < a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
    }
  }
  while (i < n/2) {
    b[k++] = a[i++];
  }
  while (j < n) {
    b[k++] = a[j++];
  }
  for(int i = 0; i < n; ++i) {
    a[i] = b[i];    
  }
}

int main()
{
  int a[] = { 9, 1, 3, 4, 8, 6 };
  std::vector<int> r(sizeof(a)/sizeof(a[0]));


  for(int i = 0; i < r.size(); ++i) {
    std::cout << a[i] << " ";
  }

  std::cout << "\n";

  merge_sort(a, r.size(), &r[0]);  

  for(int i = 0; i < r.size(); ++i) {
    std::cout << r[i] << " ";
  }

  std::cout << "\n";

  return 0;
}