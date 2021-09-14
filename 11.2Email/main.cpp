#include <iostream>
#include <string>

int dog_count_check(std::string email);
std::string before_dog_email(std::string email);
std::string after_dog_email(std::string email);

int main() {
    std::cout << "11.2 Checking the correctness of the email address.\n";

    std::string sub_str = "!#$%&'*+-/=?^_`{|}~-";

    std::cout << "Enter email adress: " << std::endl;
    std::string email;
    std::getline(std::cin, email);

    if(!dog_count_check(email)){
        return 0;
    }

    std::string first_half = before_dog_email(email);
    std::string last_half = after_dog_email(email);

    if(first_half.length() > 0 && first_half.length() <= 64){
        for( int i = 0; i < first_half.length(); i++){
            int pos = sub_str.find(first_half[i]);
            if((pos >= 0) || (first_half[i] == '.')
               || (first_half[i] >= 'a' && first_half[i] <= 'z')
               || (first_half[i] >= 'A' && first_half[i] <= 'Z')
               || (first_half[i] >= '0' && first_half[i] <= '9')){
                if(first_half[i] == '.'){
                    if((i == 0) || (i == first_half.length() - 1)){
                        std::cout << "No. Point cannot be the first or last character in the first part." << std::endl;
                        return 0;
                    }
                    if(first_half[i + 1] == '.'){
                        std::cout << "No. Two dots cannot go in a row in the first part." << std::endl;
                        return 0;
                    }
                }
            } else {
                std::cout << "No. Invalid characters are present." << std::endl;
                return 0;
            }
        }
    } else {
        std::cout << "No. The first part is longer than 64 characters." << std::endl;
        return 0;
    }

    if(last_half.length() > 0 && last_half.length() < 64){
        for( int i = 0; i < last_half.length(); i++){
            if((last_half[i] == '-') || (last_half[i] == '.')
               || (last_half[i] >= 'a' && last_half[i] <= 'z')
               || (last_half[i] >= 'A' && last_half[i] <= 'Z')
               || (last_half[i] >= '0' && last_half[i] <= '9')){
                if(last_half[i] == '.'){
                    if((i == 0) || (i == last_half.length() - 1)){
                        std::cout << "No. Point cannot be the first or last character in the second part." << std::endl;
                        return 0;
                    }
                    if(last_half[i + 1] == '.'){
                        std::cout << "No. Two dots cannot go in a row in the second part." << std::endl;
                        return 0;
                    }
                }
            } else {
                std::cout << "No. The second part contains an invalid symbol " << last_half[i] << "." << std::endl;
                return 0;
            }
        }
    } else {
        std::cout << "No. The second part is longer than 63 characters." << std::endl;
        return 0;
    }

    std::cout << "Yes!" << std::endl;
}

int dog_count_check(std::string email) {
    int dog_count = 0;

    for(int i = 0; i < email.length(); i++ ){
        if (email[i] == '@'){
            dog_count++;
        }
        if(dog_count > 1){
            std::cout << "No. There must be only one @ symbol." << std::endl;
            return 0;
        }
    }
    if (dog_count == 0){
        std::cout << "No. No symbol @." << std::endl;
        return 0;
    } else {
        return 1;
    }
}

std::string before_dog_email(std::string email){
    std::string before_dog_email = "";

    for(int i = 0; email[i] != '@'; i++){
        before_dog_email += email[i];
    }
    return before_dog_email;
}

std::string after_dog_email(std::string email){
    std::string after_dog_email = "";
    int dog = 0;
    for(int i = 0; email[i] != '@'; i++){
        dog = i + 1;
    }
    for(int i = dog + 1; i < email.length(); i++ ){
        after_dog_email += email[i];
    }
    return after_dog_email;
}


