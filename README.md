# LCD-Display
A very simple but rather long program based on a challenge on Steven S. Skiena and Miguel A. Revilla's book 'Programming Challenges'.
The program prompts for input in the format [size] [number(s)] and prints the number(s) in an LCD-like style
There must be one space between the two numbers and letters are not supported.

6/Jan/2024 Update:
Improved input handling
Any size supported as long as it doesent cause an overflow
few minor changes in code (optimisations, changing names etc)

Some info about the 'map' that the program uses:
Basically, there is a map, which is a 2d array of chars, this map represents the 2d-array of pixels on a real LCD screen, each char on the   map represents a pixel of a real LCD screen.
The write_char_to_map method accepts an int called index as one of it's arguments, this is because it needs to know the position the         current char being processed was at in the line, for example if the line was '2047', and the current char being processed was '0', the       index will be 1, this will tell the write_char_to_map method to write a '0' to the map right next to the previous number written ('2' in     this case), the write_char_to_map and draw_number_segment method and have to perform some calculations to ensure that they are writting c    chars to the correct position on the map to replicate the user's input.
