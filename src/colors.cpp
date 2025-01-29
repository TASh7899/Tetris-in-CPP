#include "colors.h"

const Color BG = {0, 19, 33, 255};
const Color grid = { 0, 13, 23, 255};
const Color block1 = { 255, 195, 0, 255};
const Color block2 = {255, 87, 51 , 255};
const Color block3 = {199, 0, 57, 255};
const Color block4 = {166, 0, 103, 255};
const Color block5 = {3, 173, 0 , 255};
const Color block6 = {255, 161, 161, 255};
const Color block7 = {188, 161, 255, 255};
const Color GO = {0, 0, 0, 255};
const Color Next = {4, 0, 14, 255};




std::vector<Color> GetColors()
{
    return {grid, block1, block2, block3, block4, block5, block6, block7};
}