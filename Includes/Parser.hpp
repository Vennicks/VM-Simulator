/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <iostream>
#include <vector>

class Parser {
    public:
        Parser();
        ~Parser();

        void checkCom(std::string str);
        bool hasValue(std::string str);
        std::string getInst(std::string str);
        std::string getType(std::string str);
        std::string getValue(std::string str);
        std::vector<std::string> _inst_w_value;
        
    protected:
    private:
};

#endif /* !PARSER_HPP_ */
