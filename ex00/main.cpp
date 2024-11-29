/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 10:47:16 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	std::string param;
	ScalarConverter tmp;

	(void)argc;
	(void)argv;
	// float test = 3.1111111;
	// std::cout << "Default test: " << test << std::endl;
	std::cout << "Prompt: " << std::flush;
	while (std::getline(std::cin, param))
	{
		tmp.convert(param);
		std::cout << "Prompt: " << std::flush;
	}
	std::cout << "Exit" << std::endl;
	return (0);
}
