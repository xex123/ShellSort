#include <iostream>
#include <vector>
#include <locale>

void ShellSort(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");

    std::cout << "Введите элементы массива (нажмите Enter когда закончите):\n";
    int element;
    while (true) {
        if (std::cin >> element) {
            data.push_back(element);
        }
        else {
            std::cin.clear();
            std::cin.ignore();
        }
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
            break;
        }
    }

    int size = data.size();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i++) {
            int temp = data[i];
            int j;
            for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
                data[j] = data[j - interval];
            }
            data[j] = temp;
        }
    }
    std::cout << "\nОтсортированный массив:\n";

    for (int& num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data;

    ShellSort(data);

    return 0;
}