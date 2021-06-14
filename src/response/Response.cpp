#include <Response.hpp>

namespace ft
{
	

	Response::Response()
	{/* Illegal*/}

	Response::Response(IHeader *head, IBody *body) : _header(head), _body(body)
	{}

	Response::~Response()
	{
		if (_header)
			delete _header;
		if (_body)
			delete _body;
	}

	Response::Response(const Response &ref)
	{
		(void)ref;
		throw std:: runtime_error("No implementation");
	}

	Response &Response::operator=(const Response &ref)
	{
		(void)ref;
		throw std:: runtime_error("No implementation");
		return (*this);
	}

	IHeader					*Response::getHeader(void)
	{
		return _header;
	}

	IBody					*Response::getBody(void)
	{
		return _body;
	}

	std::string				Response::to_string(void) const
		{
			if (_header && _body)
				return	_header->to_string() + _body->to_string();
			else if (_header)
				return _header->to_string();
			else
				return "";
		}

	unsigned long			Response::size() const
	{
		return (_header->size() + _body->size());
	}

	void Response::deleteBody()
	{
		if (_body)
			delete _body;
		_body = nullptr;
	}
} // namespace ft