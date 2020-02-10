# CFGParser
Library for parsing CFG configs in ini-style.

Allows:
	- Boolean variables can be specified as "true" and "false", "on" and "off", "yes" and "no", "1" and "0".
	- Single-line strings with escape sequence characters.
	- Single-line commenting with the symbol ';'
	- Vector values are separated by commas(64, 128, 255).
	- Section inheritance is supported(single for now).
	- File inclde is supported.
	
The syntax is simple:
 ***#include "path_of_the_file_to_include"
 
[section_name]
key = value
key_string = "some text"
key_vector = 53.74, 632.83, 146.013

[section_name] : inherited_section_name
key = value***
