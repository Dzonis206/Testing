#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <type_traits>
using namespace std;
using namespace std::chrono;

template <typename T>
void generateRandomArray(vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (is_same<T, int>::value) {
            arr[i] = rand() % 100;
        }
        else if (is_same<T, float>::value) {
            arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 100.0f;
        }
        else if (is_same<T, double>::value) {
            arr[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 100.0;
        }
    }
}

template <typename T>
void generateRandomArray(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (is_same<T, int>::value) {
            arr[i] = rand() % 100;
        }
        else if (is_same<T, float>::value) {
            arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 100.0f;
        }
        else if (is_same<T, double>::value) {
            arr[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 100.0;
        }
    }
}

template <typename T>
void measureAndPrintGenerateRandomArrayTime(vector<T>& arr) {
    auto start = high_resolution_clock::now();
    generateRandomArray(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<duration<double>>(stop - start);
    cout << "Czas generowania losowej tablicy: " << duration.count() << " sekund" << endl;
}

template <typename T>
void measureAndPrintGenerateRandomArrayTime(T* arr, int size) {
    auto start = high_resolution_clock::now();
    generateRandomArray(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<duration<double>>(stop - start);
    cout << "Czas generowania losowej tablicy: " << duration.count() << " sekund" << endl;
}

template <typename T>
void bubbleSortForForIndex(vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

template <typename T>
void bubbleSortForForIndex(T* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

template <typename T>
void bubbleSortForWhileForIndex(vector<T>& arr) {
    int i = 0;
    while (i < arr.size() - 1) {
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        i++;
    }
}

template <typename T>
void bubbleSortForWhileForIndex(T* arr, int size) {
    int i = 0;
    while (i < size - 1) {
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        i++;
    }
}

template <typename T>
void bubbleSortForWhileIndex(vector<T>& arr) {
    int i = 0;
    while (i < arr.size() - 1) {
        int j = 0;
        while (j < arr.size() - i - 1) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            j++;
        }
        i++;
    }
}

template <typename T>
void bubbleSortForWhileIndex(T* arr, int size) {
    int i = 0;
    while (i < size - 1) {
        int j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            j++;
        }
        i++;
    }
}

template <typename T>
void bubbleSortForForPointer(vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        for (int j = 0; j < arr.size() - 1; j++) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
void bubbleSortForForPointer(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        for (int j = 0; j < size - 1; j++) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
void bubbleSortForWhilePointer(vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        int j = 0;
        while (j < arr.size() - 1) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
            j++;
        }
    }
}

template <typename T>
void bubbleSortForWhilePointer(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        int j = 0;
        while (j < size - 1) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
            j++;
        }
    }
}

template <typename T>
void bubbleSortWhileForPointer(vector<T>& arr) {
    int i = 0;
    while (i < arr.size() - 1) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        for (int j = 0; j < arr.size() - 1; j++) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
        }
        i++;
    }
}

template <typename T>
void bubbleSortWhileForPointer(T* arr, int size) {
    int i = 0;
    while (i < size - 1) {
        T* w1 = &arr[0];
        T* w2 = w1 + 1;
        for (int j = 0; j < size - 1; j++) {
            if (*w2 < *w1) {
                T temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
        }
        i++;
    }
}

template <typename T>
void printArray(const vector<T>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void printArray(const T* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
duration<double> measureSortTime(vector<T>& arr, void (*sortFunc)(vector<T>&)) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<duration<double>>(stop - start);
}

template <typename T>
duration<double> measureSortTime(T* arr, int size, void (*sortFunc)(T*, int)) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, size);
    auto stop = high_resolution_clock::now();
    return duration_cast<duration<double>>(stop - start);
}

