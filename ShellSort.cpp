#include <iostream>
#include <vector>
#include <locale>

void Input(std::vector<int>& data) {
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите элементы массива (нажмите Enter когда закончите):\n";

    int element;
    while (std::cin >> element) {
        data.push_back(element);

        if (std::cin.peek() == '\n') {
            std::cin.ignore();
            break;
        }
    }
}

void ShellSort(std::vector<int>& data) {
    int size = data.size();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            int temp = data[i];
            int j;
            for (j = i; j >= interval && data[j - interval] > temp; j -= interval) {
                data[j] = data[j - interval];
            }
            data[j] = temp;
        }
    }
}

int main() {
    std::vector<int> data;

    Input(data);
    ShellSort(data);

    std::cout << "Отсортированный массив:\n";
    for (const int& num : data) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}