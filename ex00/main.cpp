/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/28 15:26:30 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	std::string param;
	ScalarConverter tmp;

	(void)argc;
	(void)argv;
	std::cout << "Prompt: " << std::flush;
	while (std::getline(std::cin, param))
	{
		tmp.convert(param);
		std::cout << "Prompt: " << std::flush;
	}
	std::cout << "Exit" << std::endl;
	return (0);
}
