#include <iostream>
#include <map>

int main()
{

    std::map<std::string, std::string> dict;

    dict.insert(std::make_pair<std::string, std::string>("12-34-56", "Ivanov"));
    dict.insert(std::make_pair<std::string, std::string>("98-76-54", "Petrov"));
    dict.insert(std::make_pair<std::string, std::string>("13-57-91", "Sidorov"));
    dict.insert(std::make_pair<std::string, std::string>("15-86-67", "Ivanov"));
    dict.insert(std::make_pair<std::string, std::string>("24-68-10", "Laptev"));

    std::cout << "Type surname or phone number:";
    std::string user_input;
    std::cin >> user_input;

    for( auto ITR = dict.begin(); ITR != dict.end(); ITR++)
    {
        if(user_input == ITR->second) std::cout << ITR->first << std::endl;
        if(user_input == ITR->first) std::cout << ITR->second << std::endl;
    }

    return 0;
}