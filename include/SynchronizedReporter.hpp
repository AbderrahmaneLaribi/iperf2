#ifndef SYNCRONIZED_REPORTER_H
#define SYNCRONIZED_REPORTER_H

#include "Settings.hpp"

class SynchronizedReporter {
public :

	static SynchronizedReporter* GetInstance();
	static void Destroy(SynchronizedReporter*);

	void SetSettings(thread_Settings*);
	void SetConnectedThread(thread_Settings*);
	void Run();

	// Reporting methods
	ReportHeader* InitReport( struct thread_Settings *agent );
	void ReportPacket( struct timespec &time );
	void CloseReport( ReportHeader *agent, ReportStruct *packet );

private :
	SynchronizedReporter();
	~SynchronizedReporter();
public :
	static SynchronizedReporter* mInstance;
	thread_Settings* mSettings;
	thread_Settings* mConnectedThread;
};



#endif // SYNCRONIZED_REPORTER_H
