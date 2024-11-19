#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Функція для підрахунку пар сусідніх букв в рядку
int countPairs(const string& line) {
    int count = 0;
    for (int i = 0; i < line.length() - 1; ++i) {
        if ((line[i] == 'a' && line[i + 1] == 'a') ||
            (line[i] == 'b' && line[i + 1] == 'b') ||
            (line[i] == 'c' && line[i + 1] == 'c')) {
            count++;
        }
    }
    return count;
}

// Функція для підрахунку пар у всьому файлі
int countPairsInFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу: " << filename << endl;
        return -1;
    }

    int total_count = 0;
    string line;
    while (getline(file, line)) {
        total_count += countPairs(line);
    }

    file.close();
    return total_count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "C:\\Users\\Dara\\Desktop\\t.txt";
    int result = countPairsInFile(filename);

    if (result != -1) {
        cout << "Кількість пар сусідніх букв aa, bb, cc: " << result << endl;
    }

    return 0;
}
