/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Int32
*/

#include "../../Includes/Types/Int32.hpp"

Int32::Int32(std::string val)
{
    const size_t point = val.find(".");
    if (point != std::string::npos) {
        val = val.substr(0, point);
    }
    OverflowError(val);
    toPrint = val;
}

Int32::~Int32()
{
}

std::string Int32::toString() const
{
    return toPrint;
}

IOperand::eOperandType Int32::getType() const
{
    return IOperand::INT32;
}

void Int32::OverflowError(std::string str) const
{
    if (str[0] != '-') {
        std::string max_val = std::to_string(std::numeric_limits<int32_t>::max());
        if (str.size() > max_val.size()) {
            std::cout << "Error Overflow: value to create new Int32 too high." << std::endl;
            std::exit(84);
        } else if (str.size() < max_val.size())
            return;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] > max_val[i]) {
                std::cout << "Error Overflow: value to create new Int32 too high." << std::endl;
                std::exit(84);
            } else if(str[i] < max_val[i])
                return;
        }
    } else {
        str = str.substr(1, str.size()-1);
        std::string min_val = std::to_string(((long)(std::numeric_limits<int32_t>::min())) * -1);
        if (str.size() > min_val.size()) {
            std::cout << "Error Overflow: value to create new Int32 too low." << std::endl;
            std::exit(84);
        } else if (str.size() < min_val.size())
            return;
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] > min_val[i]) {
                std::cout << "Error Overflow: value to create new Int32 too low." << std::endl;
                std::exit(84);
            } else if(str[i] < min_val[i])
                return;
        }
    }
}

IOperand* Int32::operator+(const IOperand &rhs) const
{
    Int32 tmp(rhs.toString());
    Int32 *result = new Int32(std::to_string(std::stoi(toString()) + std::stoi(tmp.toString())));
    return result;
}

IOperand* Int32::operator-(const IOperand &rhs) const
{
    Int32 tmp(rhs.toString());
    Int32 *result = new Int32(std::to_string(std::stoi(toString()) - std::stoi(tmp.toString())));
    return result;
}

IOperand* Int32::operator*(const IOperand &rhs) const
{
    Int32 tmp(rhs.toString());
    Int32 *result = new Int32(std::to_string(std::stoi(toString()) * std::stoi(tmp.toString())));
    return result;
}

IOperand* Int32::operator/(const IOperand &rhs) const
{
    Int32 tmp(rhs.toString());
    Int32 *result = new Int32(std::to_string(std::stoi(toString()) / std::stoi(tmp.toString())));
    return result;
}

IOperand* Int32::operator%(const IOperand &rhs) const
{
    Int32 tmp(rhs.toString());
    Int32 *result = new Int32(std::to_string(std::stoi(toString()) % std::stoi(tmp.toString())));
    return result;
}