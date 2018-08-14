#include "event.h"

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


class Logging_Handler : public Event_Handler 
{
	// Receive and process logging records
	// sent by a client application.
	public:
	// Initialize the client stream.
	Logging_Handler (SOCK_Stream &cs);
	// Hook method that handles the reception
	// of logging records from clients.
	virtual void handle_event (Event_Type et);
	// Get the I/O Handle (called by the Initiation
	// Dispatcher when Logging_Handler is registered).
	virtual HANDLE get_handle (void) const {
	return this->peer_stream_.get_handle ();
	}
	private:
	// Receives logging records from a client.
	SOCK_Stream peer_stream_;
};


Logging_Acceptor::Logging_Acceptor(const INET_Addr &addr) : acceptor_ (addr) 
{
	// Register acceptor with the Initiation
	// Dispatcher, which “double dispatches” the
	// Logging_Acceptor::get_handle() method to
	// obtain the HANDLE.
	Initiation_Dispatcher::instance ()->
	register_handler (this, ACCEPT_EVENT);
}

void Logging_Acceptor::handle_event (Event_Type et) 
{
	// Can only be called for an ACCEPT event.
	assert (et == ACCEPT_EVENT);
	SOCK_Stream new_connection;
	// Accept the connection.
	acceptor_.accept (new_connection);
	// Create a new Logging Handler.
	Logging_Handler *handler = new Logging_Handler
	(new_connection);
}

