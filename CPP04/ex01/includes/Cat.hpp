#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
        private:
        Brain *brain;

        public:
        Cat(void);
        Cat(Cat const &that);
        ~Cat(void);
        Cat &operator=(Cat const &that);

        void    makeSound(void) const;
        Brain *getBrain(void) const;
};

#endif