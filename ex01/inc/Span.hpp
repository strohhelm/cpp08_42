/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:25:11 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/20 17:12:11 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <Array>
#include <exception>


class Span 
{
	public:
		Span()= delete;
		~Span() = default;
		Span(unsigned int N);
		Span(const Span& src) = default;
		Span& operator=(const Span& src)=default;
		void addNumber(int i);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
		
		class NoSpanException : public std::exception
		{const char *what() const noexcept override {return "There is no Span in these Numbers!";};};

};
#endif