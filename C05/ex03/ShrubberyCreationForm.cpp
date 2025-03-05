#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src), target(src.target)
{
    std::cout << "ShrubberyCreationForm has been copied" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        this->target = src.target;
    }
    std::cout << "ShrubberyCreationForm has been assigned" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);
    std::ofstream file((target + "_shrubbery").c_str());

    file << "              _{\\ _{\\{\\/}/}/}__\n"
         << "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
         << "            {/{/\\}{/{/\\}(_)/}{/{/\\}  _\n"
         << "         {\\{/(/}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
         << "        {/{/(_)/}{\\{/)/}{\\(_){/}/}/}/}\n"
         << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
         << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
         << "      _{\\{/{\\{/(_)/}/}{/{/{/\\}\\})\\}{/\\}\n"
         << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
         << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
         << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
         << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{(/}/}\\}/}\n"
         << "       {/{\\{\\/}(_){\\{\\{(/}/}{\\(_)/}/}\\}\n"
         << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
         << "          (_){/{\\/}{\\{\\/}/}{\\{)/}/}(_)\n"
         << "            {/{/{\\{\\/}{/{\\{\\(_)/}\n"
         << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
         << "              {){/ {\\/}{\\/} \\}\\}\n"
         << "              (_)  \\.-'.-/\n"
         << "          __...--- |'-.-'| --...__\n"
         << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
         << " -\"    ' .  . '    |.'-._| '  . .  '   .._\n"
         << " .  '-  '    .--'  | '-.'|    .  '  . '\n"
         << "          ' ..     |'-_.-|\n"
         << "  .  '  .       _.-|-._ -|-._  .  '  .\n"
         << "              .'   |'- .-|   '.\n"
         << "  ..-'   ' .  '.   `-._.-'   .'  '  - .\n"
         << "   .-' '        '-._______.-'     '  .\n"
         << "        .      ~,\n"
         << "    .       .   |\\   .    ' '-.\n";

    file.close();
}