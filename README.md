# Metin2-Colour-Formatter
	A simple class which convert the values into a string by a specific color name.
	
	= Python Color Constants Module:
		https://www.webucator.com/blog/2015/03/python-color-constants-module/
		https://www.color-hex.com/color/ccffff

	= Ex-How-To-Use:
		text = CFF.format('Metin2', 'green')
		text = CFF.format(8000, 'banana')
		text = CFF.format(412.55, 'red')
		
		text = CFF.format(('a', 'b', 'c'), 'red') 
			* return a tuple list | text[0], text[1], text[2]
			
		text = CFF.format('Item name:', 'springgreen', CFF.FLAG_NEW_TAB) + CFF.format(item.GetItemName(), 'chocolate')
