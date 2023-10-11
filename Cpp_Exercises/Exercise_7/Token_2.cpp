#include <iostream>
#include <cstring>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main()
{
    char str[500];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;

    std::cout << "Enter a string: ";
    std::cin.getline(str, sizeof(str));

    int wordLength = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == ':' || str[i] == ';' || str[i] == '\0')
        {
            if (wordLength != 0)
            {
                words[wordCount][wordLength] = '\0';
                wordCount++;
                wordLength = 0;
            }
        }
        else
        {
            words[wordCount][wordLength] = str[i];
            wordLength++;
        }
    }

    for (int i = 0; i < wordCount; i++)
    {
        std::cout << words[i] << std::endl;
    }

    return 0;
}
