/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:53:51 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/21 15:58:59 by pstrohal         ###   ########.fr       */
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
	_vec = *src.getVector();
}

const char *Span::NoSpanException::what() const noexcept
{
	return ("There is no Span in these Numbers! either all are the same, or there is only one inside");
}
const char *Span::SizeException::what() const noexcept
{
	return ("There is no more space in this container!");
}
const std::vector<int> *Span::getVector(void)
{
	return (&_vec);
}

void Span::addNumber(int num)
{
	if (_vec.size() + 1 > _max)
		throw Span::SizeException();
	_vec.push_back(num);
	if (num > _maxValue)
		_maxValue = num;
	if (num < _minValue)
		_minValue = num;
}

int	Span::shortestSpan(void) const
{
	static auto iterator = _vec.begin();
	static unsigned int min_span = _maxValue - _minValue;
	if (_vec.size() <= 1)
		throw Span::NoSpanException();
	
		std::for_each (iterator + 1, _vec.end(), [](int value)
		{
			if ((*iterator - value) < min_span)
				min_span = *iterator - value;
		});
		if (iterator == _vec.end())
			return min_span;
		else
		{
			iterator++;
			(void)shortestSpan();
			return min_span;
		}
	if (min_span == 0)
		throw Span::NoSpanException();
	return min_span;
}

int	Span::longestSpan(void) const
{
	int span = _maxValue - _minValue;
	span = span > 0 ? span : -span;
	if (!span)
		throw Span::NoSpanException();
	return(span);
}




