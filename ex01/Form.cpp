/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:05:15 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/18 21:52:16 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

Form::~Form()
{
	
}

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "Form Name: "
		<< form.getName()
		<< ", Sign Flag: "
		<< form.getIsSigned()
		<< ", Sign Grade: "
		<< form.getGradeToSign()
		<< ", Execute Grade: "
		<< form.getGradeToExecute();

	return (out);
}
