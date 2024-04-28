#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        Brain(Brain const &that);
        ~Brain(void);
        Brain &operator=(Brain const &that);

        void        setIdeas(std::string ideas, int index);
        std::string getIdeas(int index);

};

#endif