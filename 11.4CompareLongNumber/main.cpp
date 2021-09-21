#include <iostream>
#include "string"

bool is_real_number(std::string n_str);
int sign(std::string str);
std::string get_first_part(std::string str, int sign);
std::string get_second_part(std::string str, std::string first_part_str);
int compare(std::string str_1, std::string str_2);
bool equal(std::string str_1, std::string str_2);
bool more(std::string str_1, std::string str_2);
bool less(std::string str_1, std::string str_2);

int main() {
    std::cout << "Comparison of long real numbers.\n";

    std::cout << "Input the first real number: ";
    std::string first_n_str;
    std::cin >> first_n_str;

    std::cout << "Input the second real number: ";
    std::string second_n_str;
    std::cin >> second_n_str;

    if(!is_real_number(first_n_str) || !is_real_number(second_n_str)){
        std::cout << "Incorrect input. The numbers is not real. Try again" << std::endl;
        return 0;
    }

    if (compare(first_n_str, second_n_str) == 0){
        std::cout << "Equal" << std::endl;
    } else if (compare(first_n_str, second_n_str) == 1) {
        std::cout << "More" << std::endl;
    } else {
        std::cout << "Less" << std::endl;
    }

    return 0;
}

bool is_real_number(std::string n_str){
    int dot_count = 0;
    int num_count = 0;

    for(int i = 0; i < n_str.length(); i++){
        if((n_str[i] < '0' || n_str[i] > '9')
           && n_str[i] != '.' && n_str[0]!= '-'){
            return false;
        }

        if (n_str[i] == '.'){
            dot_count++;
            if(dot_count > 1)
                return false;
        }

        if(n_str[i] >= '0' && n_str[i] <= '9') num_count++;
    }

    if(num_count < 1){
        return false;
    }
    return true;
}

int sign(std::string str){
    int sign = 0;
    if(str[0] == '-'){
        return sign = -1;
    }
    return sign;
}

std::string get_first_part(std::string str, int sign){
    std::string first_part;
    int i = 0;
    if(sign < 0){
        i = 1;
    }
    for(int i; str[i] != '.'; i++){
        first_part += str[i];
    }
    first_part.erase(0, first_part.find_first_not_of('0'));// удаляем ведущие нули
    return first_part;
}
std::string get_second_part(std::string str, std::string first_part_str){
    std::string second_part;
    for(int i = first_part_str.length() + 1; i < str.length(); i++ ){
        second_part += str[i];
    }
    while (second_part.length() > 0 && second_part[second_part.length() - 1] == 0) // убираем лишние нули с конца
        second_part.erase(second_part.end() - 1);
    // или так  - second_part = second_part.substr(0, second_part.find_last_not_of('0') + 1);
    return second_part;
}

int compare(std::string str_1, std::string str_2){
    std::string first_part_1 = get_first_part(str_1, sign(str_1));
    std::string first_part_2 = get_first_part(str_2, sign(str_2));
    std::string second_part_1 = get_second_part(str_1, first_part_1);
    std::string second_part_2 = get_second_part(str_2, first_part_2);

    if(sign(str_1) == sign(str_2)) {
        if ((first_part_1 == first_part_2) && (equal(second_part_1, second_part_2))) {
            return 0;
        }
        if ((sign(str_1) == 0) && ((first_part_1 > first_part_2) || (first_part_1 == first_part_2))
            && (more(second_part_1, second_part_2))) {
            return 1;
        }
        if ((sign(str_1) == 0) && ((first_part_1 < first_part_2) || (first_part_1 == first_part_2))
            && (less(second_part_1, second_part_2))) {
            return -1;
        }
        if ((sign(str_1) < 0) && ((first_part_1 < first_part_2) || (first_part_1 == first_part_2))
            && (less(second_part_1, second_part_2))) {
            return 1;
        }
        if ((sign(str_1) < 0) && ((first_part_1 > first_part_2) || (first_part_1 == first_part_2))
            && (more(second_part_1, second_part_2))) {
            return -1;
        }
    } else if(sign(str_1) > sign(str_2)){
        return 1;
    } else {
        return -1;
    }
}

bool equal(std::string str_1, std::string str_2){
    if(sign(str_1) != sign(str_2)){
        return false;
    }
    if(str_1.length() != str_2.length()){
        return false;
    }
    for(int i = 0; i < str_1.length(); i++){
        if (str_1[i]!= str_2[i]){
            return false;
        }
    }
    return true;
}

bool more(std::string str_1, std::string str_2){
    if (str_1.empty() && str_2.empty()){
        return false;
    }
    while(str_1.length() != str_2.length()) {
        if (str_1.length() < str_2.length()) {
            str_1 = str_1.append("0");
        } else {
            str_2 = str_2.append("0");
        }
    }

    for(int i = 0; i < str_1.length(); i++){
        if (str_1[i] < str_2[i]){
            return false;
        }
    }
    return true;
}

bool less(std::string str_1, std::string str_2){
    return !(equal(str_1,str_2) || more(str_1,str_2));
}

