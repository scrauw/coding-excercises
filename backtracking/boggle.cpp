#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, bool> words;

class Dictionary
{
public:
  bool lookup(const string& s) {
    return s == "cat" || s == "cart";
  }
};

Dictionary dictionary;

void clear_visited(bool v[4][4])
{
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      v[i][j] = false;
}

void solve_boggle(char board[4][4], int i, int j, bool visited[4][4], string word);

void solve_boggle(char board[4][4])
{
  bool visited[4][4] = { false };
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j) {
      clear_visited(visited);
      solve_boggle(board, i, j, visited, "");
    }
}

void solve_boggle(char board[4][4], int i, int j, bool visited[4][4], string word)
{
  if (i < 0 || j < 0 || i > 3 || j > 3 || visited[i][j])
    return;

  word += board[i][j];

  if (dictionary.lookup(word))
    words[word] = true;

  visited[i][j] = true;

  for(int di = -1; di <= 1; ++di)
    for(int dj = -1; dj <= 1; ++dj) 
      solve_boggle(board, i + di, j + dj, visited, word);

  visited[i][j] = false;
}


int main()
{
  char board[4][4] = { 
    'c', 'a', 'g', 't',
    't', 'r', 'e', 'n',
    'o', 'i', 'm', 'e',
    'f', 'j', 'w', 'l'
  };

  solve_boggle(board);

  for(map<string, bool>::const_iterator i = words.begin(); i != words.end(); ++i) {
    cout << i->first << endl;
  }

  return 0;
}