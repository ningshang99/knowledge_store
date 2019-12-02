//*************************************************
//*
//*
//*
//*
//*
//*
//*
//*************************************************

#ifndef SRC_LAS_SEGMENT_INTERNAL_H_
#define SRC_LAS_SEGMENT_INTERNAL_H_

#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>

class CLogTest_Internal
{
public:
	CLogTest_Internal(boost::function<void(int, std::string)> log_callback);
	~CLogTest_Internal();

	int Start();
	int Stop();

private:
	boost::thread 	*m_pReadPosThr;
	boost::function<void(int nLogType, std::string strLog)> m_log_callback;

private:
	void LogTest();
};
#endif //SRC_LAS_SEGMENT_INTERNAL_H_