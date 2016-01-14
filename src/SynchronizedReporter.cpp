// Header Include
#include "SynchronizedReporter.hpp"

// Project Includes
#include "headers.h"
#include "List.h"
#include "Extractor.h"
#include "Reporter.h"
#include "Locale.h"

// Definition
SynchronizedReporter* SynchronizedReporter::mInstance = NULL;

SynchronizedReporter* SynchronizedReporter::GetInstance()
{
	if (mInstance != NULL)
	{
		return mInstance;
	}
	mInstance = new SynchronizedReporter();
	return mInstance;
}

void SynchronizedReporter::Destroy(SynchronizedReporter* inInstance)
{
	delete inInstance;
}

SynchronizedReporter::SynchronizedReporter()
{}

SynchronizedReporter::~SynchronizedReporter()
{}



void SynchronizedReporter::SetSettings(thread_Settings* inSettings)
{
	mSettings = inSettings;
}

void SynchronizedReporter::SetConnectedThread(thread_Settings* inConnectedThread)
{
	mConnectedThread = inConnectedThread;
}


void SynchronizedReporter::Run()
{
	bool report = true;
	do {
		// UNIX timestamp
		struct timespec time;
		clock_gettime(CLOCK_REALTIME, &time);

		// Report
		if (time.tv_nsec <= 1000 && report)
		{
			printf("sync reporting at : %lld.%.9ld\n",
					(long long)(time.tv_sec),
	        		time.tv_nsec);
			report = false;
		}
		else if(time.tv_nsec > 100000000)
		{
			report = true;
		}

	} while (1);
}

ReportHeader* SynchronizedReporter::InitReport( struct thread_Settings *agent )
{
	return NULL;
}

void SynchronizedReporter::ReportPacket( ReportHeader *agent, ReportStruct *packet )
{

}

void SynchronizedReporter::CloseReport( ReportHeader *agent, ReportStruct *packet )
{

}
