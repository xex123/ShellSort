#include <iostream>
#include <locale>
#define N 5

int data[N];

void Input() {
	setlocale(LC_ALL, "Rus");
	std::cout << "Введите элементы массива: \n";
	for (int i = 0; i < N; i++) {
		std::cin >> data[i];
	}
}

void ShellSort(int data[], int size) {
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
	Input();
	int size = sizeof(data) / sizeof(data[0]);
	ShellSort(data, size);
	std::cout << "Отсортированный массив: \n";
	for (int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << "\n";
}
