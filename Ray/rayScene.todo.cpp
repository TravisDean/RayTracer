#include "rayScene.h"
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

///////////////////////
// Ray-tracing stuff //
///////////////////////

Point3D RayScene::Reflect(Point3D v,Point3D n){
	return Point3D();
}

int RayScene::Refract(Point3D v,Point3D n,double ir,Point3D& refract){
	return 0;
}

Ray3D RayScene::GetRay(RayCamera* cam,int i,int j,int width,int height){
	static double d = (height / 2) / tan(cam->heightAngle);
	static double widthAngle = cam->heightAngle * cam->aspectRatio;
	static Point3D p0 = cam->position;
	static Point3D pBL = p0 + cam->direction.scale(d) - 
		cam->up.scale(d * tan(cam->heightAngle)) - cam->right.scale(d * tan(widthAngle));

	Point3D iMod = cam->up * ((i + 0.5) / height) * 2 * d *tan(cam->heightAngle);
	Point3D jMod = cam->right * ((j + 0.5) / width) * 2 * d*tan(widthAngle);
	Point3D pixel = pBL + iMod + jMod;

	return Ray3D(p0, pixel);
}

/* Uses a Point3D to store the RGB color values of the color found. */
Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	vector<RayIntersectionInfo> hits;
	for (int i = 0; i < group->shapeNum(); i++) {
		auto shp = group->shapes[i];
		double tb = shp->bBox.intersect(ray);
		if (tb == -1) {		//TODO: Change when bounding boxes work.
			RayIntersectionInfo info;
			double ts = shp->intersect(ray, info);
			if (ts != -1) {
				hits.push_back(info);
			}
		}
	}
	// Needs to be changed to sort on dist to camera
	if (hits.size() != 0) {
		return hits[0].iCoordinate;
	}

	return Point3D(130, 180, 20);
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
}
void RayTexture::setUpOpenGL(void){
}
