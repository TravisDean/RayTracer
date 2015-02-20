#include <math.h>
#include <GL/glut.h>
#include "rayScene.h"
#include "raySphere.h"

////////////////////////
//  Ray-tracing stuff //
////////////////////////
double RaySphere::intersect(Ray3D ray,RayIntersectionInfo& iInfo,double mx){
	auto L = center - ray.position;
	auto tca = L.dot(ray.direction.unit());
	auto dsq = L.dot(L) - tca*tca;
	auto rsq = radius*radius;
	if (dsq > rsq)
		return -1;
	auto thc = sqrt(rsq - dsq);
	double t0 = tca - thc;
	double t1 = tca + thc;
	
	double t = t0;
	auto N = (center - ray.position) / (center - ray.position).length();
	iInfo.iCoordinate = ray.direction * t;
	iInfo.normal = N;
	iInfo.material = this->material;

//TODO:
	return t0;
}
BoundingBox3D RaySphere::setBoundingBox(void){
	return bBox;
}

//////////////////
// OpenGL stuff //
//////////////////
int RaySphere::drawOpenGL(int materialIndex){
	return -1;
}
