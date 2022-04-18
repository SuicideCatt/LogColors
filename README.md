# LogColors

String generator for colored text formation

How to use variant 1
```cpp
#include <LogColors.hpp>
namespace LC = SCT::LogColors;

// Use foreground color
std::cout << LC::color(LC::fg(LC::Color::Yellow))
		  << "Test text\n";

// Use background color
std::cout << LC::color(LC::bg(LC::Color::Yellow))
		  << "Test text\n";

// Use light foreground color
std::cout << LC::color(LC::fg(LC::Color::LightYellow))
		  << "Test text\n";

// Use light background color
std::cout << LC::color(LC::bg(LC::Color::LightYellow))
		  << "Test text\n";

// Use formation text
std::cout << LC::color(LC::Formation::Bold)
		  << "Test text\n";

// Use all
std::cout << LC::color(LC::fg(LC::Color::LightBlue), 
			 LC::bg(LC::Color::Yellow), LC::Formation::Bold)
		  << "Test text\n";

// Reset
std::cout << LC::color();
// Or
std::cout << LC::reset;
```
---
How to use variant 2 (**DEFINED**)
```
TFG_BLACK TFORM_ITALIC 
^^~ ^~~~~ ^^~~~ ^~~~~~
12  3     12    3
```
Number	| Value		 | Description
---		| ---		 | ---
1		| T			 | Terminal 
2		| FG/BG/FORM | Foreground/Background/Formation
3		| ANY		 | Color or Formation name
In code:
```cpp
#include <Colors.hpp> /* Colors.hpp used LogColors.hpp */
namespace LC = SCT::LogColors;

// Use foreground color
std::cout << LC::color(TFG_YELLOW)
		  << "Test text\n";

// Use background color
std::cout << LC::color(TBG_YELLOW)
		  << "Test text\n";

// Use light foreground color
std::cout << LC::color(TFG_LightYELLOW)
		  << "Test text\n";

// Use light background color
std::cout << LC::color(TBG_LightYELLOW)
		  << "Test text\n";

// Use formation text
std::cout << LC::color(TFORM_BOLD)
		  << "Test text\n";

// Use all
std::cout << LC::color(TFG_LightBLUE, TBG_YELLOW, TFORM_BOLD)
		  << "Test text\n";

// Reset
std::cout << LC::color();
// Or
std::cout << LC::reset;
```
---
Additionally, you can use std::string
```cpp
#include <Colors.hpp> /* Colors.hpp used LogColors.hpp */
namespace LC = SCT::LogColors;

std::string str = LC::color(TBG_YELLOW, TFORM_BOLD) + "Bold Yellow text" + LC::color();

std::cout << str << '\n';
```
---
To not use ``SCT::LogColors::ANY``
```cpp
#define USE_SCT_LC
#include <LogColors.hpp>
// Or
#include <Colors.hpp> /* Colors.hpp used LogColors.hpp */

std::cout << LC::color();
```
or
```cpp
#define USE_SCT_LOGCOLORS
#include <LogColors.hpp>
// Or
#include <Colors.hpp> /* Colors.hpp used LogColors.hpp */

std::cout << LogColors::color();
```
