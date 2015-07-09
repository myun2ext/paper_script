#ifndef __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__

#include "nscript/loader.hpp"
#include "nscript/tokenizer.hpp"

namespace myun2
{
	class paper_script
	{
	public:
		typedef myun2::nscript::tokenizer::token_list token_list, tokens_type;
		typedef typename token_list::iterator token_iterator;
	private:
		tokens_type tokens;
	public:
		paper_script(const char* path) { load(path); }

		bool load(const char* path)
		{
			myun2::nscript::loader ldr(path);
			myun2::nscript::tokenizer tknzr;

			tokens = tknzr.parse(ldr.data());
			return true;
		}
		bool process()
		{
			bool commenting = false;
			for(token_iterator it=tokens.begin(); it != tokens.end(); it++)
			{
				if ( !commenting )
				{
					if ( *it == "#" )
						commenting = true;
					else
						process_line(it, tokens.end());
				}
				else if ( *it == "#" )
					commenting = false;
			}
		}
		bool process_line(token_iterator it, token_iterator end)
		{
			const ::std::string token = *it;
			puts(token.c_str());
		}
		bool run() { return process(); }
	};
}

#endif///__MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
