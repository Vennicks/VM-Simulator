/*
** EPITECH PROJECT, 2020
** 100_BIG_D
** File description:
** main
*/

#include "../Includes/CoreOperation.hpp"

int main(int argc, char const *argv[])
{
    CoreOperation Core;
    if (argc == 1) {
        Core.noFile();
        Core.witheFile(NAMENOFILE);
        remove(NAMENOFILE);
    } else if (argc == 2) {
        Core.witheFile(argv[1]);
    } else
        return (84);
    return 0;
}