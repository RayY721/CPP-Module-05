/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/06 15:42:43 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	std::cout << "===== Test 1: Normal construction =====" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 42);
		std::cout << bob << std::endl;
		Form	form("application", 50, 70);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n===== Test 2: Sign grade too high =====" << std::endl;
	try
	{
		Form	form("application", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n===== Test 3: Sign grade too low =====" << std::endl;
	try
	{
		Form	form("application", 153, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n===== Test 4: Execute grade too high =====" << std::endl;
	try
	{
		Form	form("application", 42, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n===== Test 5: Execute grade too low =====" << std::endl;
	try
	{
		Form	form("application", 42, 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 6: Bureaucrat grade higher than requirement =====" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 42);
		Form	form("application", 43, 70);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
		bob.signForm(form);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 7: Bureaucrat grade less than requirement =====" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 42);
		Form	form("application", 41, 70);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
		bob.signForm(form);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 8: Bureaucrat grade equals requirement =====" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 42);
		Form	form("application", 42, 70);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
		bob.signForm(form);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 9: Bureaucrat grade equals requirement (Directly calling form's method) =====" << std::endl;
	try
	{
		Bureaucrat	bob("bob", 42);
		Form	form("application", 42, 70);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
		form.beSigned(bob);
		std::cout << "Form signed: " << form.getIsSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}

