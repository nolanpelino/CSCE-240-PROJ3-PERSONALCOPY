// Copyright 2021 Nolan Pelino
#include "./ArrayList.h"

template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    os << "[";
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "]";
    return os;
}

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}

template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    setSize(copy.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] data;
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & rhs) const {
    if (this->size != rhs.size)
        return true;
    for (int i = 0; i < size; i++) {
        if (data[i] == rhs[i])
            return false;
    }
    return true;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T val) const {
    ArrayList<T> retList;
    retList.size = this->size;
    for (int i = 0; i < size; i++)
        retList.data[i] = this->data[i];

    for (int i = 0; i < size; i++)
        retList.data[i] += val;

    return retList;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(const ArrayList<T> & rhs) const {
    ArrayList<T> retList;
    retList.size = this->size;
    for (int i = 0; i < size; i++)
        retList.data[i] = this->data[i];
    if (this->size != rhs.size)  // Returns if sizes do not match
        return retList;
    for (int i = 0; i < size; i++)
        retList.data[i] += rhs.data[i];

    return retList;
}

template <class T>
ArrayList<T> & ArrayList<T>::operator--() {
    if (size == 0)
        return *this;
    size -= 1;
    for (int i = 0; i < size; i++)
        data[i] = data[i];
    return *this;
}

template <class T>
ArrayList<T> ArrayList<T>::operator--(int) {
    if (size == 0)
        return *this;
    ArrayList<T> retList;
    retList.size = this->size;
    for (int i = 0; i < size; i++)
        retList.data[i] = this->data[i];
    size -= 1;
    for (int i = 0; i < size; i++)
        data[i] = data[i];
    return retList;
}

template <class T>
void ArrayList<T>::operator+=(T val) {
    size++;
    data[size - 1] = val;
    return;
}

template <class T>
void ArrayList<T>::operator+=(const ArrayList<T> & rhs) {
    int oldSize = this->size;
    this->size += rhs.size;
    int j(0);
    for (int i = oldSize; i < this->size; i++) {
        this->data[i] = rhs.data[j];
        j++;
    }
    return;
}

template <class T>
ArrayList<T> ArrayList<T>::operator*(int val) const {
    ArrayList<T> retList;
    retList.size = this->size;
    for (int i = 0; i < retList.size; i++)
        retList.data[i] = this->data[i];

    retList.size = retList.size * val;
    int j(0);
    for (int i = this->size; i < retList.size; i++) {
        retList.data[i] = retList.data[j];
        if (j < this->size)
            j++;
        else
            j = 0;
    }
    return retList;
}

template <class T>
ArrayList<T> ArrayList<T>::operator/(int val) const {
    ArrayList<T> retList;
    retList.size = this->size / val;
    for (int i = 0; i < retList.size; i++)
        retList.data[i] = this->data[i];
    return retList;
}
