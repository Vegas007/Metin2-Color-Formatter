#! /usr/bin/env python
__author__ = 'VegaS'
__date__ = '2019-02-19'
__version__ = '1.0'
'''
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
'''
class CFF:
	FLAG_NEW_LINE       = 0
	FLAG_NEW_TAB        = 1
	FLAG_NEW_SPACE      = 2
	
	PATTERN_BEGIN       = '|cff'
	PATTERN_END         = '|h|r'
	
	# Flags
	FLAG_DICT = {
		FLAG_NEW_LINE:      '\n',
		FLAG_NEW_TAB:       '\t',
		FLAG_NEW_SPACE:     ' ' 
	}

	# Colors
	COLOR_HEX_DICT = {
		'green':            '#15FF00',
		'blue':             '#00C5FF',
		'banana':           '#E3CF57',
		'chocolate':        '#D2691E',
		'darkred':          '#8B0000',
		'gray':             '#808080',
		'red':              '#FF0000',
		'skyblue':          '#87CEEB',
		'slateblue':        '#6A5ACD',
		'snow':             '#FFFAFA',
		'springgreen':      '#00FF7F',
		'steelblue':        '#4682B4',
		'white':            '#FFFFFF',
		'yellow':           '#FFFF00',
	}
	
	@staticmethod
	def format(tokens, color_name, add_flag = -1):
		def __scatter__(color, src):
			return '{0}{1}{2}{3}{4}'.format(CFF.PATTERN_BEGIN, color, src, CFF.PATTERN_END, CFF.FLAG_DICT.get(add_flag, str()))

		# Get the color as hexadecimal by a specific color name, if doesn't exist = white.
		color_hex = CFF.COLOR_HEX_DICT.get(color_name.lower(), 'white').replace('#', '')
		if len(color_hex) < 6:
			return tokens
			
		hasPatternNumbers = lambda x: isinstance(x, (int, float))

		# Color all the texts of a tuple or list.
		if isinstance(tokens, (tuple, list)):
			objects = []
			for token in tokens:
				objects.append(__scatter__(color_hex, src = token))
			return tuple(objects)
			
		return __scatter__(color_hex, src = tokens)