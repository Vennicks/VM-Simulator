/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** CoreOperation
*/

#include "../Includes/CoreOperation.hpp"

CoreOperation::CoreOperation()
{
    _line = 0;
    this->_map["add"] = &CoreOperation::add;
    this->_map["mul"] = &CoreOperation::mul;
    this->_map["div"] = &CoreOperation::div;
    this->_map["mod"] = &CoreOperation::mod;
    this->_map["push"] = &CoreOperation::push;
    this->_map["pop"] = &CoreOperation::pop;
    this->_map["dump"] = &CoreOperation::dump;
    this->_map["clear"] = &CoreOperation::clear;
    this->_map["dup"] = &CoreOperation::dup;
    this->_map["swap"] = &CoreOperation::swap;
    this->_map["assert"] = &CoreOperation::assert;
    this->_map["sub"] = &CoreOperation::sub;
    this->_map["load"] = &CoreOperation::load;
    this->_map["store"] = &CoreOperation::store;
    this->_map["print"] = &CoreOperation::print;
    this->_map["exit"] = &CoreOperation::exit;
    this->_type_creation["int8"] = IOperand::INT8;
    this->_type_creation["int16"] = IOperand::INT16;
    this->_type_creation["int32"] = IOperand::INT32;
    this->_type_creation["float"] = IOperand::FLOAT;
    this->_type_creation["double"] = IOperand::DOUBLE;
    this->_type_creation["bigdecimal"] = IOperand::BIGDECIMAL;

    for (int i = 0; i < 16; i++)
        _storage.push_back(nullptr);
}

CoreOperation::~CoreOperation()
{
}

std::vector<std::string> CoreOperation::parseLine(std::string line)
{
    std::vector<std::string> parsedLine;
    parsedLine.push_back(parser.getInst(line));
    if (parser.hasValue(line)) {
        parsedLine.push_back(parser.getType(line));
        parsedLine.push_back(parser.getValue(line));
    }

    return parsedLine;
}

void CoreOperation::Error(std::string typeError, std::string str)
{
    typeError.append(" L. ");
    typeError.append(std::to_string(_line));
    typeError.append(": ");
    typeError.append(str);

    std::cerr << typeError << std::endl;
    std::exit(84);
}

void CoreOperation::checkValues(std::string value)
{
    for (size_t i = 0; i < value.size() ; i++) {
        if (value.at(i) != '-' && !std::isdigit(value.at(i)) && value.at(i) != '.' && value.at(i) != ' ' && value.at(i) != '\t')
            Error("Value Erreur", "invalid Value format");
    }
}

void CoreOperation::witheFile(std::string File)
{
    std::vector<std::string> line;
    std::string operation;
    std::ifstream file(File, std::ios_base::in);

    while (getline(file, operation)) {
        _line++;
        if (operation[0] != ';') {
            line = parseLine(operation);
            if(_map.find(line.front()) == this->_map.end())
                Error("Error syntax", "Command not found");
            else
                ((this)->*(this->_map[line.front()]))(line);
            line.clear();
        }
    }
    Error("Exit Error", "program has no error exit.");
}

void CoreOperation::noFile()
{
    std::string input;
    std::ofstream ofs;
    ofs.open (NAMENOFILE, std::ofstream::out | std::ofstream::app);
    while (input.compare(";;") != 0) {
        getline(std::cin, input);
        ofs << input;
        ofs << "\n";
    }
    ofs.close();
}

std::string CoreOperation::checkFormat(IOperand *op)
{
    switch (op->getType()) {
        case (IOperand::FLOAT) :
            if (op->toString().find('.') != std::string::npos && op->toString().find('.') + 1 + 7 < op->toString().size())
                return (op->toString().substr(0, op->toString().find('.') + 1 + 7));
            return op->toString();
        case (IOperand::DOUBLE) :
            if (op->toString().find('.') != std::string::npos && op->toString().find('.') + 1 + 15 < op->toString().size()) {
                return op->toString().substr(0, op->toString().find('.') + 1 + 15);
            }
            return op->toString();
        case (IOperand::BIGDECIMAL) :
            if (op->toString().find('.') != std::string::npos && op->toString().find('.') + 1 + 200 < op->toString().size())
                return op->toString().substr(0, op->toString().find('.') + 1 + 200);
            return op->toString();
        default :
            return (op->toString());
    }
}