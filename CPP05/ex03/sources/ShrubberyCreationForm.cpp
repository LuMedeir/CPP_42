#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
AForm("ShrubberyCreationForm", 145, 137), target("NoTarget") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const newTarget):
AForm("ShrubberyCreationForm", 145, 137), target(newTarget) {
	std::cout << "ShrubberyCreationForm constructor with parameters called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& that):
AForm("ShrubberyCreationForm", 145, 137), target("NoTarget"){
	*this = that;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& that){
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(target) = that.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSing()) {
		throw AFormNotSignedException();
	} 
	else if (executor.getGrade() > getGradeToEx()) {
		throw GradeTooLowException();
	}
	std::ofstream file;
	std::string filename = this->target + "_shrubbery";
	file.open(filename.c_str());
	if (file.is_open())
	{
		file << "              _{\\ _{\\{\\/}/}/}__                           _{\\ _{\\{\\/}/}/}__" << std::endl;
		file << "             {/{/\\}{/{/\\}(\\}{/\\} _                       {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
		file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _                  {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
		file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}              {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
		file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}              {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
		file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}             _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
		file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}           {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
		file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}           _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
		file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}         {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
		file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}         {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)           {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}          {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}           {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
		file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}             {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
		file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)               (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
		file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}                     {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
		file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}                        {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
		file << "              {){/ {\\/}{\\/} \\}\\}                          {){/ {\\/}{\\/} \\}\\}" << std::endl;
		file << "              (_)  \\.-'.-/                                 (_)  \\.-'.-/" << std::endl;
		file << "          __...--- |'-.-'| --...__     Shrubberies     __...--- |'-.-'| --...__" << std::endl;
		file << "   _...--'   .-'   |'-.-'|  ' -.  ''--.._________...--'   .-'   |'-.-'|  ' -.  ''--..__" << std::endl;
		file << " -'    ' .  . '    |.'-._| '  . .  '   ''._- _-'    ' .  . '    |.'-._| '  . .  '   ''._" << std::endl;
		file << " .  '-  '    .--'  | '-.'|    .  '  . ' . . ' -' '-  '    .--'  | '-.'|    .  '     . '" << std::endl;
		file << "          ' ..     |'-_.-|                             ' ..     |'-_.-|               -" << std::endl;
		file << "  .  '  .       _.-|-._ -|-._  .  '  .    '  . .  '  .       _.-|-._ -|-._  .  '  .   '" << std::endl;
		file << "              .'   |'- .-|   '.                            .'   |'- .-|   '." << std::endl;
		file << "  ..-'   ' .  '.   `-._.--   .'  '  - .        ..-'   ' .  '.   `-._.--   .'  '  - ." << std::endl;
		file << "   .-' '        '-._______.-'     '  .   . .    .-' '        '-._______.-'     '  ." << std::endl;
		file << "    .       .    .   .    ' '-.                     .       .    .   .    ' '-. '" << std::endl;
		file.close();
	}
	else
	{
		std::cout << RED "Error creating file '" <<  filename << "'" RESET << std::endl;
	}
}