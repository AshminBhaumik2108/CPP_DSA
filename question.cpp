#include <iostream>
#include <vector>

void merge(std::vector<char>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<char> leftArray(n1);
    std::vector<char> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<char>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<char> characters(n);

    for (int i = 0; i < n; i++) {
        std::cin >> characters[i];
    }

    mergeSort(characters, 0, n - 1);

    std::cout << "Sorted Characters: ";
    for (int i = 0; i < n; i++) {
        std::cout << characters[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
