/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:23 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 16:46:47 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**========================================================================
 *                            CANNONICAL DECLARATION
 *========================================================================**/

Serializer::Serializer()
{
	std::cout << "\e[0;32mSerializer Default constructor called\e[0m" << std::endl;
}

Serializer::Serializer(const Serializer &Cpy)
{
	std::cout << "\e[0;32mSerializer Copy constructor called\e[0m" << std::endl;
	(void)Cpy;
}

Serializer &Serializer::operator=(const Serializer &Cpy)
{
	std::cout << "\e[0;32mSerializer assignement operator called\e[0m" << std::endl;
	(void)Cpy;
	return (*this);
};

/**========================================================================
 *                           CONVERT FUNCTION
 *========================================================================**/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
