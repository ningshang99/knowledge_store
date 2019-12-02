//*************************************************
//*
//*
//*
//*
//*
//*
//*
//*************************************************
#include "logTest.h"
#include "logTest_Internal.h"

CLogTest::CLogTest(boost::function<void(int, std::string)> log_callback)
{
	m_pCInternal = new CLogTest_Internal(log_callback);
}

CLogTest::~CLogTest()
{
	if (NULL != m_pCInternal) {
		delete m_pCInternal;
		m_pCInternal = NULL;
	}
}

int CLogTest::Start()
{
	if (NULL == m_pCInternal) {
		printf("Start err:m_pCInternal is NULL!");
		return 0;
	}
	m_pCInternal->Start();
}

int CLogTest::Stop()
{
	if (NULL == m_pCInternal) {
		printf("Stop err:m_pCInternal is NULL!");
		return 0;
	}

	m_pCInternal->Stop();
}