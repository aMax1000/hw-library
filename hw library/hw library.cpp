    // hw library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <deque>
#include <iostream>
#include <vector>
#include <set>
#include <cstddef>
using namespace std;

template<typename T>
class CircularBuffer {
    std::vector<T> data;
    size_t tail = 0;
    size_t size = 0;

public:
    CircularBuffer(size_t a) {
        data.reserve(a);
    }
    void push_update(const T& value) {
        this->push_noupdate(value);
        if(size<data.capacity()){
            size++;
        }
    }
    void push_noupdate(const T& value) {
        if(size>0){
            tail = (tail + 1) % data.capacity();
            data[tail] = value;
        }
    }

    T& operator[](size_t i) {
        return data[(tail +1 + i) % data.size()];
    }

    size_t get_size() const {
        return size;
    }
    vector<T> getarr() {
        return data;
    }
    ~CircularBuffer() {
        delete data;
    }
};


template<typename T>
void mymerge(vector<T>& arr, set<T> temp) {
    size_t itt = 0;
    CircularBuffer<T> que(temp.size());
    arr.reserve(arr.size()+temp.size());
    for (size_t i = 0;i < arr.size();i++) {
        if(itt<temp.end()){
            if (arr[i] > temp[itt]) {
                que.push_update(arr[i]);
                arr[i] = temp[itt];
                itt++;
            }else{
                T tempt = que[0];
                que.push_noupdate(arr[i]);
                arr[i] = tempt;
            }
        }
        else {
            T tempt = que[0];
            que.push_noupdate(arr[i]);
            arr[i] = tempt;
        }
    }
    for (size_t i = 0;i < que.get_size();i++) {
        arr[arr.size() + i] = que[i];
    }
    while (itt < temp.size()) {
        arr.push_back(temp[itt]);
    }
}


template<typename T>
class Optarray {
    bool is_compelte;
    vector<T> arr;
    set<T> temp;
public:
    bool is_completeget(){
        return is_compelte;
    }
    void merge() {
        if (is_complete) {
            mymerge(arr, temp);
        }
        is_compelte = true;
    }
    T& operator[](size_t i) {
        this->merge();
        return arr[i];
    }
    push(T ell) {
        temp.insert(ell);
        is_complete = false;
    }
};


int main()
{

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
