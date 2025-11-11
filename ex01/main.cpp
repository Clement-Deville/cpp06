/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:33:43 by cdeville          #+#    #+#             */
/*   Updated: 2025/11/11 15:06:38 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data tab[4] = {{"Clement", 1}, {"John", 2}, {"Alex", 3}, {"Michael", 4}};
	uintptr_t ser_tab[4];
	Data	*ptr;

	for (int i = 0; i < 4; i++)
	{
		ser_tab[i] = Serializer::serialize(&tab[i]);
		std::cout << "Data pointer before serialize:   \e[0;32m" << &tab[i] <<
			"\e[0m serialize value: " << ser_tab[i] << std::endl;
		ptr = Serializer::deserialize(ser_tab[i]);
		std::cout << "Pointer value after deserialize: \e[0;33m"
			<< ptr << "\e[0m" << std::endl;
		std::cout << "Accessing data throught ptr: \nname: " << ptr->name << std::endl;
	}
	return (0);
}
