#include <stdio.h>
#include <stdlib.h>
#include "bmp_header.h"

#define MAX_COMMAND_LEN 200

RGB** edit(RGB **map, bmp_fileheader *head, bmp_infoheader *info,
              char *path) {
  FILE *fp = fopen(path, "rb");
  if (!fp) {
    fprintf(stdout, "An error occurred finding the file\n");
    exit(1);
  }
  fread(head, sizeof(bmp_fileheader), 1, fp);
  fread(info, sizeof(bmp_infoheader), 1, fp);
  int height = info->height;
  int width = info->width;
  map = malloc(sizeof(RGB*) * height);
  for (int i = 0; i < height; i++) {
       map[i] = calloc(sizeof(RGB), width);
  }
  int pad_bytes = (4 - (3 * width) % 4) % 4;
  fseek(fp, head->imageDataOffset, SEEK_SET);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fread(&map[i][j], sizeof(char), 3, fp);
    }
    fseek(fp, ftell(fp) + pad_bytes, SEEK_SET);
  }
  fclose(fp);
    return map;
}

void save(bmp_infoheader *info, bmp_fileheader *head, RGB **map, char *path) {
  int height = info->height;
  int width = info->width;
  int pad_bytes = (4 - (3 * width) % 4) % 4;
  FILE *outputFile = fopen(path, "wb");
  if (outputFile == NULL) {
    printf("Can't open the file");
    exit(EXIT_FAILURE);
  }
  fwrite (head, sizeof(bmp_fileheader), 1, outputFile);
  fwrite (info, sizeof(bmp_infoheader), 1, outputFile);
  char byte = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fwrite(&map[i][j].R, 1, 1, outputFile);
      fwrite(&map[i][j].G, 1, 1, outputFile);
      fwrite(&map[i][j].B, 1, 1, outputFile);
    }
    for (int j = width; j < width + pad_bytes; j++) {
        fwrite(&byte, sizeof(byte), 1, outputFile);
    }
  }
  fclose(outputFile);
}
void free_quit(bmp_fileheader *head, bmp_infoheader *info, RGB **map) {
  int height = info->height;
  int i = 0;
  for (i = 0; i < height; i++) {
       free(map[i]);
  }
  free(map);
}
void insert_image(RGB **map, bmp_fileheader *head, bmp_infoheader *info,
              char *path, int x, int y) {
    bmp_infoheader info2 = {};
    bmp_fileheader head2 = {};
    int i = 0, j = 0;
    RGB** map2 = NULL;
    map2 = edit(map2, &head2, &info2, path);
    int height = info->height;
    int width = info->width;
    int height2 = info2.height;
    int width2 = info2.width;
     for (i = 0; i < height2; i++) {
         for (j = 0; j < width2; j++) {
             if ((i < height - x) && (j < width - y)) {
                 map[i+x][j+y].R = map2[i][j].R;
                 map[i+x][j+y].G = map2[i][j].G;
                 map[i+x][j+y].B = map2[i][j].B;
             }
         }
     }
}
void fill(RGB*** map, bmp_infoheader* info, RGB* color, int y, int x,
          RGB* color2)
{   int height = info->height;
    int width = info->width;
    RGB curr;
    curr.B = (*(*map + x) + y)->B;
    curr.G = (*(*map + x) + y)->G;
    curr.R = (*(*map + x) + y)->R;
    if (color2->B == curr.B && color2->G == curr.G && color2->R == curr.R) {
       (*(*map + x) + y)->B = color->B;
       (*(*map + x) + y)->G = color->G;
       (*(*map + x) + y)->R = color->R;
    if (x + 1 >= 0 && x + 1 < height && y >= 0 && y < width) {
            fill(map, info, color, y, x + 1, color2);
    }
    if (x - 1 >= 0 && x - 1 < height && y >= 0 && y < width) {
            fill(map, info, color, y, x - 1, color2);
    }
    if (x >= 0 && x < height && y + 1 >= 0 && y + 1 < width) {
            fill(map, info, color, y + 1, x, color2);
    }
    if (x >= 0 && x < height && y - 1 >= 0 && y - 1 < width) {
            fill(map, info, color, y - 1, x, color2);
    }
    }
}
