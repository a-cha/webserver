#pragma once

#include <IRequest.hpp>
#include <runtime_error.hpp>

namespace ft
{
	class Request : public IRequest
	{
	private:
		Request(const Request &ref);
		IHeader	*_header;
		IBody	*_body;
		int 	_port;
	public:
		Request();
		IHeader					*getHeader(void);
		IBody					*getBody(void);
		std::string				to_string(void) const;
		virtual  ~Request();
		void setBody(IBody *body);
		void setHeader(IHeader *header);
		Request(IHeader *head, IBody *body);
		Request &operator=(const Request &ref);

		int 					getPort();
		void 					setPort(int port);
	};

} // namespace ft