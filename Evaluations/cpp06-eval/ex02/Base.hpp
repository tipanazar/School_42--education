/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:33:32 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:33:34 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base() {};

};

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif