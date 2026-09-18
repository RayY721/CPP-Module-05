/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/18 21:50:36 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== Test 1: Normal construction =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 2: Grade too high =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 0);
		std::cout << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 3: Grade too low =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 151);
		std::cout << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 4: Increment =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);

		std::cout << "Before: " << bob << std::endl;

		bob.gradeIncrement();

		std::cout << "After:  " << bob << std::endl;

		// Bob is already grade 1, so this should throw.
		bob.gradeIncrement();

		std::cout << "This line should NOT be printed." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 5: Decrement =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 149);

		std::cout << "Before: " << bob << std::endl;

		bob.gradeDecrement();

		std::cout << "After:  " << bob << std::endl;

		// Bob is already grade 150, so this should throw.
		bob.gradeDecrement();

		std::cout << "This line should NOT be printed." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 6: Copy constructor =====" << std::endl;
	try
	{
		Bureaucrat original("Alice", 50);
		Bureaucrat copy(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 7: Assignment operator =====" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 100);

		std::cout << "Before assignment:" << std::endl;
		std::cout << "Alice: " << alice << std::endl;
		std::cout << "Bob:   " << bob << std::endl;

		alice = bob;

		std::cout << "After alice = bob:" << std::endl;
		std::cout << "Alice: " << alice << std::endl;
		std::cout << "Bob:   " << bob << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
