#include "Request.hpp"

namespace ft
{
	
	Request::Request() :
		_header(nullptr),
		_body(nullptr) {}


	Request::Request(IHeader *head, IBody *body) : _header(head), _body(body)
	{}

	Request::~Request()
	{
		if (_header)
			delete _header;
		if (_body)
			delete _body;
	}

	Request::Request(const Request &ref)
	{
		(void)ref;
		throw ft::runtime_error("No implementation");
	}

	Request &Request::operator=(const Request &ref)
	{
		(void)ref;
		throw ft::runtime_error("No implementation");
		return (*this);
	}

	IHeader					*Request::getHeader()
	{
		return _header;
	}

	IBody					*Request::getBody()
	{
		return _body;
	}

	std::string				Request::to_string() const
	{
		if (_header && _body)
			return	_header->to_string() + _body->to_string();
		else if (_header)
			return _header->to_string();
		else
			return "";
	}

	void Request::setBody(IBody *body) {
		_body = body;
	}

	void Request::setHeader(IHeader *header) {
		if (_header)
			delete _header;
		_header = header;
	}

	int Request::getPort() {
		return _port;
	}

	void Request::setPort(int port) {
		_port = port;
	}


} // namespace ft