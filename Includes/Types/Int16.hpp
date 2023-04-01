/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "../IOperand.hpp"

class Int16 : public IOperand
{
    public:
        Int16(std::string val);
        ~Int16();

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

#endif /* !INT16_HPP_ */
