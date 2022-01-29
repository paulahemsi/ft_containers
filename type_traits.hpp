/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:52:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/01/28 22:51:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

	//integral_constant to make false/true_type typedef below
	template<typename _Tp, _Tp __v>
	struct integral_constant
	{
		static const _Tp				value = __v;

		typedef _Tp							value_type;
		typedef integral_constant<_Tp, __v>	type;

		operator value_type() const { return value; }
	};

	//tpedefs to is_integral implementation below
	typedef integral_constant<bool, false>	false_type;
	typedef integral_constant<bool, true>	true_type;

	//is_integral
	template<typename T>
	struct is_integral<bool> : false_type {};

	//specializations
	template<>
	struct is_integral<bool> : true_type {};

	template<>
	struct is_integral<char> : true_type {};
	
	template<>
	struct is_integral<unsigned char> : true_type {};
	
	template<>
	struct is_integral<int> : true_type {};
	
	template<>
	struct is_integral<unsigned int> : true_type {};

	template<>
	struct is_integral<long> : true_type {};
	
	template<>
	struct is_integral<unsigned long> : true_type {};

	template<>
	struct is_integral<long long> : true_type {};
	
	template<>
	struct is_integral<unsigned long long> : true_type {};

	//enable if
	template <bool Cond, class T = void>
	struct enable_if {};
	
	//Partial specialization for true.
	template <>
	struct enable_if<true, T> {typedef T type;};
}


#endif
