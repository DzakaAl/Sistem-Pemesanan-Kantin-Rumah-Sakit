#ifndef ARRAY1DDINAMIS_H
#define ARRAY1DDINAMIS_H
using namespace std;

template <class T> class Array1Ddinamis {
public:
  Array1Ddinamis(int sz) : size(sz) {
    elements = new T[sz];
    for (int i = 0; i < sz; i++) {
      elements[i] = T();
    }
  }

  ~Array1Ddinamis() { delete[] elements; }

  Array1Ddinamis<T> &ReSize(int sz) {
    if (sz != size) {
      T *newElements = new T[sz];
      for (int i = 0; i < std::min(sz, size); i++) {
        newElements[i] = elements[i];
      }
      delete[] elements;
      elements = newElements;
      size = sz;
    }
    return *this;
  }

  T &operator[](int index) {
    if (index >= 0 && index < size) {
      return elements[index];
    } else {
      throw std::out_of_range("Index out of range");
    }
  }

  const T &operator[](int index) const {
    if (index >= 0 && index < size) {
      return elements[index];
    } else {
      throw std::out_of_range("Index out of range");
    }
  }

  int Size() const { return size; }

private:
  T *elements;
  int size;
};

#endif