//*************************************************
//*
//*
//*
//*
//*
//*
//*
//*************************************************

#include "logTest_Internal.h"

CLogTest_Internal::CLogTest_Internal(boost::function<void(int, std::string)> log_callback)
{
	m_log_callback = log_callback;
}

CLogTest_Internal::~CLogTest_Internal()
{
	if (m_pReadPosThr) {
	    m_pReadPosThr->join();
	    delete m_pReadPosThr;
	    m_pReadPosThr = NULL;
	}
}

int CLogTest_Internal::Start()
{
	m_pReadPosThr = new boost::thread(boost::bind(&CLogTest_Internal::LogTest, this));
}

int CLogTest_Internal::Stop()
{
	
}

void CLogTest_Internal::LogTest()
{
	while(true)
	{
		std::string strLog("Hello! Here is Log Test!");
		m_log_callback(1,strLog);
		sleep(2);
	}
}
