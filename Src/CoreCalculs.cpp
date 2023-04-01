/*
** EPITECH PROJECT, 2020
** syn_abstractvm_2019
** File description:
** CoreCalculs
*/

#include "../Includes/CoreOperation.hpp"

void CoreOperation::add(std::vector<std::string> vec)
{
    (void)vec;
    IOperand *result;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand *first = _operands.top();
    _operands.pop();
    IOperand *second = _operands.top();
    _operands.pop();

    if (first->getType() > second->getType())
        result = *Factory::createOperand(first->getType(), second->toString()) + *first;
    else if (first->getType() < second->getType())
        result = *second + *Factory::createOperand(second->getType(), first->toString());
    else
        result = *second + *first;
    _operands.push(result);
}

void CoreOperation::mul(std::vector<std::string> vec)
{
     (void)vec;
    IOperand *result;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand *first = _operands.top();
    _operands.pop();
    IOperand *second = _operands.top();
    _operands.pop();

    if (first->getType() > second->getType())
        result = *Factory::createOperand(first->getType(), second->toString()) * *first;
    else if (first->getType() < second->getType())
        result = *second * *Factory::createOperand(second->getType(), first->toString());
    else
        result = *second * *first;
    _operands.push(result);
}

void CoreOperation::div(std::vector<std::string> vec)
{
    (void)vec;
    IOperand *result;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand *first = _operands.top();
    _operands.pop();
    IOperand *second = _operands.top();
    _operands.pop();

    if (std::stoi(first->toString()) == 0)
        Error("Error Operation", "Division by 0.");
    if (first->getType() > second->getType())
        result = *Factory::createOperand(first->getType(), second->toString()) / *first;
    else if (first->getType() < second->getType())
        result = *second / *Factory::createOperand(second->getType(), first->toString());
    else
        result = *second / *first;
    _operands.push(result);
}

void CoreOperation::mod(std::vector<std::string> vec)
{
    (void)vec;
    IOperand *result;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand *first = _operands.top();
    _operands.pop();
    IOperand *second = _operands.top();
    _operands.pop();

    if (first->toString() == "0")
        Error("Error Operation", "Division by 0.");
    if (first->getType() > second->getType())
        result = *Factory::createOperand(first->getType(), second->toString()) % *first;
    else if (first->getType() < second->getType())
        result = *second % *Factory::createOperand(second->getType(), first->toString());
    else
        result = *second % *first;
    _operands.push(result);
}

void CoreOperation::push(std::vector<std::string> vec)
{
    checkValues(vec.at(2));
    if (_type_creation.find(vec.at(1)) == _type_creation.end())
        Error("Error Syntax", "Wrong Type");
    else
        _operands.push(Factory::createOperand(_type_creation[vec.at(1)], vec.at(2)));
}

void CoreOperation::pop(std::vector<std::string> vec)
{
    (void)vec;
    if (!_operands.empty())
        _operands.pop();
    else
        Error("Error Stack", "Pop on empty stack"); // stack empty
}

void CoreOperation::dump(std::vector<std::string> vec)
{
    (void)vec;

    std::stack<IOperand *> tmp = _operands;

    while (!tmp.empty()) {
        std::cout << checkFormat(tmp.top()) << std::endl;
        tmp.pop();
    }
}

void CoreOperation::clear(std::vector<std::string> vec)
{
    (void)vec;

    while (!_operands.empty())
        _operands.pop();
}

void CoreOperation::dup(std::vector<std::string> vec)
{
    (void)vec;

    if (!_operands.empty())
        _operands.push(_operands.top());
    else
        Error("Error Operation", "Operation's stack is empty.");
}

void CoreOperation::swap(std::vector<std::string> vec)
{
    (void)vec;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand* first = _operands.top();
    _operands.pop();
    IOperand* sec = _operands.top();
    _operands.pop();

    _operands.push(first);
    _operands.push(sec);
}

void CoreOperation::assert(std::vector<std::string> vec)
{
    if (_operands.size() < 1)
        Error("Error Operation", "Operation's stack is empty.");
    if (_operands.top()->getType() != _type_creation[vec.at(1)] && _operands.top()->toString() != vec.at(2))
        Error("Error Assert", "the value and the type given as parameter isn't the same than the one in the stack.");
    if (_operands.top()->getType() != _type_creation[vec.at(1)])
        Error("Error Assert", "type of the value given as parameter isn't the same than the one in the stack.");
    if (_operands.top()->toString() != vec.at(2))
        Error("Error Assert", "the value given as parameter isn't the same than the one in the stack.");
}

void CoreOperation::sub(std::vector<std::string> vec)
{
    (void)vec;
    IOperand *result;

    if (_operands.size() < 2)
        Error("Error Operation", "Operation with less than 2 operands.");

    IOperand *first = _operands.top();
    _operands.pop();
    IOperand *second = _operands.top();
    _operands.pop();

    if (first->getType() > second->getType())
        result = *Factory::createOperand(first->getType(), second->toString()) - *first;
    else if (first->getType() < second->getType())
        result = *second - *Factory::createOperand(second->getType(), first->toString());
    else
        result = *second - *first;
    _operands.push(result);
}

void CoreOperation::load(std::vector<std::string> vec)
{
    if (std::stoi(vec[2]) < 0 || std::stoi(vec[2]) > 15)
        Error("Error Operands", "Invalid storage number [0-15]");
    if (!_storage.at(std::stoi(vec.at(2))))
        Error("Error Operands", "Loading an empty register");

    _operands.push(_storage.at(std::stoi(vec.at(2))));
    _storage.at(std::stoi(vec.at(2))) = nullptr;
}

void CoreOperation::store(std::vector<std::string> vec)
{
    if (_operands.empty())
        Error("Error Operation", "Operation's stack is empty.");
    if (std::stoi(vec[2]) < 0 || std::stoi(vec[2]) > 15)
        Error("Error Storage", "Invalid storage number [0-15]");
    if (_storage[std::stoi(vec.at(2))] != nullptr)
        Error("Error Storage", "This stack is already full");

    _storage[std::stoi(vec.at(2))] = (_operands.top());
    _operands.pop();
}

void CoreOperation::print(std::vector<std::string> vec)
{
    char print;
    (void)vec;
    if (_operands.empty()) {
        Error("Error Operation", "Operation's stack is empty.");
    }
    if (_operands.top()->getType() == IOperand::INT8) {
        print = std::stoi(_operands.top()->toString());
        std::cout << print << std::endl;
    } else
        Error("Error Operation", "Opration's type isn't int8 for print.");
}

void CoreOperation::exit(std::vector<std::string> vec)
{
    (void)vec;
    std::exit(0);
}