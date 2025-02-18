/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:12 by pstrohal          #+#    #+#             */
/*   Updated: 2025/02/18 15:14:50 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <random>

template<typename T>
void easyfind(T container, int to_find)
{
	auto occurrence = std::find(container.begin(), container.end(), to_find);
	if(occurrence == container.end())
		throw std::logic_error("No occurence found!");
	return ;
};

#endif