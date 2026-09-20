/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/20 09:46:13 by kuyu             ###   ########.fr       */
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

	std::cout << "\n===== Test 6: Bureaucrat has enough authority =====" << std::endl;
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

	std::cout << "\n===== Test 7: Bureaucrat does not have enough authority =====" << std::endl;
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

	std::cout << "\n===== Test 8: Bureaucrat exactly meets requirement =====" << std::endl;
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

	std::cout << "\n===== Test 10: Direct beSigned exception test =====" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 43);
		Form		form("Application", 42, 70);

		form.beSigned(bob);
		std::cout << "[FAIL] Exception was expected" << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << "[PASS] Correct exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[FAIL] Wrong exception: " << e.what() << std::endl;
	}

	return (0);
}
