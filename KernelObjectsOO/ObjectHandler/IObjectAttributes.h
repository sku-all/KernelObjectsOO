#pragma once
#include <string>
#include "ObjectAttributeMask.h"
#include <windows.h>
#include <winternl.h>



namespace OOK
{
	class IObjectAttribute
	{
	public:
		 operator OBJECT_ATTRIBUTES() { return getNativeObject_Attributtes(); }	//support implicit conversion to native

	protected:
		std::wstring m_ObjectName = L"";
		HANDLE m_rootDirectory = NULL;
		ObjectAttributeMask m_objectAttributeMask;
		SECURITY_DESCRIPTOR m_securityDescriptor = {};

	private:
		OBJECT_ATTRIBUTES getNativeObject_Attributtes();
		OBJECT_ATTRIBUTES m_nativeObjectAttribute;
	}; 
}
