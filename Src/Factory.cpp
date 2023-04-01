/*
** EPITECH PROJECT, 2020
** syn_abstractvm_2019
** File description:
** Factory
*/

#include "../Includes/Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand* Factory::createInt8(const std::string& value)
{
    return (new Int8(value));
}
IOperand* Factory::createInt16(const std::string& value)
{
    return (new Int16(value));
}
IOperand* Factory::createInt32(const  std::string& value)
{
    return (new Int32(value));
}
IOperand* Factory::createFloat(const std::string& value)
{
    return (new Float(value));
}
IOperand* Factory::createDouble(const std::string& value)
{
    return (new Double(value));
}
IOperand* Factory::createBigDecimal(const std::string& value)
{
    return (new BigDecimal(value));
}