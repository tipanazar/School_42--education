/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:33:17 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:33:21 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static  Data* deserialize(uintptr_t raw);
		~Serializer();

	private:
	Serializer();
};

#endif