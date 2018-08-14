#ifndef _EVENT_H
#define _EVENT_H

#if 0
class Event_Handler {
	// Abstract base class that serves as the
	// target of the Initiation_Dispatcher.
	public:
	// Hook method that is called back by the
	// Initiation_Dispatcher to handle events.
	virtual int handle_event (Event_Type et) = 0;
	// Hook method that returns the underlying
	// I/O Handle.
	virtual Handle get_handle (void) const = 0;
};
#endif

class Event_Handler 
{
public:
	// Hook methods that are called back by the Initiation
	// Dispatcher to handle particular types of events.
	virtual int handle_accept      	  (void) = 0;
	virtual int handle_input           (void) = 0;
	virtual int handle_output          (void) = 0;
	virtual int handle_timeout         (void) = 0;
	virtual int handle_close (void) = 0;
	// Hook method that returns the underlying
	// I/O Handle.
	virtual Handle get_handle (void) const = 0;
};


class Logging_Acceptor : public Event_Handler 
{
	// Handles client connection requests.
	public:
	// Initialize the acceptor_ endpoint and
	// register with the Initiation_Dispatcher.
	Logging_Acceptor (const INET_Addr &addr);
	// Factory method that accepts a new
	// SOCK_Stream connection and creates a
	// Logging_Handler object to handle logging
	// records sent using the connection.
	virtual void handle_event (Event_Type et);
	// Get the I/O Handle (called by the
	// Initiation Dispatcher when
	// Logging_Acceptor is registered).
	virtual HANDLE get_handle (void) const {
	return acceptor_.get_handle ();
	}
	private:
	// Socket factory that accepts client
	// connections.
	SOCK_Acceptor acceptor_;
};


#endif
