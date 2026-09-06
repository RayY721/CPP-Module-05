/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 09:29:47 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/04 21:57:20 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::gradeIncrement()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::gradeDecrement()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		// call form.beSigned() to sign the form
		form.beSigned(*this);
		// print <bureaucrat> signed <form>
		std::cout << _name
					<< " signed "
					<< form.getName()
					<< std::endl;
	}
	catch (const std::exception& e)
	{
		// print <bureaucrat> couldn’t sign <form> because <reason>.
		std::cout << _name
					<< " couldn't sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";
	return (out);
}