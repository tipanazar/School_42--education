/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:31:28 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 18:27:17 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(char *input)
{
	char    *_str;
	char    _convchar;
	int     _convint;
	float   _convfloat;
	double  _convdouble;
	_str = input;
    if (strlen(_str) == 1 && !(_str[0] >= '0' && _str[0] <= '9'))
    {
        if (!(_str[0] >= 32 && _str[0] <= 126))
        {
            std::cout << "Cannot convert non printable char" << std::endl;
            return;
        }
        _convchar = _str[0];
        _convint = static_cast<int>(_str[0]);
        _convfloat = static_cast<float>(_convint);
        _convdouble = static_cast<double>(_convint);
    }
    else
    {
		_convdouble = atof(_str);
		_convchar = static_cast<char>(_convdouble);
		_convint = static_cast<int>(_convdouble);
		_convfloat = static_cast<float>(_convdouble);
    }
    std::cout.precision(1);
    if (!(_convint >= 0 && _convint <= 255))
        std::cout << "char: impossible" << std::endl;
    else if (!(_convint >= 32 && _convint <= 126))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << _convchar << "'" << std::endl;

    if (!(_convdouble >= INT_MIN && _convdouble <= INT_MAX) && std::isfinite(_convint))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _convint << std::endl;

    if (!(_convdouble >= -FLT_MAX && _convdouble <= FLT_MAX) && std::isfinite(_convfloat))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << _convfloat << "f" << std::endl;

    if (!(_convdouble >= -DBL_MAX && _convdouble <= DBL_MAX) && std::isfinite(_convdouble))
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << _convdouble << std::endl;
}

char = a
int i = (int)a