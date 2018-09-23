#include "block.h"
#include <vector>
#include <iostream>



/**
 * Returns the width of the current Block
 * */
int Block::width() const {
    return data.size();
}

/**
 * Returns the height of the current Block
 * */
int Block::height() const {
    return data[0].size();
}

/**
 * From ims, grab the vertical strip of pixels whose
 * upper left corner is at position (column,0) whose
 * width is @param width
 * */

void Block::build(PNG & img, int column, int width) {
    unsigned height = img.height();
    vector<HSLAPixel> tempVector;

    for (int x = column; x < column + width; x++) {
        tempVector.clear();
        for (unsigned y = 0; y < height; y++) {
            tempVector.push_back(*(img.getPixel(x,y)));
        }
        data.push_back(tempVector);
    }
}

/** 
 * Draws the current block at position (column,0) in im
 * */
void Block::render(PNG & im, int column) const {
    for (unsigned x = 0; x < data.size(); x++) {
        for (unsigned y = 0; y < data[0].size(); y++) {
            HSLAPixel* imgPixel = im.getPixel(x + column,y);
            *imgPixel = data[x][y];
        }
    }
}

/**
 * Change the saturation of every pixel in the block to 0
 * */
void Block::greyscale() {
    for (unsigned x = 0; x < data.size(); x++) {
        for (unsigned y = 0; y < data[0].size(); y++) {
            data[x][y].s = 0;
        }
    }
}