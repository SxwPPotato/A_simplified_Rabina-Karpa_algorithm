#include <iostream>
#include <string>

int hashstr(std::string str, int size) {
    int hash = 0;
    for (int i = 0; i < size; ++i) {
        hash += static_cast<int> (str[i]);
    }
    return hash;
}


int find_substring_light_rabin_karp(std::string str, std::string substr) {
    
    int size = substr.size();
    int h = 0;;
    int hashsubstr = hashstr(substr, size);
    for (int i = 0; i <= str.size() - size + 1 ; ++i) {
        int index = 0;
        if (i == 0) {
           h = hashstr(str, size);
        }
        else {
            h -= static_cast<int> (str[i - 1]);
            h += static_cast<int> (str[i + size - 1]);
        }
        if (h != hashsubstr) {
            index = -1;
        }
        else {
            for (int j = 0; j < size; ++j) {
                if (str[i + j] != substr[j]) {
                   index = -1;
                }
               
            }
            if (index != -1)
                return i;
            else return -1;

        }
        

    }
    return -1;

}

int main()
{
    setlocale(LC_ALL, "russian");
    std::string str = "hellohellomydearfriend";
    std::string substr;
    /*std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> str;*/
   
    do {
        std::cout << "\nВведите подстроку, которую нужно найти: ";
        std::cin >> substr;
       int index = find_substring_light_rabin_karp(str, substr);
       if (index != -1) {
           std::cout << "Подстрока " << substr << " найдена по индексу " << index;
       }
      else std::cout << "Подстрока " << substr << " не найдена ";
    } while (substr != "exit");
    return 0;
}
