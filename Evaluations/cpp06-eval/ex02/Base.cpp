/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:33:26 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:33:29 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	int i = rand() % 3;
	std::cout << "Random number: " << i << std::endl;
	if (i == 0)
	{
		std::cout << "Generetad type: A" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{
		std::cout << "Generetad type: B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Generetad type: C" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified type: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Identified type: A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Identified type: B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Identified type: C" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
	}
}
