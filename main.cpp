#include <iostream>
#include <string.h>

using namespace std;

class Sort {
public:
    virtual void sort(int *array, int size) = 0;
};

class MergeSort : public Sort {
private:
    void _sort(int *array, int left, int right) {
        if (right == left)
            return;

        if (right - left == 1) {
            if (array[right] < array[left]) {
                swap(array[right], array[left]);
            }
            return;
        }

        int middle = (right + left) / 2;
        _sort(array, left, middle);
        _sort(array, middle + 1, right);

        int *buf = nullptr;
        buf = new int[right+1];

        int new_left = left;
        int new_right = middle + 1;
        int current = 0;

        while (right - left + 1 != current) {

            if (new_left > middle)
                buf[current++] = array[new_right++];
            else if (new_right > right)
                buf[current++] = array[new_left++];
            else {
                if (array[new_left] > array[new_right])
                    buf[current++] = array[new_right++];
                else buf[current++] = array[new_left++];
            }
        }

        for (int i = 0; i < current; i++) {
            array[i + left] = buf[i];
        }
        delete buf;
    }

public:
    void sort(int *array, int size) {
        _sort(array, 0, size-1);
    };
};

void printSortedArray(Sort &sort, int *arr, int n) {
    int *res = new int[n];
    memcpy(res, arr, n * sizeof(int));

    sort.sort(res,n);

    for (int i = 0; i < n; i++) {
        std::cout << " " << res[i];
    }
};


int main() {
    int size(6);
    int arr[] = {5, 2, 3, 2, 1, 1};

    MergeSort s1;

    printSortedArray(s1, arr, size);

    return 0;
}