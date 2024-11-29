/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:52 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 17:48:48 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

class Base
{
public:
	virtual ~Base();
};

class A: public Base{
	virtual ~A();
};

class B: public Base{
	virtual ~B();
};

class C: public Base{
	virtual ~C();
};

#endif
