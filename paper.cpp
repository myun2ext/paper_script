#include "paper.hpp"
#include "paper_script/modules/print.hpp"
using namespace myun2;

int main()
{
	paper_script s("ex.txt");
	paper_script::context c;

	c.register_function<paper_script_builtin_modules::print>("print");

	s.run(c);
	return 0;
}
