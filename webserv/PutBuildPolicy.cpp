#include <PutBuildPolicy.hpp>

namespace ft
{
	PutBuildPolicy::PutBuildPolicy()
	{
	}

	PutBuildPolicy::~PutBuildPolicy()
	{
	}

	PutBuildPolicy::PutBuildPolicy(const PutBuildPolicy &ref)
	{(void)ref;}

	PutBuildPolicy &PutBuildPolicy::operator=(const PutBuildPolicy &ref)
	{
		(void)ref;
		return (*this);
	}

	IResponse		*PutBuildPolicy::buildResponse(IRequest *request)
	{
		(void) request;
		Header *head = checkCommingURI(request);
		BasicResponse *response = new BasicResponse(head, NULL);
		return response;
		return _e_pager.getErrorPage(404);
	}

	Header *PutBuildPolicy::checkCommingURI(IRequest *request)
	{
		std::cout<<_fmngr.getRoot()<<std::endl;
		Header *head = new Header(response);
		if (!_fmngr.isFileExisting(request->getURI())) {
			head->setResponseCode(201);
			head->setCodeDescription(ft::getCodeDescr(201));
			head->setHeader("Content-Location", request->getURI());
			creatFile(request);
			return head;
		} else {
			if (request->getBody()) {
				head->setResponseCode(200);
				head->setCodeDescription(ft::getCodeDescr(200));
				mutantExistingFile(request);
				return head;
			} else {
				head->setResponseCode(204);
				head->setCodeDescription(ft::getCodeDescr(204));
				head->setHeader("Content-Location", request->getURI());
				truncExistingFile(request);
				return head;
			}
		}
		return head;
	}

	void PutBuildPolicy::creatFile(IRequest *pRequest)
	{
		int fd = ft::temporaryBody("<p>Новый файл</p>");
		//		IBody *body = pRequest->getBody();
		_fmngr.copyFdToFile(pRequest->getURI(), fd);
		//		Пока что я закрываю FD
		close(fd);
	}

	void PutBuildPolicy::mutantExistingFile(IRequest *pRequest)
	{
		int fd = ft::temporaryBody("<p>Новый новый файл</p>");
		//		IBody *body = pRequest->getBody();
		_fmngr.copyFdToFile(pRequest->getURI(), fd);
		//		Пока что я закрываю FD
		close(fd);
	}

	void PutBuildPolicy::truncExistingFile(IRequest *pRequest)
	{
		_fmngr.getFd(pRequest->getURI(), O_TRUNC);
	}
}