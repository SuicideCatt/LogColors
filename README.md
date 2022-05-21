# LogColors

Formated text generator for ostream. Works on Windows10+ and Linux.

How to use variant 1
```cpp
#include <LogColors.hpp>
namespace LC = SCT::LogColors;

// Use foreground color
std::cout << LC::fg::yellow << "Test text" << LC::off << '\n';

// Use background color
std::cout << LC::bg::yellow << "Test text" << LC::off << '\n';

// Use light foreground color
std::cout << LC::fg::lightYellow << "Test text" << LC::off << '\n';

// Use light background color
std::cout << LC::bg::lightYellow << "Test text" << LC::off << '\n';

// Use formation text
std::cout << LC::form::bold << "Test text" << LC::off << '\n';

// Use all
std::cout << LC::fg::lightBlue << LC::bg::yellow << LC::form::bold
		  << "Test text" << LC::off << '\n';

// Reset color
std::cout << LC::off;
```
---
How to use variant 2 (Save color and formation configuration)
```cpp
#include <LogColors.hpp>
namespace LC = SCT::LogColors;

// Variant 1
LC::Config conf = ostreamReference 
		<< LC::fg::black << LC::bg::white
		<< "BW colors, Text: " << 1;

// Variant 2
LC::Config conf2{ostreamReference}
conf2 << LC::fg::black << LC::bg::white
	  << "BW colors, Text: " << 1.2;

conf << LC::form::invert << "\nInverted colors, Text: " << 2;
conf << LC::form::italic << "\nItalic, Text: " << 3;
conf << "\nNonItalic, Text: " << 4 << LC::form::bold;
conf << "\nBold, Text: " << 5 << LC::reset;
conf << "\nText: " << 6 << '\n' << LC::off;
```
---
To not use ``SCT::LogColors::ANY``
```cpp
#define USE_SCT_LC
#include <LogColors.hpp>

std::cout << LC::[fg/bg/form]::[ANY];
```
or
```cpp
#define USE_SCT_LOGCOLORS
#include <LogColors.hpp>

std::cout << LogColors::[fg/bg/form]::[ANY];
```
