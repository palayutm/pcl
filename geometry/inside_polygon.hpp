#include "point.hpp"
#include "on_segment.hpp"

// Returns true if p lies within the polygon described by the points in vec. If
// strict false is returned when p is on the edge of the polygon. Answer is
// calculated by counting the number of intersections between the polygon and a
// line going from p to infinity in the positive x-direction. The algorithm uses
// products in intermediate steps so watch out for overflow. If points within
// epsilon from an edge should be considered as on the edge replace the line "if
// (onSegment..." with the comment bellow it (this will cause overflow for int
// and long long).

template <class P>
bool insidePolygon(std::vector<P> vec, const P &p, bool strict = true) {
  int n = 0; // number of isects with line from p to (inf,p.y)
  for (auto i = vec.begin(), j = vec.end() - 1; i != vec.end(); j = i++) {
    // if p is on edge of polygon
    if (onSegment(*i, *j, p)) return !strict;
    // or: if (segDist(*i, *j, p) <= epsilon) return !strict;
    // increment n if segment intersects line from p
    n += (max(i->y, j->y) > p.y && min(i->y, j->y) <= p.y &&
          ((*j - *i).cross(p - *i) > 0) == (i->y <= p.y));
  }
  return n & 1; // inside if odd number of intersections
}
