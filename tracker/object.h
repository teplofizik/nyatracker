// Nya tracker
// 

#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>
#include <memory>

namespace NyaTracker {

	// Представление точки
	class Point {
		public:
			float X;
			float Y;
			
		public:
			Point(float X, float Y);
	};
	
	// Представление прямоугольника
	class Rectangle {
		public:
			float X;      // Координата X верхнего левого угла
			float Y;      // Координата Y верхнего левого угла
			float Width;  // Ширина
			float Height; // Высота
			
		public:
			Rectangle(int X, int Y, int W, int H);
			Rectangle(Rectangle & R);
	};

	// Класс для описания объекта, входного и выходного
	class Object {
		public:
			Rectangle Rect;
			
			int         Type;
			float       Prob;
			std::string Id; // Детектируемый объект не имеет идентификатора
		
		public:
			Object(int X, int Y, int W, int H, int Type, float Prob, std::string Id);
			Object(Rectangle R, int Type, float Prob, std::string Id);
		
		public:
			// Точка для представления положения объекта (X: середина, Y: 0.8 от верха)
			std::shared_ptr<Point> getTrackedPoint();
	};
	
};

#endif
