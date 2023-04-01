/*
** EPITECH PROJECT, 2020
** syn_abstractvm_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IOperand.hpp"
#include "Types/BigDecimal.hpp"
#include "Types/Double.hpp"
#include "Types/Float.hpp"
#include "Types/Int32.hpp"
#include "Types/Int16.hpp"
#include "Types/Int8.hpp"

class Factory {
    public:
        Factory();
        ~Factory();
        static IOperand* createOperand(IOperand::eOperandType type, const std::string& value)
        {
            Factory factory;

            switch (type) {
                case IOperand::INT8:
                    return factory.createInt8(value);
                case IOperand::INT16:
                    return factory.createInt16(value);
                case IOperand::INT32:
                    return factory.createInt32(value);
                case IOperand::FLOAT:
                    return factory.createFloat(value);
                case IOperand::DOUBLE:
                    return factory.createDouble(value);
                case IOperand::BIGDECIMAL:
                    return factory.createBigDecimal(value);
                default:
                    std::exit(84);
    }
};
    protected:
    private:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        IOperand* createBigDecimal(const std::string& value);
};

#endif /* !FACTORY_HPP_ */
