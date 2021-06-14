#pragma once
#include <IResponse.hpp>
#include <runtime_error.hpp>
namespace ft
{

	class Response : public IResponse
	{
	private:
		IHeader			*_header;
		IBody			*_body;
		Response();
		Response(const Response &ref);
		Response &operator=(const Response &ref);
	public:
		Response(IHeader *head, IBody *body);
		virtual ~Response();
		
		IHeader					*getHeader(void);
		IBody					*getBody(void);
		std::string				to_string(void) const;
		unsigned long			size() const;

		virtual void deleteBody();
	};


} // namespace ft
