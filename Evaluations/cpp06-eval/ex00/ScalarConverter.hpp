/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:32:12 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:42:22 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <climits>
# include <float.h>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(char *input);

	private:
		ScalarConverter();
};

#endif
