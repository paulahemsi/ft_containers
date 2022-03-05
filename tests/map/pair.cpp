/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:00:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/03/05 18:29:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.tpp"

#include <string>
#include <iostream>

int test_pair(void)
{
  ft::pair <std::string,double> product1;
  ft::pair <std::string,double> product2 ("tomatoes",2.30);
  ft::pair <std::string,double> product3 (product2);

  //product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
  std::cout << "P2 == P3: " << (product2 == product3) << std::endl;
  std::cout << "P2 != P3: " << (product2 != product3) << std::endl;
  std::cout << "P2 > P3: " << (product2 > product3) << std::endl;
  std::cout << "P2 >= P3: " << (product2 >= product3) << std::endl;
  std::cout << "P2 < P3: " << (product2 < product3) << std::endl;
  std::cout << "P2 <= P3: " << (product2 <= product3) << std::endl;

  product2.second = 39.90;
  std::cout << "P2 == P3: " << (product2 == product3) << std::endl;
  std::cout << "P2 != P3: " << (product2 != product3) << std::endl;
  std::cout << "P2 > P3: " << (product2 > product3) << std::endl;
  std::cout << "P2 >= P3: " << (product2 >= product3) << std::endl;
  std::cout << "P2 < P3: " << (product2 < product3) << std::endl;
  std::cout << "P2 <= P3: " << (product2 <= product3) << std::endl;

  product2.first = "shoes";
  std::cout << "P2 == P3: " << (product2 == product3) << std::endl;
  std::cout << "P2 != P3: " << (product2 != product3) << std::endl;
  std::cout << "P2 > P3: " << (product2 > product3) << std::endl;
  std::cout << "P2 >= P3: " << (product2 >= product3) << std::endl;
  std::cout << "P2 < P3: " << (product2 < product3) << std::endl;
  std::cout << "P2 <= P3: " << (product2 <= product3) << std::endl;  

  ft::pair <std::string,double> product4;
  product4 = product2;

  std::cout << "P1: The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "P2: The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "P3: The price of " << product3.first << " is $" << product3.second << '\n';
  std::cout << "P4: The price of " << product4.first << " is $" << product4.second << '\n';

  std::cout << "P1 == P2: " << (product1 == product2) << std::endl;
  std::cout << "P2 == P3: " << (product2 == product3) << std::endl;
  std::cout << "P3 == P4: " << (product3 == product4) << std::endl;
  std::cout << "P2 == P4: " << (product2 == product4) << std::endl;
  return 0;
}
