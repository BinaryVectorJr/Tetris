#pragma once
#include <raylib.h>
#include <vector>

// "extern" allows us to declare a variable in one file and use it in another
// "const" specifies that the value of the variable cannot change during program execution
extern const Color darkGray;
extern const Color red;
extern const Color blue;
extern const Color yellow;
extern const Color green;
extern const Color orange;
extern const Color purple;
extern const Color cyan;

std::vector<Color> GetCellColors();