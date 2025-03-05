#include <iostream>
#include <fstream>
#include <sstream>


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream ifs(filename.c_str());

    if (!ifs.is_open())
    {
        std::cerr << "Cannot open the file" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string content = buffer.str();


    ifs.close();


    size_t pos = 0;

    pos = content.find(s1, pos);
    while (pos != std::string::npos)
    {
        content.replace(pos, s1.length(), s2);
        pos += s2.length();
        pos = content.find(s1, pos);
    }

    std::string outfile = filename + ".replace";

    std::ofstream   ofs(outfile.c_str());

    ofs << content;
    
    ofs.close();
    

    return (0);

}