## Edit Function:

The edit function in utils.c facilitates the modification of bitmap (BMP) files. Here's a step-by-step explanation of its operations:

--> It opens the specified file path and reads the bmp_fileheader and bmp_infoheader structures using fread.

--> Memory is allocated for the pixel map based on the height and width of the BMP file.

--> The function calculates padding bytes required for proper alignment of pixel data.

--> It reads the pixel data from the file into the allocated memory.

## Save Function:

The save function in utils.c is responsible for saving modifications made to a BMP file. Here's how it operates:

--> It writes the bmp_fileheader and bmp_infoheader structures to the output file using fwrite.

--> Pixel data from the modified pixel map is written to the output file, along with any necessary padding bytes for alignment.

## Free_Quit Function:

The free_quit function in utils.c handles memory deallocation and program termination. Here's what it does:
It frees the memory allocated for the pixel map, ensuring proper cleanup before program exit.

## Insert_Image Function:

The insert_image function inserts an image into the specified coordinates within the pixel map, allowing for seamless integration of additional content into the BMP file.

## Fill Function:

The fill function recursively fills neighboring pixels with a specified color, starting from a given coordinate. This operation is useful for various image manipulation tasks, such as flood filling areas with a specific color.
## Additional Definitions:
Color: Represents the color of the initial pixel set by the set command.

Color2: Represents the color of the current pixel being processed during the fill operation.

## BMP_Header:

Defines structures for the bmp_fileheader, bmp_infoheader, and RGB color components, necessary for handling BMP file data.
## main.c:

In main.c, the functions defined in utils.c are called based on commands entered via keyboard input.
The program executes the corresponding function depending on the command provided, allowing users to edit, save, insert images, set colors, fill areas, or quit the program gracefully.
