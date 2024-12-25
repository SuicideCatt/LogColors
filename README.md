# LogColors

Colored and formated text generator for std::ostream on C++20.

## Usage
```cpp
#define USE_SCT_LC
#include <LogColors.hpp>
#include <iostream>
// ...
using LC::fg;
using LC::bg;
using LC::form;
std::cout << fg::blue << form::bold << "Blue bold text!" << LC::off << '\n';
std::cout << bg::yellow << form::italic << "Yellow italic text!" << LC::off << '\n';
```

## Supported colors
- 16 colors
	
	![16 colors exemple](img/16_colors.png)
- 256 colors
	
	![256 colors exemple](img/256_colors.png)

## TODO
- [ ] RGB colors palette
- [ ] Add std::wostream support
- [ ] Add RPM package
- [ ] Add Arch package
