#include "Image.h"
#include "Dxlib.h"

std::map<std::string, int> Image::imgMap;

Image::~Image() {

}

int Image::read(const char* imgPass) {
	if (imgMap.find(imgPass) == imgMap.end())
		imgMap[imgPass] = LoadGraph(imgPass);

	return imgMap[imgPass];
}

void Image::clear() {
	InitGraph();
	imgMap.clear();
}