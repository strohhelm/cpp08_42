/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:51 by pstrohal          #+#    #+#             */
/*   Updated: 2025/02/18 15:02:21 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"


Span::Span(unsigned int N)
{
	_max = N;
}

Span& Span::operator=(const Span& src)
{
	_vec = src._vec;
	return *this;
}

const char *Span::NoSpanException::what() const noexcept
{
	return ("There is no Span in these Numbers! All numbers are the same!");
}
const char *Span::NoSizeException::what() const noexcept
{
	return ("There is nothing in this container!");
}
const char *Span::SizeException::what() const noexcept
{
	return ("There is not enough space in this container!");
}


void Span::addNumber(int num)
{
	if (_vec.size() + 1 > _max)
		throw Span::SizeException();
	_vec.push_back(num);
}
void Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	if (it2 - it1 + _vec.size() > _max)
		throw Span::SizeException();
	_vec.insert(_vec.end(), it1, it2);
}

long Span::shortestSpan(void)
{
	sort_and_diff();
	return static_cast<long>( *(_diff.begin() + 1));
}

void Span::sort_and_diff(void)
{
	if (_vec.size() <= 1)
		throw Span::NoSpanException();

	std::sort(_vec.begin(), _vec.end());
	_diff.resize(_vec.size());
	std::adjacent_difference(_vec.begin(), _vec.end(), _diff.begin(), [](int a, int b){return std::abs(a - b);});
	std::sort(_diff.begin(), _diff.end());
	return ;
}
long Span::longestSpan(void)
{
	sort_and_diff();
	return(static_cast<long>(*(_vec.end() - 1)) - static_cast<long>(*_vec.begin()));
}
void Span::printi(void)
{
	for(unsigned int i = 0; i < _diff.size(); i++)
	{
		std::cout<<_diff[i]<<std::endl;
	}
}
void Span::printv(void)
{
	for(unsigned int i = 0; i < _vec.size(); i++)
	{
		std::cout<<_vec[i]<<std::endl;
	}
	

}


