#include <stdio.h>
#include "paper.hpp"

using namespace myun2::paper_script;

int main()
{
	//	Load phase
	loader l("ex.txt");
	puts(l.data());

	//	Parse phase
	tokenizer tk;
	tokenizer::token_list tl = tk.parse(l.data());

	for(int i=0; i<tl.size(); i++)
		printf("\"%s\"\n", tl[i].c_str());
	return 0;
}
