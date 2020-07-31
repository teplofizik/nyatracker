#include "trackerdata.h"
#include <fstream>
#include <sstream>

typedef struct {
	int         nNumFrame;
	std::string sType;
	std::string sId;
	float       fScore;

	int         nX1;
	int         nY1;
	int         nX2;
	int         nY2;
} TFrameObject;

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}
	
void AddObject(std::vector<TFrameObject> & objects, std::string line)
{
	std::vector<std::string> parts;
	split(line, parts, '\t');

	if(parts.size() > 6)
	{
		if((parts[1] == "car") || (parts[1] == "bus") || (parts[1] == "truck"))
		{
			TFrameObject FO;
			FO.nNumFrame = atoi(parts[0].c_str());
			FO.sType = parts[1];
			FO.nX1 = atoi(parts[2].c_str());
			FO.nY1 = atoi(parts[3].c_str());
			FO.nX2 = atoi(parts[4].c_str());
			FO.nY2 = atoi(parts[5].c_str());
			FO.fScore = strtod(parts[6].c_str(), 0);
			FO.sId = (parts.size() > 7) ? parts[7] : "";
			objects.push_back(FO);
		}
	}
}

std::vector<TFrameObject> LoadTrackerFrames(std::string Filename)
{
	std::ifstream file(Filename);
	std::string str;
	std::vector<TFrameObject> objects;
	 
	while (std::getline(file, str)) {
		AddObject(objects, str);
	}
	return std::move(objects);
}

std::vector<TFrameObject> FilterObjects(std::vector<TFrameObject> & Objects, int FrameId)
{
	std::vector<TFrameObject> res;
	
	for(int i = 0; i < Objects.size(); i++)
	{
		if(Objects[i].nNumFrame == FrameId)
			res.push_back(Objects[i]);
		
		if(Objects[i].nNumFrame > FrameId)
			break;
	}

	return std::move(res);
}

std::string Classes[80] = { "person","bicycle","car","motorbike","aeroplane","bus","train","truck","boat","traffic light","fire hydrant","stop sign","parking meter","bench","bird","cat","dog","horse","sheep","cow","elephant","bear","zebra","giraffe","backpack","umbrella","handbag","tie","suitcase","frisbee","skis","snowboard","sports ball","kite","baseball bat","baseball glove","skateboard","surfboard","tennis racket","bottle","wine glass","cup","fork","knife","spoon","bowl","banana","apple","sandwich","orange","broccoli","carrot","hot dog","pizza","donut","cake","chair","sofa","pottedplant","bed","diningtable","toilet","tvmonitor","laptop","mouse","remote","keyboard","cell phone","microwave","oven","toaster","sink","refrigerator","book","clock","vase","scissors","teddy bear","hair drier","toothbrush"};

int GetObjectType(std::string ObjectType) {
	for(int i = 0; i < 80; i++) {
		if(Classes[i] == ObjectType)
			return i + 1;
	}
}

void AppendObject(std::vector<std::shared_ptr<NyaTracker::Object>> & objects, TFrameObject & FO)
{
	NyaTracker::Rectangle rect(FO.nX1, FO.nY1, FO.nX2 - FO.nX1 + 1, FO.nY2 - FO.nY1 + 1);

	objects.push_back(std::make_shared<NyaTracker::Object>(rect, GetObjectType(FO.sType), FO.fScore, FO.sId));
}

std::vector<TTestFrame> LoadTrackerData(std::string Filename)
{
	std::vector<TTestFrame> Frames;
	
	auto Objects = LoadTrackerFrames(Filename);
	if(Objects.size() > 0)
	{
		int StartFrame = Objects[0].nNumFrame;
		int LastFrame = Objects[Objects.size()-1].nNumFrame;

		printf("From: %d, To: %d\n", StartFrame, LastFrame);
		for(int i = StartFrame; i <= LastFrame; i++)
		{
			TTestFrame Frame;

			Frame.FrameId = i;
			
			auto FrameObjects = std::move(FilterObjects(Objects, i));
			for(int o = 0; o < FrameObjects.size(); o++)
				AppendObject(Frame.objects, FrameObjects[o]);
			
			Frames.push_back(Frame);
		}
	}
	
	return std::move(Frames);
}
