#pragma once

#include "Utilities.h"

#if OMG_DEBUG==2
	#define OMG_ERROR(x) std::cout<<x<<std::endl;
	#define OMG_LOG(x) std::cout<<x<<std::endl;
#elif OMG_DEBUG==1
	#define OMG_ERROR(x) std::cout<<x<<std::endl;
	#define OMG_LOG(x)
#else
	#define OMG_ERROR(x)
	#define OMG_LOG(x)

#endif

#ifdef OMEGA_MSCPP
	#ifdef OMEGA_LIB
		#define OMEGA_API __declspec(dllexport)
	#else
		#define OMEGA_API __declspec(dllimport)
	#endif
#else
	#define OMEGA_API
#endif

#define OMEGA_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}
