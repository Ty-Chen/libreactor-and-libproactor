class Asynch_Stream {
// A Factory for initiating reads and writes
// asynchronously.
public:
// Initializes the factory with information that will
// be used with each asynchronous call. <handler> is
// notified when the operation completes. The async.
// operations are performed on the <handle>. Results
// of the operations are sent to the <Proactor>.
Asynch_Stream (Completion_Handler *handler,
HANDLE handle,
Proactor *);
// This starts off an asynchronous read.
// Upto <bytes_to_read> will be read and
// stored in the <message_block>.
int read (Message_Block &message_block,
u_long bytes_to_read,
const void *act = 0);10
© Douglas C. Schmidt 1998, 1999, all rights reserved, © Siemens AG 1998, 1999, all rights reserved
29.09.1999 Proactor.doc
// This starts off an asynchronous write.
// Upto <bytes_to_write> will be written
// from the <message_block>.
int write (Message_Block &message_block,
u_long bytes_to_write,
const void *act = 0);
class Asynch_Result {
// Bytes transferred by asynchronous operation.
u_long bytes_transferred ();
// Error value if operation failed.
u_long error ();
// Asynchronous Completion Token (ACT)
// associated with the operation.
const void *act ();
};
class Read_Result : public Asynch_Result {
// Read-specific information.
};
class Write_Result : public Asynch_Result {
// Write-specific information
};
};
