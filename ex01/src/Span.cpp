/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:51 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/23 17:04:33 by pstrohal         ###   ########.fr       */
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

int	Span::shortestSpan(void)
{
	sort_and_diff();
	return _diff.front();
}

void Span::sort_and_diff(void)
{
	if (_vec.size() <= 1)
		throw Span::NoSpanException();

	std::sort(_vec.begin(), _vec.end());
	_diff.resize(_vec.size());
	std::adjacent_difference(_vec.begin(), _vec.end(), _diff.begin(), [](int a, int b){return std::abs(a - b);});
	_diff[0] = 0;
	_diff.erase(std::remove(_diff.begin(), _diff.end(), 0), _diff.end());
	if (_diff.empty())
		throw Span::NoSpanException();
	std::sort(_diff.begin(), _diff.end());
	return ;
}
int	Span::longestSpan(void)
{
	sort_and_diff();
	return(_vec.back() - _vec.front());
}




