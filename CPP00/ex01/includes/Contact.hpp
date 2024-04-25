#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string number;
		std::string dkSecret;

	public:
		void		setFirstName(std::string name);
		void		setLastName(std::string name);
		void		setNickName(std::string name);
		void		setNumber(std::string number);
		void		setDkSecret(std::string secret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getNumber(void);
		std::string	getDkSecret(void);
};

#endif
