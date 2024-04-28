#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal{
    private:
        Brain *brain;

    public:
        Dog(void);
        Dog(Dog const &that);
        ~Dog(void);
        Dog &operator=(Dog const &that);

        void    makeSound(void) const;
        Brain *getBrain(void) const;
};

#endif