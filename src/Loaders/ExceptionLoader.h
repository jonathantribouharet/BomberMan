#ifndef _EXCEPTION_LOADER_H_
#define _EXCEPTION_LOADER_H_

#include <exception>

class ExceptionLoader : public std::exception{
	
	public:
		ExceptionLoader(const std::string & _message)
		:message(_message){
		}

		virtual ~ExceptionLoader() throw() {}

		virtual const char* what() const throw(){
		    return message.c_str();
		}

	private:
		const std::string message;
};

#endif
