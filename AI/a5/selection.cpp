#include <iostream>
using namespace std;

class SelectionSort {
private:
    int arr[100], n;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void sort() {
        for(int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    void display() {
        cout << "Sorted Array:\n";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    SelectionSort s;

    s.input();
    s.sort();
    s.display();

    return 0;
}