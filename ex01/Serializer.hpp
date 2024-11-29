/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:53:52 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 17:31:30 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

struct Data{
	std::string	name;
	int			randow_value;
};

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &Cpy);
	virtual ~Serializer() = 0;
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer &operator=(const Serializer &Cpy);
};

#endif
