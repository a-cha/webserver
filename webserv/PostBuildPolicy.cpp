#include <PostBuildPolicy.hpp>

namespace ft
{
	PostBuildPolicy::PostBuildPolicy()
	{
	}
	
	PostBuildPolicy::~PostBuildPolicy()
	{
	}

	PostBuildPolicy::PostBuildPolicy(const PostBuildPolicy &ref)
	{(void)ref;}

	PostBuildPolicy &PostBuildPolicy::operator=(const PostBuildPolicy &ref)
	{
		(void)ref;
		return (*this);
	}

	IResponse		*PostBuildPolicy::buildResponse(IRequest *request)
	{
		(void) request;
		IResponse *response = NULL;
		std::cout<<request->getHeader()->to_string()<<std::endl;
		ServerInit *conf = getConfig();
		applyConfig(conf);
		LocationInit *location = extensionCheck(request, conf);
		if (!location)
			location = getCorrectLocation(request->getHeader()->getPath(), conf);
		if (ifCorrectMethod(request, location))
		{
			if (ifCorrectBodySize(request, location))
			{
				response = redirectToCGI(request, location);
				if(!response) {
					response = generateFile(request);
				}
			} else {
				response = _e_pager.getErrorPage(413);
			}
		} else {
			IResponse *response = _e_pager.getErrorPage(405);
			response->getHeader()->setHeader("allow", location->getArgs().find("limit_except")->second);
			response = _e_pager.getErrorPage(405);
			response->getHeader()->setHeader(h_allow, location->getArgs().find("limit_except")->second);
			return response;
		}
		return response;
	}

	IResponse *PostBuildPolicy::generateFile(IRequest *request)
	{
		std::cout<<_fmngr.getRoot()<<std::endl;
		IHeader *head = new Header(response);
		head->setHTTPV(pRequest->getHeader()->getHTTPVersion());
		head->setResponseCode(405);
		head->setCodeDescription(ft::getCodeDescr(405));
		head->setHeader("allow", "GET, HEAD");
		head->setHeader("connection", "close");
		if (!_fmngr.isFileExisting(request->getHeader()->getURI())) {
			head->setResponseCode(201);
			head->setCodeDescription(ft::getCodeDescr(201));
			head->setHeader(h_content_location, request->getHeader()->getURI());
			head->setHeader(h_content_length, std::to_string(request->getBody()->size()));
			head->setHeader(h_connection, "close");
			creatFile(request);
		} else {
			if (request->getBody()) {
				head->setResponseCode(303);
				head->setCodeDescription(ft::getCodeDescr(303));
				head->setHeader(h_location, "/post_body");
				head->setHeader(h_content_length, std::to_string(request->getBody()->size()));
				head->setHeader(h_connection, "close");
				mutantExistingFile(request);
			} else {
				head->setResponseCode(204);
				head->setCodeDescription(ft::getCodeDescr(204));
				head->setHeader(h_content_location, request->getHeader()->getURI());
				head->setHeader(h_content_length, std::to_string(request->getBody()->size()));
				head->setHeader(h_connection, "close");
				truncExistingFile(request);
			}
		}
		BasicResponse *response = new BasicResponse(head, NULL);
		return response;
	}

	void PostBuildPolicy::creatFile(IRequest *pRequest)
	{
		int fd = pRequest->getBody()->getFd();
		_fmngr.copyFdToFile(pRequest->getHeader()->getURI(),fd);
		ft_close(fd);
	}

	void PostBuildPolicy::mutantExistingFile(IRequest *pRequest)
	{
		int fd = pRequest->getBody()->getFd();
		_fmngr.copyFdToFile(pRequest->getHeader()->getURI(), fd);
		ft_close(fd);
	}

	void PostBuildPolicy::truncExistingFile(IRequest *pRequest)
	{
		_fmngr.getFd(pRequest->getHeader()->getURI(), O_TRUNC);
	}
}