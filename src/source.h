#ifndef SOURCE_DOT_H    /* This is an "include guard" */
#define SOURCE_DOT_H    /* prevents the file from being included twice. */

#define VGA_ADDRESS 0xB8000   


#define BLACK 0
#define GREEN 2
#define RED 4
#define YELLOW 14
#define WHITE_COLOR 15

unsigned short* terminal_buffer;
unsigned int vga_index;

void print_string(char* str, unsigned char color);
void print_char(char str, unsigned char color);
void clear_screen(void);

#endif /* FOO_DOT_H */