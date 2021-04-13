#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::string user_input;
    int x = 0;
    std::map<std::string, int> dict_number;
    std::map<int, std::string> dict_name;

    dict_number.insert(std::pair<std::string, int>("11-34-56", 1));
    dict_number.insert(std::pair<std::string, int>("98-76-54", 2));
    dict_number.insert(std::pair<std::string, int>("13-57-91", 3));
    dict_number.insert(std::pair<std::string, int>("15-86-67", 4));
    dict_number.insert(std::pair<std::string, int>("12-68-10", 5));
    dict_number.insert(std::pair<std::string, int>("24-45-10", 6));
    dict_number.insert(std::pair<std::string, int>("34-68-10", 7));
    dict_number.insert(std::pair<std::string, int>("10-61-01", 8));
    dict_number.insert(std::pair<std::string, int>("99-61-21", 9));
    dict_number.insert(std::pair<std::string, int>("46-85-01", 10));
    dict_number.insert(std::pair<std::string, int>("55-91-01", 11));

    dict_name.insert(std::pair<int, std::string>(1, "Ivanov"));
    dict_name.insert(std::pair<int, std::string>(2, "Petrov"));
    dict_name.insert(std::pair<int, std::string>(3, "Sidorov"));
    dict_name.insert(std::pair<int, std::string>(4, "Ivanov"));
    dict_name.insert(std::pair<int, std::string>(5, "Laptev"));
    dict_name.insert(std::pair<int, std::string>(6, "Bobrov"));
    dict_name.insert(std::pair<int, std::string>(7, "Morozov"));
    dict_name.insert(std::pair<int, std::string>(8, "Agafonov"));
    dict_name.insert(std::pair<int, std::string>(9, "Korolev"));
    dict_name.insert(std::pair<int, std::string>(10, "Bobrov"));
    dict_name.insert(std::pair<int, std::string>(11, "Kolosov"));

    //Init variables & iterators for searching operations
    std::map<std::string, int>::iterator itr_b = dict_number.begin();
    std::map<std::string, int>::iterator itr_e = dict_number.end();
    std::map<std::string, int>::iterator itr_finder = dict_number.begin();
    x = dict_number.size();

    //show the dictionary
    for(std::map<std::string, int>::iterator itr = itr_b; itr != itr_e; itr++)
    {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
    std::cout << "map size: " << x << std::endl;

    //User input
    std::cout << "Type surname or phone number:";
    std::cin >> user_input;

    //sets what to check. check name by number as default
    bool flag = true;
    for(int i = 0; i < user_input.size(); i++)
    {
        if((user_input[i] >= 'A' && user_input[i] <='Z') || (user_input[i] >= 'a' && user_input[i] <='z'))
        {
            flag = false;
            break;
        }
    }

    //IF SEARCH by NUMBER
    if(flag)
    {
        std::vector<std::string> number_key_v = {};
        std::vector<int> number_value_v = {};
        for(std::map<std::string, int>::iterator itr = dict_number.begin(); itr != dict_number.end(); itr++)
        {
            number_key_v.push_back(itr->first);
            number_value_v.push_back(itr->second);
        }

        //binary search variables
        int mid = number_value_v.size()/2;
        int tmp_up = 0;
        int tmp_down = number_value_v.size();

        //binary search
        for(int i = 0;;)
        {
            std::cout << "\ncicle: " << ++i << std::endl;

            //condition to exit
            if(mid == tmp_up)
            {
                std::cout << "no number in the list" << std::endl;
                break;
            }

            //checks
            if(number_key_v[mid] == user_input)
            {
                std::cout << dict_name[number_value_v[mid]] << std::endl;
                break;
            }
            if(user_input > number_key_v[mid])
            {
                tmp_up = mid;
                mid = (mid+tmp_down)/2;
                continue;
            }
            if(user_input < number_key_v[mid])
            {
                tmp_down = mid;
                mid = (mid + tmp_up)/2;
                continue;
            }
        }
    }

    //IF SEARCH by NAME
    else if (!flag)
    {
        //creates vector with associated numbers for similar or single names
        std::vector<int> names_v = {};
        for(std::map<int, std::string>::iterator itr = dict_name.begin(); itr != dict_name.end(); itr++)
        {
            if(itr->second == user_input)
            {
                names_v.push_back(itr->first);
            }
        }

        //check associated number in vector with dictionary
        for(int i = 0; i < names_v.size(); i++)
        {
            for(std::map<std::string, int>::iterator itr = dict_number.begin(); itr != dict_number.end(); itr++)
            {
                if(itr->second == names_v[i]) std::cout << dict_name[names_v[i]] << " " << itr->first << std::endl;
            }
        }
    }

    return 0;
}