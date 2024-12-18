/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:43 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 16:14:19 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	std::string param;

	(void)argc;
	(void)argv;
	std::cout << "Prompt: " << std::flush;
	while (std::getline(std::cin, param))
	{
		ScalarConverter::convert(param);
		std::cout << "Prompt: " << std::flush;
	}
	std::cout << "Exit" << std::endl;
	return (0);
}
