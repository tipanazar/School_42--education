/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:32:48 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:32:53 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	public:
	
		Data();
		Data(std::string value);
		Data( Data const & src );
		~Data();
		Data &		operator=( Data const & rhs );
		std::string getStr() const;
		void		setStr(std::string str);

	private:
		std::string _str;
};

#endif
