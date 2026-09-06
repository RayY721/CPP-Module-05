/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 18:02:36 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/04 09:47:08 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		
		const std::string&	getName() const;
		int			getGrade() const;
		
		void		gradeIncrement();
		void		gradeDecrement();
		void		signForm(Form& form) const;

	// nested class for exception handling
	class GradeTooHighException : public std::exception
	{
		// override the what(), 
		// const means what() will not change the current exception object, 
		// throw() means what() will not throw any exception
		public:
			virtual const char* what() const throw();
		
	};
	class GradeTooLowException : public std::exception
	{
		// private by default, so need "public" to make it accessable
		public:
			virtual const char* what() const throw();
	};
};

// overloading the << operator
std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif