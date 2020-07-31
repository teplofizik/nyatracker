#include "tracker.h"

#ifndef _TRACKERDATA_H
#define _TRACKERDATA_H

	typedef struct {
		int FrameId;
		
		std::vector<std::shared_ptr<NyaTracker::Object>> objects;
	} TTestFrame;

	std::vector<TTestFrame> LoadTrackerData(std::string Filename);

#endif