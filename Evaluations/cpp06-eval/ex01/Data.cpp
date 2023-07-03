/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:32:39 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:32:41 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _str("default")
{
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(std::string value): _str(value)
{
	std::cout << "Data constructor called" << std::endl;
}

Data::Data( Data const & src )
{
	std::cout << "Data copy constructor called" << std::endl;
	*this = src;
}

Data::~Data()
{
	std::cout << "Data destructor called" << std::endl;
}

Data &	Data::operator=( Data const & rhs )
{
	std::cout << "Data assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_str = rhs._str;
	}
	return *this;
}

std::string Data::getStr() const
{
	return _str;
}

void		Data::setStr(std::string str)
{
	this->_str = str;
}