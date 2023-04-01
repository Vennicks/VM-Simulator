/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_
#include <string>
#include <iostream>

#include <limits>
#include <iomanip>
#include <math.h>

class IOperand
{
    public:
        enum eOperandType {
            INT8,
            INT16,
            INT32,
            FLOAT,
            DOUBLE,
            BIGDECIMAL
        };
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual void OverflowError(std::string) const = 0;
        virtual IOperand* operator+(const IOperand &rhs) const = 0; //  sum
        virtual IOperand* operator-(const IOperand &rhs) const = 0; //  difference
        virtual IOperand* operator*(const IOperand &rhs) const = 0; //  product
        virtual IOperand* operator/(const IOperand &rhs) const = 0; //  quotient
        virtual IOperand* operator%(const IOperand &rhs) const = 0; //  modulo

        virtual ~IOperand () {}
};
#endif /* !IOPERAND_HPP_ */
