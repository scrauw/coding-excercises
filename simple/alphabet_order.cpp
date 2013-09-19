#include <iostream>
#include <vector>

using namespace std;

void add_edge(char a, char b)
{
  cout << a << ", " << b << endl;
}

void dictionary2graph(const string *begin, const string *end, int charno)
{
  char c = 0;
  const string *range_start = begin;
  for(const string *i = begin; i != end; ++i) {
    char cc = (*i)[charno];
    if (cc != c) {
      if (c != 0) {
        add_edge(c, cc);
        dictionary2graph(range_start, i, charno + 1);
        range_start = i;
      }
      c = cc;
    }
  }
  if (range_start < end)
    dictionary2graph(range_start, end, charno + 1);
}

void get_sorted_alphabet(const vector<string>& dictionary, string& alphabet)
{
  dictionary2graph(&dictionary[0], &dictionary[0] + dictionary.size(), 0);
}

int main()
{
  const char *dict [] = {
    "art",
    "ass",
    "bar",
    "bee",
    "cart",
    "court",
    "creek",
    "ebony",
    "eery"
  };

  string alphabet;
  get_sorted_alphabet(
    vector<string>(dict, dict + sizeof(dict)/sizeof(dict[0])),
    alphabet);

  cout << alphabet << endl;

  return 0;
}