#ifndef __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__

#include "nscript/loader.hpp"
#include "nscript/tokenizer.hpp"

namespace myun2
{
	class paper_script
	{
	private:
		myun2::nscript::tokenizer::token_list tokens;
	public:
		paper_script(const char* path) { load(path); }

		bool load(const char* path)
		{
			myun2::nscript::loader ldr(path);
			myun2::nscript::tokenizer tknzr;

			tokens = tknzr.parse(ldr.data());
			return true;
		}
	};
}

#endif///__MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
