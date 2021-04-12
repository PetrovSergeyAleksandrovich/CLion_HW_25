#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string parent_word, child_word;
    std::map<int, char> parent, child;
    int counter_g = 0;
    int word_size = 0;

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
        std::cout << "false_1";
        return 0;
    }
    else word_size = parent_word.length();
    //Checked length comparison

    //Check dictionaries for anagrama
    for(int i = 0; i < parent_word.length(); i++)
    {
        for(int j = 0; j < child_word.length(); j++)
        {
            if(parent[i] == child[j])
            {
                child[j] = '*';
                counter_g++;
                break;
            }
            if(j == child_word.length()-1)
            {
                std::cout << "false_2";
                return 0;
            }
        }
    }
    //Checked dictionaries for anagrama

    counter_g == word_size ? std::cout << "anagrama true" : std::cout << "anagrama false";

    return 0;
}
