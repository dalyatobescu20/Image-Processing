In utils.c:

--> for the edit function: 
    - I read the path file and read the structures from bmp_header (with fread); 
    -Map represents the matrix of pixels; 
    -For Padding I took the formula from stackoverflow 
    -And finally I read the matrix.

-->for the save function: Everything is similar to the edit except that now I write instead of reading 
  -outputfile-->the file where my output will appear
  -I wrote the structures from bmp_header (With fwrite);
  -I wrote the pixel matrix

-->for the free_quit function (a very suggestive name) 
  - I don't really have anything to explain here, I freed the memory for the map with free.

-->color - is the color of the initial pixel set by the set_draw command; 
-->curr - is the current color (pixels from position x, y); 
- if all the neighbors of the pixel are equal, the fill function is called, (ie neighbors x-1, x+1, y-1, y+1);

In bmp_header: - I have put the data for bmp_fileheader and bmp_infoheader; 
               -I added a structure for RGB

In main.c: - I called the functions and depending on what command I read from the keyboard, it executes the functions.
