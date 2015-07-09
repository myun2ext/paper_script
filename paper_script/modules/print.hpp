#ifndef __MYUN2_GITHUB_COM__PAPER_SCRIPT__MODULES__PRINT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_SCRIPT__MODULES__PRINT_HPP__

namespace myun2
{
	namespace paper_script_builtin_modules
	{
		typedef typename paper_script::token_list token_list, tokens_type;
		typedef typename paper_script::token_iterator token_iterator;

		struct print {
			token_iterator last;
			print(token_iterator it, const token_iterator end)
			{
				const ::std::string token = *it;
				while ( token != "." && it != end )
				{
					if ( token != "\"" )
						puts(token.c_str());
					it++;
				}
				last = it;
			}
		};
	}
}

#endif///__MYUN2_GITHUB_COM__PAPER_SCRIPT__MODULES__PRINT_HPP__
