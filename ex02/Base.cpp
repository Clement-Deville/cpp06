/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:23 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 16:46:47 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**========================================================================
 *                            CANNONICAL DECLARATION
 *========================================================================**/

Base::~Base()
{
	std::cout << "\e[0;31mBase destructor called\e[0m" << std::endl;
}

A::~A()
{
	std::cout << "\e[0;31mA destructor called\e[0m" << std::endl;
}

B::~B()
{
	std::cout << "\e[0;31mB destructor called\e[0m" << std::endl;
}

C::~C()
{
	std::cout << "\e[0;31mC destructor called\e[0m" << std::endl;
}
