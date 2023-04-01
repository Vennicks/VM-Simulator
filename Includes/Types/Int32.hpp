/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "../IOperand.hpp"

class Int32 : public IOperand
{
    public:
        Int32(std::string val);
        ~Int32();

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

#endif /* !INT32_HPP_ */
