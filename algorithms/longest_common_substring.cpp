#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_common_substring(const string& s, const string& t)
{
  size_t m = s.size();
  size_t n = t.size();
  vector<int> d(m*n);

  for(size_t i = 0; i < m; ++i)
    d[i] = 0;

  for(size_t i = 1; i < n; ++i)
    d[i*m] = 0;

  for(size_t i = 1; i < n; ++i)
    for(size_t j = 1; j < m; ++j) {
      if (s[j] == t[i])
        d[i*m + j] = d[(i - 1)*m + j - 1] + 1;
      else 
        d[i*m + j] = 0;//max(d[(i - 1)*m + j], d[i*m + j - 1]);
    }

  int result = 0;
  for(size_t i = 1; i < n; ++i) {
    for(size_t j = 1; j < m; ++j) {
      if (result < d[i*m + j])
        result = d[i*m + j];
      cout << d[i*m + j] << ' ';
    }
    cout << '\n';
  }  

  return result;
}

int main(int argc, char **argv)
{
  cout << longest_common_substring(argv[1], argv[2]);

  return 0;
}
