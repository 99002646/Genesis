#include"stlpoint.h"
#include"point.h"
#include<list>
#include<iostream> 
#include<algorithm>  
#include<utility>

void STLPoint:: addPoint(int x,int y)
{
	points.push_back(Point(x,y));
}


void STLPoint::displayAll()
{
	std::list<Point>::iterator iter;
   	for(iter=points.begin();iter!=points.end();++iter)
       		iter->display();
}
   

int STLPoint::countAll(Quadrant e1){
	int count=0;
	count = std::count_if(points.begin(),points.end(),[e1](const Point &ref){return ref.quadrant()==e1;});
	return count;		
}
   
int  STLPoint::displayPointOnCircle(int r){
	int count=0;
	count = std::count_if(points.begin(),points.end(),[r](const Point &ref)
														{
															return (  (ref.getx()*ref.getx())  +  (ref.gety()*ref.gety()) == (r*r) ); 
														} );
	return count;	
}
   

int  STLPoint::displayPointinCircle(int r){
	int count=0,x,y;
	count = std::count_if(points.begin(),points.end(),[r](const Point &ref)
														{
															return (  (ref.getx()*ref.getx())  +  (ref.gety()*ref.gety()) < (r*r) ); 
														} );
	return count;
}
