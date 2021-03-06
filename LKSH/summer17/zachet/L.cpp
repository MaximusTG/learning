#include <iostream>
#include <vector>
#include <cmath>

const int32_t RIGHT = 1;
const int32_t LEFT = -1;
const double PI = 3.1415926535;
const double eps = 1e-6;

struct Vector {
    double x, y;

    double length() {
        return std::sqrt(this->x * this->x + this->y * this->y);
    }

    void rotate90(int32_t direction) {
        double new_x = 0, new_y = 0;
        new_x = -this->y * direction;
        new_y = this->x * direction;
        this->x = new_x;
        this->y = new_y;
    }

    Vector rotated90(int32_t direction) {
        Vector new_vector = *this;
        new_vector.rotate90(direction);
        return new_vector;
    }

    void set_length(double new_length) {
        double new_x = this->x * new_length / this->length(), new_y = this->y * new_length / this->length();
        this->x = new_x;
        this->y = new_y;
    }
};

struct Point : Vector{
    double x, y;
};

struct Line {
    Point point;
    Vector direction;
};

struct Circle {
    Point center;
    double radius;
};

// Input and Output
std::istream& operator>>(std::istream& input_stream, Vector& vector) {
    input_stream >> vector.x >> vector.y;
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Vector& vector) {
    output_stream << vector.x << ' ' << vector.y;
    return output_stream;
}

std::istream& operator>>(std::istream& input_stream, Point& point) {
    input_stream >> point.x >> point.y;
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Point& point) {
    output_stream << point.x << ' ' << point.y;
    return output_stream;
}
// ================

// Operators
Vector operator+(const Vector& first, const Vector& second) {
    return Vector{first.x + second.x, first.y + second.y};
}

Vector operator-(const Vector& first, const Vector& second) {
    return Vector{first.x - second.x, first.y - second.y};
}

Vector operator-(const Point& first, const Point& second) {
    return Vector{first.x - second.x, first.y - second.y};
}

Point operator+(const Point& point, const Vector& vector) {
    double  new_x = point.x + vector.x, new_y = point.y + vector.y;
    Point new_point;
    new_point.x = new_x;
    new_point.y = new_y;
    return new_point;
}

Vector operator*(const double coef, const Vector& vector) {
    return Vector{vector.x * coef, vector.y * coef};
}

Vector operator*(const Vector& vector, const double coef) {
    return Vector{vector.x * coef, vector.y * coef};
}

Vector operator/(const Vector& vector, const double coef) {
    return Vector{vector.x / coef, vector.y / coef};
}

bool operator<(Point& first,  Point& second) {
    if (first.x < second.x) {
        return false;
    } else if (first.x > second.x) {
        return true;
    } else {
        if (first.y < second.y) {
            return true;
        } else {
            return false;
        }
    }
}
// =========

// Dot and vector Product
double operator*(const Vector& first, const Vector& second) {
    return first.x * second.x + first.y * second.y;
}

double operator%(const Vector& first, const Vector& second) {
    return first.x * second.y - second.x * first.y;
}
// ======================

// Functions
double VectorVectorAngle(Vector first, Vector second) {
    return std::atan2(first % second, first * second) / PI * 180;
}

double PointPointDistance(Point first, Point second) {
    return (first - second).length();
}

double PointLineDistance(Point point, Line line) {
    return std::abs(((point - line.point) % line.direction) / line.direction.length());
}

Point PerpendicularPoint(Point point, Line line) {
    double distance = PointLineDistance(point, line);
    Vector new_direction;
    if ((point - line.point) % line.direction > 0) {
        new_direction = line.direction.rotated90(RIGHT);
    } else {
        new_direction = line.direction.rotated90(LEFT);
    }
    new_direction.set_length(distance);
    return point + new_direction;
}

bool PointSegmentProects(Point point, Line segment) {
    Point segment_begin = segment.point;
    Point segment_end = segment_begin + segment.direction;
    if (segment_end < segment_begin) {
        std::swap(segment_begin, segment_end);
    }
    double x = point.x, y = point.y, x1 = segment_begin.x, y1 = segment_begin.y, x2 = segment_end.x, y2 = segment_end.y;
    return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

double PointSegmentDistance(Point point, Line segment) {
    Point segment_begin = segment.point;
    Point segment_end = segment_begin + segment.direction;
    if (segment_end < segment_begin) {
        std::swap(segment_begin, segment_end);
    }
    if (PointSegmentProects(point, Line{segment_begin, segment_end - segment_begin})) {
        return PointLineDistance(point, segment);
    } else {
        return std::min(PointPointDistance(point, segment_begin), PointPointDistance(point, segment_end));
    }
}

std::pair<Point, Point> LineCirculeInterseption(Line line, Circle circle) {
    double distance = PointLineDistance(circle.center, line);
    Point point_to_shift_from = PerpendicularPoint(circle.center, line);
    if (std::abs(distance - circle.radius) < eps) {
        return {point_to_shift_from, point_to_shift_from};
    }
    double shift = std::sqrt(distance * distance + circle.radius * circle.radius);
    Vector new_direction = line.direction;
    new_direction.set_length(shift);
    std::pair<Point, Point> result;
    result.first = point_to_shift_from + new_direction;
    result.second = point_to_shift_from + (-1 * new_direction);
    return result;
}

bool LineSegmentIntersepts(Line line, Line segment) {
    Point segment_begin = segment.point;
    Point segment_end = segment_begin + segment.direction;
    if (std::abs(distance - circle.radius) < eps) {
        return {point_to_shift_from, point_to_shift_from};
    }
    if (((segment_begin - line.point) % line.direction > 0) != ((segment_end - line.point) % line.direction > 0)) {
        return true;
    } else {
        return false;
    }
}

int32_t Square(std::vector<Point> points) {
    double square = 0;
    for (int32_t i = 0; i < points.size(); ++i) {
        square 
    }
}
// =========

int main() {
    Point point;
    point.x = 0, point.y = 0;
    Circle circle {point, 1};
    Point point1;

    point1.x = 0, point1.y = 1;
    Line line{point1, Vector{1, 0}};
    std::cout << LineCirculeInterseption(line, circle).first << '\n';

    return 0;
}