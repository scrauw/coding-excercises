#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template<class T>
class heap
{
    std::vector<T> m_data;

    static int parent(int i) {
        return (i + 1)/2 - 1;
    }

    static int left_child(int i) {
        return (i + 1)*2 - 1;
    }
public:
    heap() {
       m_data.reserve(100);
    }

    void insert(int n) {
       m_data.push_back(n);
       if (m_data.size() == 1)
          return;
       int i = m_data.size() - 1;
       int p = parent(i);
       while (i > 0 && m_data[p] > m_data[i]) {
          std::swap(m_data[i], m_data[p]);
          i = p;
          p = parent(i);
       }
    }

    T extract_min() {
       if (m_data.size() == 0)
           throw std::runtime_error("container is empty");
       T result = m_data[0];
       std::swap(m_data[0], m_data.back());
       m_data.pop_back();

       int i = 0;
       int c = left_child(i);
       while (c < m_data.size() && m_data[i] > m_data[c] && c + 1 < m_data.size() && m_data[i] > m_data[c + 1]) {
          if (m_data[c] > m_data[c + 1])
             c = c + 1;
           std::swap(m_data[i], m_data[c]);
           i = c;          
       }
       if (c < m_data.size() && m_data[i] > m_data[c]) {
           std::swap(m_data[i], m_data[c]);
       }

       return result;
    }

    int size() const {
        return m_data.size();
    }
};

int main()
{
    int a[] = { 5,2,7,4,1,6,3 };
    heap<int> h;

    for(int i = 0; i < 7; ++i) {
       h.insert(a[i]);
    }

    while (h.size()) {
       std::cout << h.extract_min() << " ";
    }

    std::cout << "\n";
 
    return 0;
}