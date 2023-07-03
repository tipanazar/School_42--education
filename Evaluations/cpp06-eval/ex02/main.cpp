/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:33:39 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:33:42 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	int i = 0;

	while (i < 5)
	{
		std::cout << "Test " << i << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		i++;
	}
	return (0);
}