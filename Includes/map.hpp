/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include "IOperand.hpp"
#include <map>

class Calcul {
    public:
        TEST();
        ~TEST();
        std::map<std::string, void (TEST::*)(int, int)> _map;
        void add(int, int);
        void mul(int, int);
        void teste();
};


#endif /* !MAP_HPP_ */
