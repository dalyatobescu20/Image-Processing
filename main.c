#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp_header.h"

#define MAX_COMMAND_LEN 100

int main() {
    RGB **map = NULL;
    bmp_fileheader head = {};
    bmp_infoheader info = {};
    RGB** edit(RGB** , bmp_fileheader* , bmp_infoheader*, char*);
    void freeimage();
    void save(bmp_infoheader* info, bmp_fileheader* head, RGB **map,
             char* path);
    void free_quit(bmp_fileheader *head, bmp_infoheader *info, RGB **map);
    void insert_image(RGB**, bmp_fileheader*, bmp_infoheader*, char*, int, int);
    void set();
    void fill(RGB*** map, bmp_infoheader* info, RGB* color, int y, int x,
            RGB* color2);
    RGB color = {0, 0, 0};
    RGB color2 = {0, 0, 0};
while (1) {
        char command[MAX_COMMAND_LEN];
        scanf("%s", command);

        if (!strcmp(command, "edit")) {
            char path[MAX_COMMAND_LEN];
            scanf("%s", path);
            map = edit(map, &head, &info, path);

        } else if (!strcmp(command, "save")) {
            char path[MAX_COMMAND_LEN];
            scanf("%s", path);
            save(&info, &head, map, path);
        } else if (!strcmp(command, "quit")) {
            free_quit(&head, &info, map);
            exit(EXIT_SUCCESS);
        } else if (!(strcmp(command, "insert"))) {
                char path[MAX_COMMAND_LEN];
                int x = 0, y = 0;
                scanf("%s", path);
                scanf("%u %u", &x, &y);
                insert_image(map, &head, &info, path, y, x);
        } else if (!(strcmp(command, "set"))) {
                char command[MAX_COMMAND_LEN];
                scanf("%s", command);
                if (!strcmp(command, "draw_color")) {
                     scanf("%hhu", &color.B);
                     scanf("%hhu", &color.G);
                     scanf("%hhu", &color.R);
                } else {
                     printf("Command not found\n");
                     return 0;
                }
        } else if (!(strcmp(command, "fill"))) {
                int x = 0, y = 0;
                scanf("%d %d", &y, &x);
                color2.B = map[x][y].B;
                color2.G = map[x][y].G;
                color2.R = map[x][y].R;
                fill(&map, &info, &color, y, x, &color2);
        } else {
                printf("Command not found");
                return 0;
        }
}
}
