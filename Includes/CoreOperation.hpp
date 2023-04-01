/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** CoreOperation
*/

#ifndef COREOPERATION_HPP_
#define COREOPERATION_HPP_

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <map>
#include <vector>
#include <stack>

#include "Factory.hpp"
#include "Parser.hpp"

#define NAMENOFILE "temp.asm"

class CoreOperation {
    public:
        CoreOperation();
        ~CoreOperation();

        Parser parser;

        void witheFile(std::string File);
        void checkValues(std::string value);
        void noFile();

        std::stack<IOperand *> _operands;
        std::vector<std::string> parseLine(std::string line);
        std::map<std::string, void (CoreOperation::*)(std::vector<std::string>)> _map;
        std::map<std::string, IOperand::eOperandType> _type_creation;
        std::vector<IOperand*> _storage;
        std::string checkFormat(IOperand *op);

        void Error(std::string typeError, std::string str);
        void add (std::vector<std::string>);
        void mul (std::vector<std::string>);
        void push (std::vector<std::string>);
        void pop (std::vector<std::string>);
        void dump (std::vector<std::string>);
        void clear (std::vector<std::string>);
        void dup (std::vector<std::string>);
        void swap (std::vector<std::string>);
        void assert (std::vector<std::string>);
        void sub (std::vector<std::string>);
        void load (std::vector<std::string>);
        void store (std::vector<std::string>);
        void print (std::vector<std::string>);
        void div (std::vector<std::string>);
        void mod (std::vector<std::string>);
        void exit (std::vector<std::string>);

    protected:
    private:
        int _line;
};

#endif /* !COREOPERATION_HPP_ */
