#include <iostream>
#include <map>

int main()
{
    std::string user_input;
    int counter_to_show = 1;
    int counter_to_add = 0;
    std::map<std::string, int> dict;

    //START Init dictionary and sort them
    dict.insert(std::make_pair<std::string, int>("Sidorov", 1));
    dict.insert(std::make_pair<std::string, int>("Petrov", 2));
    dict.insert(std::make_pair<std::string, int>("Agafonov", 3));
    dict.insert(std::make_pair<std::string, int>("Laptev", 4));
    for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
    {
        ITR->second = ++counter_to_add;
    }
    counter_to_add = 0;
    //END Init dictionary and sort them

    //Main cicle starts here
    while(user_input != "exit")
    {

        std::cout << "Current list:" << std::endl;
        for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
        {
            std::cout << "<- " << ITR->first << " " << ITR->second << std::endl;
        }

        std::cout << "\nInput Surname or type Next to get next person in the list: ";
        std::cin >> user_input;

        if(user_input == "Next" || user_input == "next")
        {
            //Show next or show from new added person
            for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
            {
                if(counter_to_show == ITR->second)
                {
                    std::cout << "<- " << ITR->first << std::endl << std::endl;
                    counter_to_show++;
                    break;
                }
            }
        }
        else
        {
            //Add new person
            dict.insert(std::pair<std::string, int>(user_input, 0));
            for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
            {
                ITR->second = ++counter_to_add;
            }
            for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
            {
                if(ITR->first == user_input && counter_to_show > ITR->second) counter_to_show = ITR->second;
            }
            counter_to_add = 0;
        }

    }
    //Main cicle ends here
}

