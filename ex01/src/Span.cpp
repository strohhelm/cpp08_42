/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:51 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/23 15:06:49 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"


Span::Span(unsigned int N)
{
	_max = N;
	_maxValue = std::numeric_limits<int>::min();
}

Span& Span::operator=(const Span& src)
{
	_vec = src._vec;
	return *this;
}

const char *Span::NoSpanException::what() const noexcept
{
	return ("There is no Span in these Numbers! either all are the same, or there is only one inside");
}
const char *Span::SizeException::what() const noexcept
{
	return ("There is no more space in this container!");
}


void Span::addNumber(int num)
{
	if (!_vec.size())
	{
		_maxValue = num;
		_minValue = num;
	}
	if (_vec.size() + 1 > _max)
		throw Span::SizeException();
	_vec.push_back(num);
	if (num > _maxValue)
		_maxValue = num;
	if (num < _minValue)
		_minValue = num;
}

int	Span::shortestSpan(void)
{
	int min_span = _maxValue - _minValue;
	if (_vec.size() <= 1)
		throw Span::NoSpanException();
	if (_maxValue > 10000000)
		std::cout<<"sorting now!"<<std::endl;
	std::sort(_vec.begin(), _vec.end());
	if (_maxValue > 10000000)
		std::cout<<"sorting finished!\nlooking for shortest span now!"<<std::endl;
	for (auto it = _vec.begin(); it < _vec.end() - 1; it++)
	{
		if ((*(it + 1) - *it) != 0 && (*(it + 1) - *it) < min_span)
			min_span = *(it + 1) - *it;
	}
	if (min_span == 0)
		throw Span::NoSpanException();
	return min_span;
}

int	Span::longestSpan(void) const
{
	std::cout<<"\n{_maxValue: "<<_maxValue<<"\n_minValue: "<<_minValue<<"}"<<std::endl;
	int span = _maxValue - _minValue;
	span = span >= 0 ? span : -span;
	if (!span)
		throw Span::NoSpanException();
	return(span);
}




