/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:07:23 by syakovle          #+#    #+#             */
/*   Updated: 2023/08/26 21:42:43 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int countchar = 0;
    int countav = 1;

    if (ac <= 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
    while (av && av[countav])
    {
        while (av[countav][countchar])
        {
            av[countav][countchar] = std::toupper(av[countav][countchar]);
            countchar++;
        }
        std::cout << av[countav];
        countav++;
        countchar = 0;
        if (av[countav])
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}