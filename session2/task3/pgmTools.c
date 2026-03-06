#include <stdlib.h>
#include <stdio.h>

int getUserInput(unsigned char *message);
void printMenu(void);
unsigned char **allocateArray(int height, int width);
unsigned char **read(unsigned char *fn, int *a, int *b, int *c);
void printImage(unsigned char **p, int a, int b);
int checkDims(int height, int width);
int checkMaxGrey(unsigned char **pic_arr, int maxGrey, int height, int width);
// int checkPixelCount(unsigned char *fn, int height, int width);

int main(int argc, unsigned char **argv) {
  if (argc != 2) {
    printf("Usage: ./pgmTools image_path\n");
    return 0;
  }

  int height, width, maxGrey;
  unsigned char **img_arr;
  img_arr = read(argv[1], &height, &width, &maxGrey);

  int errCheck = 0;
  errCheck += checkDims(height, width);
  errCheck += checkMaxGrey(img_arr, maxGrey, height, width);
  // errCheck += checkPixelCount(argv[1], height, width);
  if (errCheck != 0) {
    return 1;
  }


  int choice = -1;
  do {
    choice = -1;
    printMenu();
    while (choice < 1)
      choice = getUserInput("Enter choice");

    switch (choice) {
    case 1:
      printImage(img_arr, height, width);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      return 0;
    default:
      printf("Bad choice\n");
      break;
    }
  } while (1);
}

int getUserInput(unsigned char *message) {
  unsigned char buffer[100];
  int choice;
  printf("%s: ", message);
  fgets(buffer, 100, stdin);
  int check = sscanf(buffer, "%d", &choice);
  if (!check) {
    return -1;
  }
  return choice;
}

void printMenu(void) {
  printf("1 - View PGM Image\n");
  printf("2 - Invert Image\n");
  printf("3 - Rotate Image\n");
  printf("4 - Scale Image\n");
  printf("5 - quit\n");
}

unsigned char **allocateArray(int height, int width) {
  unsigned char **array = calloc(height, sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    array[i] = calloc(width, sizeof(unsigned char));
  }

  return array;
}

unsigned char **read(unsigned char *fn, int *a, int *b, int*c) {
  unsigned char temp[10];
  unsigned char maxGrey[10];
  int height, width;
  FILE *f = fopen(fn, "r");
  fscanf(f, "%s ", temp);
  fscanf(f, "%d %d", &height, &width);
  fscanf(f, "%s ", maxGrey);
  unsigned char **pic_arr = allocateArray(height, width);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(f, "%hhd", &pic_arr[i][j]);
    }
  }
  fclose(f);
  *a = height;
  *b = width;
  *c = atoi(maxGrey);
  return pic_arr;
}

void printImage(unsigned char **pic_arr, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d%s", pic_arr[i][j],
             (pic_arr[i][j] < 100) ? (pic_arr[i][j] < 10) ? "   " : "  " : " ");
    }
    printf("\n");
  }
}

int checkDims(int height, int width) {
  if (height > 0 && width > 0) {
    return 0;
  }
  printf("Error: Bad dimensions\n");
  return 1;
}

int checkMaxGrey(unsigned char **pic_arr, int maxGrey, int height, int width) {
  for (int i=0; i<height; i++) {
    for (int j=0; j<width; j++) {
      if (pic_arr[i][j] > maxGrey) {
        printf("Error: Bad maxGrey\n");
        return 1;
      }
    }
  }
  return 0;
}

// int checkPixelCount(unsigned char *fn, int height, int width) {
//   unsigned char tempChar[10];
//   int tempInt;
//   FILE *f = fopen(fn, "r");
//   fscanf(f, "%s ", tempChar);
//   fscanf(f, "%d %d", &tempInt, &tempInt);
//   fscanf(f, "%s ", tempChar);

//   int i, j = 0;
//   while (1) {
//     char val;  
//     fscanf(f, "%hhd", &val);
//     if ((val == NULL && j<width) || (val != NULL && j > width) || (val != NULL && i > height)) {
//       printf("Error: Incorrect amount of pixels\n");
//       return 1;
//     } 
//     if (val == NULL && j == width) {
//       if (i == height - 1) {
//         return 0;
//       }
//       j=0;
//       i++;
//     } else {
//       j++;
//     }
//   }
// }