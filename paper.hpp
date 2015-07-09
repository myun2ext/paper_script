#ifndef __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
#define __MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__

#include "nscript/loader.hpp"
#include "nscript/tokenizer.hpp"
#include <map>

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
		struct context {
			struct function_caller_base {
				virtual token_iterator call(token_iterator it, const token_iterator end) = 0;
			};

			template <typename Function>
			struct function_caller : function_caller_base {
				token_iterator call(token_iterator it, const token_iterator end) {
					Function f(it, end);
					return f.last;
				}
			};

			::std::map< ::std::string, function_caller_base* > functions;

			template <typename Function>
			void register_function(const char* name) {
				functions[name] = new function_caller<Function>;
			}

			token_iterator call(token_iterator it, token_iterator end)
			{
				const ::std::string ope = *it++;
				return functions[ope]->call(it, end);
			}
		};
	public:
		paper_script(const char* path) { load(path); }

		bool load(const char* path)
		{
			myun2::nscript::loader ldr(path);
			myun2::nscript::tokenizer tknzr;

			tokens = tknzr.parse(ldr.data());
			return true;
		}
		bool process(context c)
		{
			bool commenting = false;
			for(token_iterator it=tokens.begin(); it != tokens.end(); it++)
			{
				if ( !commenting )
				{
					if ( *it == "#" )
						commenting = true;
					else {
						it = process_line(c, it, tokens.end());
						if ( it == tokens.end() )
							break;
					}
				}
				else if ( *it == "#" )
					commenting = false;
			}
		}
		token_iterator process_line(context c, token_iterator it, token_iterator end)
		{
			return c.call(it, end);
		}
		bool run(context c) { return process(c); }
	};
}

#endif///__MYUN2_GITHUB_COM__PAPER_SCRIPT_HPP__
