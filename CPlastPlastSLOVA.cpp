// CPlastPlastSLOVA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

std::string reverse(const std::string& word) {
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::string removeVowels(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}

std::string removeConsonants(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                continue;
            }
        }
        result += c;
    }
    return result;
}

std::string shuffle(const std::string& word) {
    std::string slovo = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(slovo.begin(), slovo.end(), g);
    return slovo;
}

int main() {
    std::string word;
    int choice;

    std::cout << "Enter a word: ";//ввести слово с которым нужно будет выполнить действия 
    std::cin >> word;

    std::cout << "Choose an action: \n";
    std::cout << "1. Reverse the word\n";
    std::cout << "2. Remove vowels\n";
    std::cout << "3. Remove consonants\n";
    std::cout << "4. Shuffle the letters\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Reversed word: " << reverse(word) << std::endl;//переворачиваем слово задом наперед 
        break;
    case 2:
        std::cout << "Word without vowels: " << removeVowels(word) << std::endl;//удаляет гласные буквы
        break;
    case 3:
        std::cout << "Word without consonants: " << removeConsonants(word) << std::endl;//удаляет согласные буквы 
        break;
    case 4:
        std::cout << "Shuffled word: " << shuffle(word) << std::endl;//перемешивает буквы в слове
        break;
    default:
        std::cout << "Invalid choice\n";
        break;
    }

    return 0;
}

