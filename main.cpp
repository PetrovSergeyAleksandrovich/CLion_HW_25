#include <iostream>
#include <map>

int main()
{
    std::map<int, std::map<int, char> > dict;

    for(int i = 0; i < 127; i++)
        for(int j = 0; j < 127; j++)
            dict[i][j] = (char)j;

    std::cout << dict[99][107];

    return 0;
}

