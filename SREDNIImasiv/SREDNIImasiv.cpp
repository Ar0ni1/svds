#include <iostream>
#include <vector>

std::vector<std::vector<double>> vvodMatrici(int stroki, int stolbci) {
    std::vector<std::vector<double>> matrica(stroki, std::vector<double>(stolbci));

    for (int i = 0; i < stroki; ++i) {
        std::cout << "Введите элементы для строки " << i + 1 << ":\n";
        for (int j = 0; j < stolbci; ++j) {
            std::cout << "Элемент " << j + 1 << ": ";
            while (!(std::cin >> matrica[i][j])) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    return matrica;
}
std::vector<double> vichislenie(const std::vector<std::vector<double>>& matrica) {
    std::vector<double> srednee;
    for (const auto& stroki : matrica) {
        double summaStrici = 0;
        for (double element : stroki) {
            summaStrici += element;
        }
        double sredneeStroci = summaStrici / stroki.size();
        srednee.push_back(sredneeStroci);
    }
    return srednee;
}
int main() {
    setlocale(LC_ALL, "RUS");
    int stroki = 3;
    int stolbci = 5;
    auto matrica = vvodMatrici(stroki, stolbci);
    auto sredneeStroci = vichislenie(matrica);
    for (int i = 0; i < sredneeStroci.size(); ++i) {
        std::cout << "Среднее арифметическое для строки " << i + 1 << ": " << sredneeStroci[i] << std::endl;
    }
    return 0;
}
