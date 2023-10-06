#include <iostream>
#include <fstream>
#include <string.h>

std::string replaceline(std::string line, std::string s1, std::string s2)
{
    std::string result;
    int i = 0;
    while (line[i])
    {
        int j = 0;
        while (line[i + j] && s1[j])
        {
            if (line[i + j] != s1[j])
                break ;
            j++;
        }
        if (s1[0] != 0 && s1[j] == '\0')
        {
            result = result + s2;
            i += s1.length();
        }
        else
        {
            result.push_back(line[i]);
        }
        i++;
    }
    return (result);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "invalid args" << std::endl;
        return (0);
    }
    std::string s1;
    std::string s2;

    s1.assign(av[2], strlen(av[2]));
    s2.assign(av[3], strlen(av[3]));
    if (s1.length() == 0 || s2.length() == 0 || strlen(av[1]) == 0)
    {
        std::cout << "args cannot be empty" << std::endl;
        return (0);
    }
    std::fstream file;
    file.open(av[1], std::fstream::in | std::fstream::out);
    if (!file.is_open())
    {
        std::cout << "error while opening first file" << std::endl;
        return (1);
    }
    std::string line;
    std::string buffer;
    while(std::getline(file, buffer))
    {
        line.append(buffer);
    }
    std::ofstream outfile;
    std::string outfilename = av[1];
    outfilename.append(".replace");
    outfile.open(outfilename.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!outfile.is_open())
    {
        file.close();
        std::cout << "error while opening 2nd file" << std::endl;
        return (1);
    }
    outfile << replaceline(line, s1, s2);
    file.close();
    outfile.close();
    return (0);
}