#include <iostream>
#include <map>

int main()
{
    std::string user_input;
    int counter_surname = 1;
    std::map<std::string, int> dict;
    std::map<std::string, int>::iterator ITR_g;

    //START Init dictionary
    dict.insert(std::make_pair<std::string, int>("Sidorov", 1));
    dict.insert(std::make_pair<std::string, int>("Petrov", 1));
    dict.insert(std::make_pair<std::string, int>("Agafonov", 1));
    dict.insert(std::make_pair<std::string, int>("Laptev", 2));
    ITR_g = dict.begin();
    //ENDS Init dictionary and sort them

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
                if(ITR == ITR_g && counter_surname <= ITR->second)
                {
                    std::cout << "<- " << ITR->first << " " << counter_surname << std::endl << std::endl;
                    if(ITR->second > counter_surname)
                    {
                        ITR_g = ITR;
                        counter_surname++;
                    }
                    else
                    {
                        ITR_g++;
                        counter_surname = 1;
                    }
                    break;
                }
            }

        }
        else
        {
            bool flag = false;
            std::map<std::string, int>::iterator ITR_l;
            //Add new person
            for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
            {
                //if exists - add quantity
                if(user_input == ITR->first)
                {
                    flag = true;
                    ITR_l = ITR;
                    break;
                }
            }

            if(flag)
            {
                ITR_l->second++;
                counter_surname = ITR_l->second;
                if(user_input == ITR_l->first && ITR_g->first > ITR_l->first)
                {
                    ITR_g = ITR_l;
                }
            }

            if(!flag)
            {
                //if new person - add
                dict.insert(std::pair<std::string, int>(user_input, 1));
                //Switch iterator to added Surname
                for(std::map<std::string, int>::iterator ITR = dict.begin(); ITR != dict.end(); ITR++)
                {
                    if(user_input == ITR->first && ITR_g->first > ITR->first)
                    {
                        ITR_g = ITR;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

