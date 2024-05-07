#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	private:
		std::string string;
		int	number;
	public:
		Data(void);
		Data(std::string string, int number);
		~Data(void);
		Data(Data const &copy);
		Data &operator=(Data const &rhs);

		std::string getString(void) const;
		int getNumber(void) const;

		void setString(std::string string);
		void setNumber(int number);
};

#endif