#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string parent_word, child_word;
    std::map<int, char> parent, child;

    std::cout << "Input first word:";
    std::cin >> parent_word;
    std::cout << "Input second word:";
    std::cin >> child_word;

    //Create dictionaries
    for(int i = 0; i < parent_word.length(); i++)
    {
        parent.insert(std::pair<int, char> (i, parent_word[i]));
    }
    for(int i = 0; i < child_word.length(); i++)
    {
        child.insert(std::pair<int, char> (i, child_word[i]));
    }
    //Dictionaries created

    //Check length comparison
    if(parent_word.length() != child_word.length())
    {
        std::cout << "false_1 / lengths not equal";
        return 0;
    }
    //Checked length comparison

    //Check dictionaries for anagrama
    for(int i = 0; i < parent_word.length(); i++)
    {
        for(int j = 0; j < child_word.length(); j++)
        {
            if(parent[i] == child[j])
            {
                child[j] = '*';
                break;
            }
            if(j == child_word.length()-1)
            {
                std::cout << "false_2 / no char at child: " << parent[i];
                return 0;
            }
        }
    }
    //Checked dictionaries for anagrama

    //If all checks passed prints:
    std::cout << "true" ;

    return 0;
}
