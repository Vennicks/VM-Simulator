/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Float
*/

#include "../../Includes/Types/Float.hpp"

Float::Float(std::string val)
{
    OverflowError(val);
    toPrint = val;
}

Float::~Float()
{
}

std::string Float::toString() const
{
    if (toPrint.find('.') != std::string::npos) {
        std::string ret = toPrint;
        int i = ret.size() - 1;
        while (ret[i] == '0') {
            ret.erase(i);
            i--;
        }
        if (ret[i] != '.')
            i++;
        ret.erase(i);

        return ret;
    } else
        return toPrint;
}

IOperand::eOperandType Float::getType() const
{
    return IOperand::FLOAT;
}

void Float::OverflowError(std::string str) const
{
    bool isdec = false;
    std::string integer;
    std::string decimal;
    const size_t point = str.find(".");

    if (point != std::string::npos) {
        isdec = true;
        integer = str.substr(0, point - 1);
        decimal = str.substr(point + 1, str.length() - (point + 1));
    } else
        integer = str;

    if (str[0] != '-') {
        std::string max_val = std::to_string(std::numeric_limits<float>::max());
        if (integer.size() > max_val.size()) {
            std::cout << "Error Overflow: value to create new float too high." << std::endl;
            std::exit(84);
        } else if (integer.size() < max_val.size())
            return;
        for (int i = 0; integer[i] != '\0'; i++)
        {
            if (str[i] > max_val[i]) {
                std::cout << "Error Overflow: value to create new float too high." << std::endl;
                std::exit(84);
            } else if(integer[i] < max_val[i])
                return;
        } if (isdec) {
            for (int i = 0; decimal[i] != '\0'; i++) {
                if (decimal[i] != '0') {
                    std::cout << "Error Overflow: value to create new float too high." << std::endl;
                    std::exit(84);
                }
            }
        }
    } else {
        str = str.substr(1, str.size()-1);
        std::string min_val = std::to_string(std::numeric_limits<float>::min()* -1);
        if (integer.size() > min_val.size()) {
            std::cout << "Error Overflow: value to create new float too low." << std::endl;
            std::exit(84);
        } else if (integer.size() < min_val.size())
            return;
        for (int i = 0; integer[i] != '\0'; i++)
        {
            if (str[i] > min_val[i]) {
                std::cout << "Error Overflow: value to create new float too low." << std::endl;
                std::exit(84);
            } else if(integer[i] < min_val[i])
                return;
        } if (isdec) {
            for (int i = 0; decimal[i] != '\0'; i++) {
                if (decimal[i] != '0') {
                    std::cout << "Error Overflow: value to create new float too low." << std::endl;
                    std::exit(84);
                }
            }
        }
    }
}

IOperand* Float::operator+(const IOperand &rhs) const
{
    Float tmp(rhs.toString());
    Float *result = new Float(std::to_string(std::stof(toString()) + std::stof(tmp.toString())));
    return result;
}

IOperand* Float::operator-(const IOperand &rhs) const
{
    Float tmp(rhs.toString());
    Float *result = new Float(std::to_string(std::stof(toString()) - std::stof(tmp.toString())));
    return result;

}

IOperand* Float::operator*(const IOperand &rhs) const
{
    Float tmp(rhs.toString());
    Float *result = new Float(std::to_string(std::stof(toString()) * std::stof(tmp.toString())));
    return result;
}

IOperand* Float::operator/(const IOperand &rhs) const
{
    Float tmp(rhs.toString());
    Float *result = new Float(std::to_string(std::stof(toString()) / std::stof(tmp.toString())));
    return result;
}

IOperand* Float::operator%(const IOperand &rhs) const
{
    return (new Float(std::to_string(fmod(std::stof(toString()), std::stof(rhs.toString())))));
}