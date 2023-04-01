/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "../IOperand.hpp"

class BigDecimal : public IOperand
{
    public:

        BigDecimal(std::string val);
        ~BigDecimal();

        void OverflowError(std::string val) const;
        std::string toString() const;
        IOperand::eOperandType getType() const;
        IOperand* operator+(const IOperand &rhs) const;
        IOperand* operator-(const IOperand &rhs) const;
        IOperand* operator*(const IOperand &rhs) const;
        IOperand* operator/(const IOperand &rhs) const;
        IOperand* operator%(const IOperand &rhs) const;
    private:
        std::string toPrint;
};

#endif /* !BIGDECIMAL_HPP_ */