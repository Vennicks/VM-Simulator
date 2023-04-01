/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Parser
*/

#include "../Includes/Parser.hpp"

Parser::Parser()
{
    _inst_w_value.push_back("push");
    _inst_w_value.push_back("assert");
    _inst_w_value.push_back("load");
    _inst_w_value.push_back("store");
}

Parser::~Parser()
{
}

bool Parser::hasValue(std::string str)
{
    std::string inst = getInst(str);

    for (int i = 0; i < (int)_inst_w_value.size(); i++) {
        if (!inst.compare(_inst_w_value[i])) {
            return true;
        }
    }
    return false;
}

void Parser::checkCom(std::string str)
{
    bool flag = false;
    std::string tmp;

    if (hasValue(str))
        tmp = str.substr(str.find(')') + 1, str.size() - (str.find(')') + 1));
    else
        tmp = str.substr(getInst(str).size(), str.size() - getInst(str).size());
    for (int i = 0; i < (int)tmp.size() && !flag; i++) {
        if (tmp[i] != ';' && tmp[i] != ' ' && tmp[i] != '\t') {
            std::cerr << "Instruction format error." << std::endl;
            std::exit(84);
        }
        else if (tmp[i] == ';')
            flag = true;
    }
}

std::string Parser::getInst(std::string str)
{
    std::string ret;
    int i = 0;

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    while (str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t') {
        ret.push_back(str.c_str()[i]);
        i++;
    }
    return ret;
}

std::string Parser::getType(std::string str)
{
    std::string ret;
    int i = 0;

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    while (str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    while ((str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t' && str.c_str()[i] != '(')) {
        ret.push_back(str.c_str()[i]);
        i++;
    }

    return ret;
}

std::string Parser::getValue(std::string str)
{
    std::string ret;
    int i = 0;

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    while (str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    while ((str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t' && str.c_str()[i] != '('))
        i++;

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    if (str.c_str()[i] == '(')
        i++;

    while (str.c_str()[i] == ' ' || str.c_str()[i] == '\t')
        i++;

    if (str.c_str()[i] == '\0')
        std::exit(84);

    if (str.c_str()[i] == ')')
        std::exit(84);

    while ((str.c_str()[i] != '\0' && str.c_str()[i] != ' ' && str.c_str()[i] != '\t' && str.c_str()[i] != ')')) {
        ret.push_back(str.c_str()[i]);
        i++;
    }
    return ret;
}