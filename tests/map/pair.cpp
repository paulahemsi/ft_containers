/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:00:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2022/03/06 22:41:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <string>
#include <iostream>

template <class Pair>
static void print_pair(Pair pair)
{
  std::cout << "The price of " << pair.first << " is $" << pair.second << '\n';
}

static void compare_pairs(ft::pair<std::string,double> pair1, ft::pair<std::string,double> pair2)
{
  print_instructions("Pair1:");
  print_pair(pair1);
  print_instructions("Pair2:");
  print_pair(pair2);
  std::cout << "Pair1 == Pair2: " << (pair1 == pair2) << std::endl;
  std::cout << "Pair1 != Pair2: " << (pair1 != pair2) << std::endl;
  std::cout << "Pair1 > Pair2: " << (pair1 > pair2) << std::endl;
  std::cout << "Pair1 >= Pair2: " << (pair1 >= pair2) << std::endl;
  std::cout << "Pair1 < Pair2: " << (pair1 < pair2) << std::endl;
  std::cout << "Pair1 <= Pair2: " << (pair1 <= pair2) << std::endl;
}

static void test_assignment_operator(ft::pair<std::string,double>& pair1)
{
  print_subheading(" = ");
  print_instructions("ft::pair <std::string,double> pair2(\"wine\", 49.90);");
  ft::pair <std::string,double> pairTemp("wine", 49.90);
  print_instructions("pair1 = pairTemp;");
  pair1 = pairTemp;
  print_pair(pair1);
}

static void test_comparsions(ft::pair<std::string,double> pair1, ft::pair<std::string,double> pair2)
{
  print_subheading("comparation");
  compare_pairs(pair1, pair2);

  print_instructions("pair1 = pair2;");
  pair1 = pair2;
  compare_pairs(pair1, pair2);

  print_instructions("pair1.second = 2.33;");
  pair1.second = 2.33;
  compare_pairs(pair1, pair2);

  print_instructions("pair1.second = pair2.second;");
  pair1.second = pair2.second;
  print_instructions("pair1.first = \"tom\";");
  pair1.first = "tom";
  compare_pairs(pair1, pair2);
}

static void test_make_pair(void)
{
  print_subheading("make_pair");

  print_instructions("ft::pair <std::string,double> pair1");
  ft::pair <std::string,double> pair1;
  print_pair(pair1);
  print_instructions("pair1 = ft::make_pair(std::string(\"lightbulbs\"),0.99);");
  pair1 = ft::make_pair(std::string("lightbulbs"),0.99);
  print_pair(pair1);
}

void test_pair(void)
{
  print_title("PAIR");

  print_subheading("constructors");

  print_instructions("ft::pair <std::string,double> pair1");
  ft::pair <std::string,double> pair1;
  print_pair(pair1);
  print_instructions("ft::pair <std::string,double> pair2(\"tomatoes\", 2.30);");
  ft::pair <std::string,double> pair2("tomatoes", 2.30);
  print_pair(pair2);
  print_instructions("ft::pair <std::string,double> pair3 (pair2);");
  ft::pair <std::string,double> pair3 (pair2);
  print_pair(pair3);

  test_assignment_operator(pair1);
  test_comparsions(pair1, pair2);
  test_make_pair();
}
