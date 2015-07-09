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
			for(int i=0; i<tokens.size(); i++)
			{
				const ::std::string& token = tokens[i];
				if ( !commenting )
				{
					if ( token == "#" )
						commenting = true;
					else
						process_one(token);
				}
				else if ( token == "#" )
					commenting = false;
			}
		}
		bool process_one(const ::std::string& token)
		{
			puts(token.c_str());
		}
		bool run() { return process(); }
	};
}

#endif///__MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
