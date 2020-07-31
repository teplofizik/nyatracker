// Nya tracker
// 

#ifndef _TRACKER_H
#define _TRACKER_H

#include "object.h"

#include <vector>
#include <memory>

namespace NyaTracker {

	// Base class of trackers
	// Tracker:
	//   SimpleTracker => generate map/field of vectors, autocalc projection translation
	//   MapTracker
	class Tracker {
		
	public:
		// Process detected objects to tracked objects
		// in: detected objects
		// out: tracked objects
		virtual std::vector<std::shared_ptr<Object>> Process(std::vector<std::shared_ptr<Object>> objects) = 0;
	};
	
};

#endif
