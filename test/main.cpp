
#include "argparser.h"
#include "trackerdata.h"

#include <thread>
#include <sys/time.h>
#include <opencv2/opencv.hpp>

void TestTracker() {
	auto Data = LoadTrackerData("tracked.txt");
	
	for(int i = 0; i < Data.size(); i++)
	{
		int Time = Data[i].FrameId * 1000 / 25;
	}
}

int main(int argc, char **argv)
{
	ap_Init(argc, argv);
	
	TestTracker();
	return 0;
}
