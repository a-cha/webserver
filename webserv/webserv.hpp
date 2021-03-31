#pragma once
#include <string>

namespace ft
{
	static const char webpage_header[] =
		"HTTP/1.1 200 OK\r\n"
		"Connection: keep-alive\r\n"
		"Content-Length: 636\r\n" // 614
		"Content-Type: text/html; charset=UTF-8\r\n\r\n";

	static const char webpage2_header[] =
		"HTTP/1.1 200 OK\r\n"
		"Connection: keep-alive\r\n"
		"Content-Length: 593\r\n"
		"Content-Type: text/html; charset=UTF-8\r\n\r\n";

	static const char webpage_body[] =
		"<!DOCTYPE html>"
		"<html>"
		"<head>"
		"<title>Welcome to myNGINX!</title>"
		"<style>"
		"    body {"
		"        width: 35em;"
		"        margin: 0 auto;"
		"        font-family: Tahoma, Verdana, Arial, sans-serif;"
		"    }"
		"</style>"
		"</head>"
		"<body>"
		"<h1>Welcome to myNGINX!</h1>"
		"<p>If you see this page, the nginx web server is successfully installed and "
		"working. Further configuration is required.</p>"

		"<p>For online documentation and support please refer to"
		"<a href=\"http://nginx.org/\">nginx.org</a>.<br/>"
		"Commercial support is available at "
		"<a href=\"http://nginx.com/\">nginx.com</a>.</p>"

		"<p><em>Thank you for using nginx.</em></p>"
		"<img src=\"trump.gif\">"
		"<img src=\"baiden.gif\">"
		"</body>"
		"</html>";

	static const char webpage2_body[] =
		"<!DOCTYPE html>"
		"<html>"
		"<head>"
		"<title>Welcome to myNGINX!</title>"
		"<style>"
		"    body {"
		"        width: 35em;"
		"        margin: 0 auto;"
		"        font-family: Tahoma, Verdana, Arial, sans-serif;"
		"    }"
		"</style>"
		"</head>"
		"<body>"
		"<h1>Welcome to myNGINX!</h1>"
		"<p>If you see this page, the nginx web server is successfully installed and "
		"working. Further configuration is required.</p>"

		"<p>For online documentation and support please refer to"
		"<a href=\"http://nginx.org/\">nginx.org</a>.<br/>"
		"Commercial support is available at "
		"<a href=\"http://nginx.com/\">nginx.com</a>.</p>"

		"<p><em>Thank you for using nginx.</em></p>"
		"</body>"
		"</html>";

	static const char webpage2[] =
		"HTTP/1.1 200 OK\r\n"
		"Content-Type: text/html; charset=UTF-8\r\n\r\n"
		"<!DOCTYPE html>"
		"<html>"
		"<head>"
		"<title>Welcome to myNGINX!</title>"
		"<style>"
		"    body {"
		"        width: 35em;"
		"        margin: 0 auto;"
		"        font-family: Tahoma, Verdana, Arial, sans-serif;"
		"    }"
		"</style>"
		"</head>"
		"<body>"
		"<h1>Welcome to myNGINX!</h1>"
		"<p>If you see this page, the nginx web server is successfully installed and "
		"working. Further configuration is required.</p>"

		"<p>For online documentation and support please refer to"
		"<a href=\"http://nginx.org/\">nginx.org</a>.<br/>"
		"Commercial support is available at "
		"<a href=\"http://nginx.com/\">nginx.com</a>.</p>"

		"<p><em>Thank you for using nginx.</em></p>"
		"</body>"
		"</html>\r\n\r\n";


	typedef enum header_keys
	{
		h_accept_charsets,
		h_accept_language,
		h_allow,
		h_authorization,
		h_content_language,
		h_content_length,
		h_content_location,
		h_content_type,
		h_date,
		h_host,
		h_last_modified,
		h_location,
		h_referer,
		h_retry_after,
		h_server,
		h_transfer_encoding,
		h_user_agent,
		h_www_authenticate
	} header_keys_enum;

	enum methods_enum
	{
		m_get,
		m_post,
		m_put
	};


	
	void				*ft_memcpy(void *dest, const void *src, unsigned long num);
	unsigned long		ft_strlen(char *str);
	std::string			getHeaderKey(header_keys_enum key);
	std::string			getMethodStr(const methods_enum key);
	std::string			getCodeDescr(int code);
	std::string			to_string(int num);
}