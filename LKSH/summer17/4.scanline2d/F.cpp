#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int32_t BEGIN = 1;
const int32_t NEUTRAL = 0;
const int32_t END = -1;
std::vector<int32_t> RESULT;

template<typename T>
using Row = std::vector<T>;

struct Point{
    int32_t coord, type, id;
};

bool operator<(Point first, Point second) {
    if (first.coord < second.coord) {
        return true;
    } else if (first.coord > second.coord) {
        return false;
    } else {
        if (first.type > second.type) {
            return true;
        } else {
            return false;
        }
    }
}

Point point(const int32_t coord, const int32_t type) {
    return Point {coord, type};
}

int32_t MAX_POINT_ID = -1;
std::istream& operator>>(std::istream& input_stream, Point& random_point) {
    ++MAX_POINT_ID;
    int32_t type = NEUTRAL;
    int32_t id = MAX_POINT_ID;
    int32_t coord;
    input_stream >> coord;
    random_point = Point {coord, type, id};
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Point& point) {
    output_stream << '<' << "Point " << point.coord << '|' << point.type << '>';
    return output_stream;
}

struct Segment{
    Point begin;
    Point end;
};

Segment segment(int32_t begin, int32_t end) {
    if (end < begin) {
        std::swap(begin, end);
    }
    Point begin_point = point(begin, BEGIN);
    Point end_point = point(end, END);
    return Segment {begin_point, end_point};
}

std::istream& operator>>(std::istream& input_stream, Segment& random_segment) {
    int32_t begin, end;
    input_stream >> begin >> end;
    if (begin > end) {
        std::swap(begin, end);
    }
    random_segment = segment(begin, end);
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, Segment segment) {
    output_stream << '<' << "Segment " << segment.begin.coord << '-' << segment.end.coord << '>';
    return output_stream;
}

template<typename T>
std::vector<T> ReadVector(size_t length) {
    std::vector<T> objects(length);
    for (size_t i = 0; i < length; ++i) {
        std::cin >> objects[i];
    }
    return objects;
}

std::vector<Point> SegmentsToPoints(const std::vector<Segment> segments) {
    std::vector<Point> points;
    for (size_t i = 0; i < segments.size(); ++i) {
        points.push_back(segments[i].begin);
        points.push_back(segments[i].end);
    }

    return points;
}

std::vector<int32_t> IntersectionSize(std::vector<Point> points, int32_t point_count) {
    std::vector<int32_t> result(point_count);
    int32_t balance = std::max(points[0].type, 0);
    for (size_t i = 1; i < points.size(); ++i) {
        Point point = points[i];
        balance += point.type;
        if (point.type == NEUTRAL) {
            result[point.id] = balance;
        }
    }
    return result;
}

template<typename T>
void PrintVector(std::vector<T> random_vector) {
    for (size_t i = 0; i < random_vector.size(); ++i) {
        std::cout << random_vector[i];
        if (i < random_vector.size() - 1) {
            std::cout << ' ';
        }
    }
}

template<typename T>
std::vector<T> ConcatinateVector(std::vector<T> first, std::vector<T> second) {
    std::vector<T> result = first;
    for (T elem : second) {
        result.push_back(elem);
    }
    return result;
}

bool operator==(Segment a, Segment b) {
    int32_t begin = std::max(a.begin.coord, b.begin.coord);
    int32_t end = std::min(a.end.coord, b.end.coord);
    int32_t inter = end - begin;
    std::cout << a << ' ' << b << '\n';
    if (inter >= 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<(Segment a, Segment b) {
    if (a.end.coord < b.begin.coord) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m;
    std::cin >> m >> n;
    std::set<Segment> set;
    for (int32_t i = 0; i < n; ++i) {
        Segment seg;
        std::cin >> seg;
        auto found = set.find(seg);
        while ((found) != set.end()) {
            //std::cout << *found << '\n';
            set.erase(found);
            found = set.find(seg);
        }
        set.insert(seg);
    }
    std::cout << set.size();
    std::cout << '\n';

    return 0;
}