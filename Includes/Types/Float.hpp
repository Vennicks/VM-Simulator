/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "../IOperand.hpp"

class Float : public IOperand
{
    public:
        Float(std::string val);
        ~Float();

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

#endif /* !FLOAT_HPP_ */
