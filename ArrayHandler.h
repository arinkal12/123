#include <cstdint>
#include <cstring>
#include <iostream>

class ArrayHandler {
private:
    int8_t* _array;
    int8_t _max;
    int8_t _min;
    long long int _size;
    long long int _count;
public:
    ArrayHandler(int8_t size = 10){ // О(1) не зависим от размера массива храним фио 
        _size = size;
        _array = new int8_t[_size];
        _max = INT8_MIN;
        _min = INT8_MAX;
        _count = 0;
    }
    void Append(int8_t new_element){// О(
        if (_count == _size) {
            _size = _size +10;
            int8_t* new_arr = new int8_t[_size];
            std::memcpy(new_arr, _array, _count*sizeof(int8_t));
            delete [] _array;
            _array = new_arr;
        }
        _array[_count] = new_element;
        _count++;
        if (new_element > _max) {
            _max = new_element;
        }
        if (new_element < _min) {
            _min = new_element;
        }
    
    }


    int GetMax(){ // О(1)
        return _max; 
    } 

    int GetMin(){ // О(1)
        return _min; 
    } 
    long long GetIndexElem(int8_t elem){
        int l = 0, r = _count - 1;
        while (l <=r) {
            int mid = l+ (r - l) / 2;
            if (_array[mid]==elem) {
                return mid;
            } else if (_array[mid]< elem) {
                l =mid + 1;
            } else {
                r =mid - 1;
            }
        }
        return -1; 
    }
    /*long long GetIndexElem(int8_t elem){// О(N)
    // доп память для храненияпервого встр индекса
    //бинераный поиск 
        for (int i = 0; i < _count; i++) 
            if (elem == _array[i]) 
                return i;

        return -1;
    }*/
    ~ArrayHandler() {// О(1)
        delete [] _array;
    }
};

