/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:39:14 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 18:17:05 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	std::srand(std::rand());
	switch (std::rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	void *test;

	test = dynamic_cast<A*>(p);
	if (test)
	{
		std::cout << "Object is of type: A" << std::endl;
		return ;
	}
	test = dynamic_cast<B*>(p);
	if (test)
	{
		std::cout << "Object is of type: B" << std::endl;
		return ;
	}
	test = dynamic_cast<C*>(p);
	if (test)
	{
		std::cout << "Object is of type: C" << std::endl;
		return ;
	}
	std::cout << "Object type can not be identified" << std::endl;
}

void identify(Base& p)
{
	try {
		A &test_A = dynamic_cast<A&>(p);
		(void)test_A;
		std::cout << "Object is of type: A" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
		(void)e;
	};
	try {
		B &test_B = dynamic_cast<B&>(p);
		(void)test_B;
		std::cout << "Object is of type: B" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
		(void)e;
	};
	try {
		C &test_C = dynamic_cast<C&>(p);
		(void)test_C;
		std::cout << "Object is of type: C" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
		(void)e;
	}
	std::cout << "Object type can not be identified" << std::endl;
}

int	main(void)
{
	std::string	input;
	Base		*object;
	std::cout << "Press enter to generate one random Object: " << std::flush;
	while (std::getline(std::cin, input))
	{
		object = generate();
		std::cout << "Pointer identification: " << std::endl;
		identify(object);
		std::cout << "Reference identification: " << std::endl;
		identify(*object);
		delete object;
		std::cout << "Press enter to generate one random Object: " << std::flush;
	}
	if (std::cin.eof())
	{
		std::cout << "Exit" << std::endl;
		return (0);
	}
	else
	{
		std::cerr << "error on stdin" << std::endl;
		return (1);
	}
}
