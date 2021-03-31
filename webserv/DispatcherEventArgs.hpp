#pragma once
#include <RequestReciever.hpp>
namespace ft
{
	enum disp_event_type
	{
		reading,
		writing,
		timeout,
		conn_close
	};

	enum disp_event_target
	{
		client,
		listener
	};


	struct Dispatcher_event_args
	{
		int					_fd;
		disp_event_type		_type;
		disp_event_target	_target;
		RequestReciever		*_reciever;
		Dispatcher_event_args(int __fd, disp_event_type __type, disp_event_target __targ, RequestReciever *recv) : _fd(__fd), _type(__type), _target(__targ), _reciever(recv){}
	};
}