//*************************************************
//*
//*
//*
//*
//*
//*
//*
//*************************************************

#ifndef INCLUDE_ECARX_LAS_SRGMENT_H_
#define INCLUDE_ECARX_LAS_SRGMENT_H_

#ifdef WIN32
	#define ECARX_LAS_SEGMENT_EXPORTS
	#ifdef ECARX_LAS_SEGMENT_EXPORTS
	#define ECARX_LAS_SEGMENT_API __declspec(dllexport)
	#else
	#define ECARX_LAS_SEGMENT_API __declspec(dllimport)
	#endif
#endif

#include <string>

#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>


class CLogTest_Internal;

// This class is exported from the Win32Project1.dll
#ifdef WIN32
class ECARX_LAS_SEGMENT_EXPORTS CLogTest {
#else
class CLogTest {
#endif
public:
	CLogTest(boost::function<void(int, std::string)> log_callback);
	~CLogTest();

	/**
     * @brief Start SDK.
     */
	int Start();

	/**
     * @brief Stop SDK.
     */
	int Stop();

private:
	CLogTest_Internal *m_pCInternal;
};

#endif	//INCLUDE_ECARX_LAS_SRGMENT_H_