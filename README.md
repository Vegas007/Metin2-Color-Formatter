
# Metin2 Color Formatter
A simple class writted for Python and C++ which convert the param-values into an string by a specific color rgb as hexadecimals.

 - **Color constants module:**
	```css
	https://www.webucator.com/blog/2015/03/python-color-constants-module/
	https://www.color-hex.com/color/ccffff
	```
 - **Python:**
	```py
	from cff import CFF
	text = CFF.format('Metin2', 'green')
	text = CFF.format(8000, 'banana')
	text = CFF.format(412.55, 'red')
	text = CFF.format('Pending', '#113355')
	text = CFF.format('Item name:', 'springgreen', CFF.FLAG_NEW_TAB) + CFF.format(item.GetItemName(), 'chocolate')
	text = CFF.multi_format(('a', 'b', 'c'), 'red') # text[0], text[1], text[2]
	```
 - **C++:**
	```c++
	#include "cff.h"
	std::string text = CFF::format("Metin2", "green");
	std::string text = CFF::format(std::to_string(8000), "banana");
	std::string text = CFF::format(std::to_string(412.55), "red");
	std::string text = CFF::format("Pending", "#113355");
	std::string text = CFF::format("Item name:", "springgreen", CFF::FLAG_NEW_TAB) + CFF::format(pItemData->GetName(), "chocolate");

	std::vector<string> text = CFF::multi_format({"a", "b", "c"}, "red"); // text[0], text[1], text[2]
	```


