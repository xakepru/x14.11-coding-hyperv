
//#define DBG 0

#include "Ntifs.h"

#define DBG_PRINT_LEVEL DPFLTR_ERROR_LEVEL
#define DbgLog(format, value) { DbgPrintEx(DPFLTR_IHVDRIVER_ID, DBG_PRINT_LEVEL,"%-50s [%08X]\n", format, value ); } 
#define DbgLog16(format, value) { DbgPrintEx(DPFLTR_IHVDRIVER_ID, DBG_PRINT_LEVEL,"%-50s [%016I64X]\n", format, value ); } 
#define DbgPrintString(value)  { DbgPrintEx(DPFLTR_IHVDRIVER_ID, DBG_PRINT_LEVEL,"%s \n", value ); } 

typedef struct _MY_DEVICE_EXTENSION
{
	PDEVICE_OBJECT	fdo;
	UNICODE_STRING	ustrSymLinkName; 
} MY_DEVICE_EXTENSION, *PMY_DEVICE_EXTENSION;


#define IOCTL_VMCALL CTL_CODE( \
	FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define INTERCEPTION_CODE CTL_CODE( \
	FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define INTERRUPT_CODE CTL_CODE( \
	FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)

