/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "../IOperand.hpp"

class Double : public IOperand
{
    public:
        Double(std::string val);
        ~Double();

        std::string toString() const;
        IOperand::eOperandType getType() const;
        void OverflowError(std::string val) const;
        void printer();
        IOperand* operator+(const IOperand &rhs) const;
        IOperand* operator-(const IOperand &rhs) const;
        IOperand* operator*(const IOperand &rhs) const;
        IOperand* operator/(const IOperand &rhs) const;
        IOperand* operator%(const IOperand &rhs) const;
    private:
        std::string toPrint;
};

#endif /* !DOUBLE_HPP_ */
