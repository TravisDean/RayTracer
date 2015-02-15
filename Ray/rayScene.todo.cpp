#include "rayScene.h"
#include <GL/glut.h>
#include <math.h>


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
	static Point3D pBL = p0 + cam->direction.scale(d) - cam->up.scale(d * tan(cam->heightAngle)) - cam->right.scale(d * tan(widthAngle));

	Point3D iMod = cam->up * ((i + 0.5) / height) * 2 * d *tan(cam->heightAngle);
	Point3D jMod = cam->right * ((j + 0.5) / width) * 2 * d*tan(widthAngle);
	Point3D pixel = pBL + iMod + jMod;

	return Ray3D(p0, pixel);
}

/* Uses a Point3D to store the RGB color values of the color found. */
Point3D RayScene::GetColor(Ray3D ray,int rDepth,Point3D cLimit){
	return Point3D(130, 180, 20);
}

//////////////////
// OpenGL stuff //
//////////////////
void RayMaterial::drawOpenGL(void){
}
void RayTexture::setUpOpenGL(void){
}
