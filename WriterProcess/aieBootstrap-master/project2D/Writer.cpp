#include "Writer.h"

///The method HANDLE to a file, which acts like a pointer. If the method fails
///The returned result will be equal to nullptr

///The method has multiple parameters, the first used to specify which file HANDLE
///To use, or we can specify INVALID_HANDLE_VALUE and the method will create a new 
///File for us, which is what we want.

struct MyData
{
	///In all applications, the memory that was allocated by the CreateFileMapping()
	///application is hidden away within a virtual file system. To access it we need to get
	///a temporary pointer to it

	///We set up a pointer by "mapping" it to where the data is stored on the file system.
	///In our example, we had a struct MyData, which may look something like:

	int i;
	float f;
	char c;
	bool b;
	double d;
};

Writer::Writer()
{
	HANDLE fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE,				///A handle to an existing virtual file, or valid
		nullptr,							///Optional security attributes
		PAGE_READWRITE,						///Read/Write access control
		0, sizeof(MyData),					///Size of the memory block,
		L"MySharedMemory");


	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS,
					0, 0, sizeof(MyData));
}


Writer::~Writer()
{
}

