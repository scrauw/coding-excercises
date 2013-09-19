#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct mypair {
  int n;
  int h;
};

bool compare_mypairs(const mypair& p1, const mypair& p2)
{
  return p1.n < p2.n || p1.n == p2.n && p1.h < p2.h;
}

void reconstruct_queue(mypair *mypairs, int size, list<int>& result)
{
  while (size > 0) {
    sort(mypairs, mypairs + size, compare_mypairs);
    mypair *first = mypairs;
    result.push_back(first->h);
    ++mypairs;
    --size;
    for(mypair *p = mypairs; p < mypairs + size; ++p)
      if (p->h < first->h)
        --p->n;
  } 
}

template<class T>
void print(T begin, T end)
{
  for(T i = begin; i != end; ++i)
    cout << *i << " ";
  cout << endl;
}


int main()
{
  int queue[] = { 7, 1, 4, 2, 9, 5 };
  int size = sizeof(queue)/sizeof(queue[0]);
  vector<mypair> mypairs(size);

  cout << "original queue:\n";
  print(queue, queue + size);

  for(int i = 0; i < size; ++i) {
    int n = 0;
    for(int j = 0; j < i; ++j) {
      if (queue[j] > queue[i])
        ++n;
    }
    mypairs[i].n = n;
    mypairs[i].h = queue[i];
  }


  random_shuffle(mypairs.begin(), mypairs.end());

  cout << "shuffled queue:\n";
  for(int i = 0; i < size; ++i)
    cout << mypairs[i].h << " ";
  cout << endl;
//  for(int i = 0; i < size; ++i)
//    cout << mypairs[i].n << " ";
//  cout << endl;

  list<int> rqueue;
  reconstruct_queue(&mypairs[0], mypairs.size(), rqueue);

  cout << "reconstructed queue:\n";
  print(rqueue.begin(), rqueue.end());

  return 0;
}