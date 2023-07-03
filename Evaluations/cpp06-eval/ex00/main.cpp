/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:32:23 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 18:28:52 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{

	if (argc != 2 || argv[1] == NULL)
	{
		std::cout << "One arg, please" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
