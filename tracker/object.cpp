
#include "object.h"

using namespace NyaTracker;

/* Класс точки */
Point::Point(float X, float Y) {
	this->X = X;
	this->Y = Y;
}

/* Класс прямоугольничка */
Rectangle::Rectangle(int X, int Y, int W, int H) : X(X), Y(Y), Width(W), Height(H) {
	
}

Rectangle::Rectangle(Rectangle & R) : X(R.X), Y(R.Y), Width(R.Width), Height(R.Height) {
	
}

/* Класс объекта */
Object::Object(int X, int Y, int W, int H, int Type, float Prob, std::string Id) : Rect(X, Y, W, H), Type(Type), Prob(Prob), Id(Id) {
	
}

Object::Object(Rectangle R, int Type, float Prob, std::string Id) : Rect(R), Type(Type), Prob(Prob), Id(Id) {
	
}

std::shared_ptr<Point> Object::getTrackedPoint() {
	return std::make_shared<Point>(this->Rect.X + this->Rect.Width / 2, this->Rect.Y + this->Rect.Height * 0.8f);
}