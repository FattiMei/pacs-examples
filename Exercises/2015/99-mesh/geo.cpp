#include "geo.hpp"

namespace Geometry{
  
  Point::Point(double x, double y){
    M_coor[0]=x; M_coor[1]=y;
  }
  void Point::setCoordinates(double x, double y){
    M_coor[0]=x; M_coor[1]=y;
  }
  void Point::getCoordinates(double & x, double & y) const{
    x=M_coor[0];y=M_coor[1];
  }

  // Definition of the static variable edge
    const int Triangle::M_edge[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    Triangle::Triangle()
    {
        // set pointers to null
        M_points[0] = M_points[1] = M_points[2] = 0;
    }

    Triangle::Triangle(Point & a, Point & b, Point & c)
    {
        M_points[0] = &a;
        M_points[1] = &b;
        M_points[2] = &c;
    }

    Point *Triangle::changePoint(int i, Point & p)
    {
        Point *tmp(M_points[i]);
        M_points[i] = &p;
        return tmp;
    }

    Point & Triangle::edgePoint(int edgenum, int endnum)
    {
        return *(M_points[M_edge[edgenum][endnum]]);
    }

    const Point & Triangle::edgePoint(int edgenum, int endnum) const
    {
        return *(M_points[M_edge[edgenum][endnum]]);
    }

    Triangle::Triangle(const Triangle & t)
    {
    	M_points[0]=t.M_points[0];
    	M_points[1]=t.M_points[1];
    	M_points[2]=t.M_points[2];
    }

    Triangle & Triangle::operator =(const Triangle & t)
    {
    	if (this !=&t){
    	   	M_points[0]=t.M_points[0];
    	    M_points[1]=t.M_points[1];
    	    M_points[2]=t.M_points[2];
    	}
    	return *this;
    }

    int Triangle::edge(int i, int j)
    {
        return M_edge[i][j];
    }

    double Triangle::measure() const
    {
        const Triangle & t = *this;
        return 0.5 *
        		(t[1][0] * (t[2][1] - t[0][1]) +
        		 t[2][0] * (t[0][1] - t[1][1]) +
        		 t[0][0] * (t[1][1] - t[2][1]));
    }

    Point operator -(const Point & a, const Point & b)
    {
    	return Point(a.M_coor[0]-b.M_coor[0],
    			a.M_coor[1]-b.M_coor[1]);
    }

    Point operator +(const Point & a, const Point & b)
    {
    	return Point(a.M_coor[0]+b.M_coor[0],
    			a.M_coor[1]+b.M_coor[1]);
    }

    Point Point::operator *(const double & d) const
    {
    	return Point(d*M_coor[0],d*M_coor[1]);
    }

    Point::Point(const Point & p)    {
        M_coor[0]=p.M_coor[0];
        M_coor[1]=p.M_coor[1];
    }

    Point & Point::operator =(const Point & p)
    {
    	if(this!=&p){
            M_coor[0]=p.M_coor[0];
            M_coor[1]=p.M_coor[1];
    	}
    	return *this;
    }

    Point operator *(const double & d, const Point & p)
    {
        return p*d;
    }
}




