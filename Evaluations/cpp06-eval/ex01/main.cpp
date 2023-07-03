/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:32:57 by lupereir          #+#    #+#             */
/*   Updated: 2023/07/01 15:33:00 by lupereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data *data = new Data("Hello World!");

    uintptr_t serialized = Serializer::serialize(data);

    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == data) {
        std::cout << "Deserialization successful." << std::endl;
    } else {
        std::cout << "Deserialization failed." << std::endl;
    }
	std::cout << "Data in data object: " << data->getStr() << std::endl;
	std::cout << "Data deserialized:   " << deserialized->getStr() << std::endl;
	std::cout << "Data address:              " << data << std::endl;
	std::cout << "Data deserialized address: " << deserialized << std::endl;
	std::cout << "Data serialized: " << serialized << std::endl;

	delete data;
    return 0;
}
