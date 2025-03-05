#include <iostream>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

bool is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

bool is_lowercase(char c)
{
    return (c >= 97 && c <= 122);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    int length = 0;



    for (int j = 1; av[j]; j++)
    {
        length = ft_strlen(av[j]);
        for (int i = 0; i < length; i++)
        {
            if (is_printable(av[j][i]) == true)
            {
                if (is_lowercase(av[j][i]) == true)
                    std::cout << (char)(av[j][i] - 32);
                else
                    std::cout << (char)(av[j][i]);
            }
        }
    }
    std::cout << std::endl;


    return 0;
    
}