template <typename T>
bool isSorted(const T* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool isSorted(const vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> sizes = { 100, 1000, 10000 };

    vector<string> sortNames = {
        "BubbleSortForForIndex",
        "BubbleSortForWhileForIndex",
        "BubbleSortForWhileIndex",
        "BubbleSortForForPointer",
        "BubbleSortForWhilePointer",
        "BubbleSortWhileForPointer"
    };

    vector<void(*)(vector<int>&)> intSortFuncsVec = {
        bubbleSortForForIndex<int>,
        bubbleSortForWhileForIndex<int>,
        bubbleSortForWhileIndex<int>,
        bubbleSortForForPointer<int>,
        bubbleSortForWhilePointer<int>,
        bubbleSortWhileForPointer<int>
    };

    vector<void(*)(int*, int)> intSortFuncsArr = {
        bubbleSortForForIndex<int>,
        bubbleSortForWhileForIndex<int>,
        bubbleSortForWhileIndex<int>,
        bubbleSortForForPointer<int>,
        bubbleSortForWhilePointer<int>,
        bubbleSortWhileForPointer<int>
    };

    vector<void(*)(vector<float>&)> floatSortFuncsVec = {
        bubbleSortForForIndex<float>,
        bubbleSortForWhileForIndex<float>,
        bubbleSortForWhileIndex<float>,
        bubbleSortForForPointer<float>,
        bubbleSortForWhilePointer<float>,
        bubbleSortWhileForPointer<float>
    };

    vector<void(*)(float*, int)> floatSortFuncsArr = {
        bubbleSortForForIndex<float>,
        bubbleSortForWhileForIndex<float>,
        bubbleSortForWhileIndex<float>,
        bubbleSortForForPointer<float>,
        bubbleSortForWhilePointer<float>,
        bubbleSortWhileForPointer<float>
    };

    vector<void(*)(vector<double>&)> doubleSortFuncsVec = {
        bubbleSortForForIndex<double>,
        bubbleSortForWhileForIndex<double>,
        bubbleSortForWhileIndex<double>,
        bubbleSortForForPointer<double>,
        bubbleSortForWhilePointer<double>,
        bubbleSortWhileForPointer<double>
    };

    vector<void(*)(double*, int)> doubleSortFuncsArr = {
        bubbleSortForForIndex<double>,
        bubbleSortForWhileForIndex<double>,
        bubbleSortForWhileIndex<double>,
        bubbleSortForForPointer<double>,
        bubbleSortForWhilePointer<double>,
        bubbleSortWhileForPointer<double>
    };

    cout << left << setw(30) << "Sortowanie" << setw(15) << "int" << setw(15) << "float" << setw(15) << "double" << endl;
    cout << string(75, '-') << endl;

    for (int n : sizes) {
        cout << "Dla tablicy o rozmiarze: " << n << endl;
        vector<int> intTabVec(n);
        vector<float> floatTabVec(n);
        vector<double> doubleTabVec(n);

        int* intTabArr = new int[n];
        float* floatTabArr = new float[n];
        double* doubleTabArr = new double[n];

        for (int i = 0; i < sortNames.size(); i++) {
            generateRandomArray(intTabVec);
            generateRandomArray(floatTabVec);
            generateRandomArray(doubleTabVec);

            generateRandomArray(intTabArr, n);
            generateRandomArray(floatTabArr, n);
            generateRandomArray(doubleTabArr, n);

            auto intDurationVec = measureSortTime(intTabVec, intSortFuncsVec[i]);
            auto floatDurationVec = measureSortTime(floatTabVec, floatSortFuncsVec[i]);
            auto doubleDurationVec = measureSortTime(doubleTabVec, doubleSortFuncsVec[i]);

            generateRandomArray(intTabArr, n);
            generateRandomArray(floatTabArr, n);
            generateRandomArray(doubleTabArr, n);

            auto intDurationArr = measureSortTime(intTabArr, n, intSortFuncsArr[i]);
            auto floatDurationArr = measureSortTime(floatTabArr, n, floatSortFuncsArr[i]);
            auto doubleDurationArr = measureSortTime(doubleTabArr, n, doubleSortFuncsArr[i]);

            if (n == 100 || n == 1000) {
                cout << left << setw(30) << sortNames[i]
                    << setw(15) << duration_cast<nanoseconds>(intDurationVec).count() << " ns / " << duration_cast<nanoseconds>(intDurationArr).count() << " ns -------- "
                    << setw(15) << duration_cast<nanoseconds>(floatDurationVec).count() << " ns / " << duration_cast<nanoseconds>(floatDurationArr).count() << " ns -------- "
                    << setw(15) << duration_cast<nanoseconds>(doubleDurationVec).count() << " ns / " << duration_cast<nanoseconds>(doubleDurationArr).count() << " ns" << endl;
            }
            else {
                cout << left << setw(30) << sortNames[i]
                    << setw(15) << intDurationVec.count() << " s / " << intDurationArr.count() << " s -------- "
                    << setw(15) << floatDurationVec.count() << " s / " << floatDurationArr.count() << " s -------- "
                    << setw(15) << doubleDurationVec.count() << " s / " << doubleDurationArr.count() << " s" << endl;
            }

            cout << "Czy intTabVec jest posortowane? " << (isSorted(intTabVec) ? "Tak" : "Nie") << endl;
            cout << "Czy floatTabVec jest posortowane? " << (isSorted(floatTabVec) ? "Tak" : "Nie") << endl;
            cout << "Czy doubleTabVec jest posortowane? " << (isSorted(doubleTabVec) ? "Tak" : "Nie") << endl;

            cout << "Czy intTabArr jest posortowane? " << (isSorted(intTabArr, n) ? "Tak" : "Nie") << endl;
            cout << "Czy floatTabArr jest posortowane? " << (isSorted(floatTabArr, n) ? "Tak" : "Nie") << endl;
            cout << "Czy doubleTabArr jest posortowane? " << (isSorted(doubleTabArr, n) ? "Tak" : "Nie") << endl;
        }

        delete[] intTabArr;
        delete[] floatTabArr;
        delete[] doubleTabArr;
    }

    return 0;
}
