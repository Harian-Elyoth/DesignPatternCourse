#include <cmath>

enum class PointType { cartesian, polar };

class Point {
  /*Point(float a, float b, PointType type = PointType::cartesian)
  {
    if (type == PointType::cartesian)
    {
      x = a; b = y;
    }
    else
    {
      x = a*cos(b);
      y = a*sin(b);
    }
  }*/

  // use a factory method
  friend class PointFactory;
  Point(float x, float y) : x(x), y(y) {}

public:
  float x, y;

  friend class PointFactory;
};

class PointFactory {
public:
  static Point NewCartesian(float x, float y) { return Point{x, y}; }

  static Point NewPolar(float r, float theta) {
    return Point{static_cast<float>(r * cos(theta)),
                 static_cast<float>(r * sin(theta))};
  }
};

int main(int argc, char const *argv[]) {
  Point p = PointFactory::NewCartesian(5.0, 6.0);
  return 0;
}
