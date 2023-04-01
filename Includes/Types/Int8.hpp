/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "../IOperand.hpp"

class Int8 : public IOperand
{
    public:
        Int8(std::string val);
        ~Int8();

        virtual std::string toString() const;
        virtual IOperand::eOperandType getType() const;
        void OverflowError(std::string val) const;
        virtual IOperand* operator+(const IOperand &rhs) const;
        virtual IOperand* operator-(const IOperand &rhs) const;
        virtual IOperand* operator*(const IOperand &rhs) const;
        virtual IOperand* operator/(const IOperand &rhs) const;
        virtual IOperand* operator%(const IOperand &rhs) const;
    private:
        std::string toPrint;
};

#endif /* !INT8_HPP_ */
