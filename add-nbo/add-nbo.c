#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *in1, *in2;
  uint32_t ch;
  uint32_t buffer1[4] = {0,};
  uint32_t buffer2[4] = {0,};
  
  uint32_t bin1 = 0;
  uint32_t bin2 = 0;
  
  if ( (in1 = fopen(argv[1], "rb")) == NULL ) {
    fputs("파일1 열기 에러!", stderr);
    exit(1);
  }

  if ( (in2 = fopen(argv[2], "rb")) == NULL ) {
    fputs("파일2 열기 에러!", stderr);
    exit(1);
  }

  // 이진 파일, 1바이트씩 읽어, 헥사로 출력
  int i = 0;
  while ( (ch = fgetc(in1)) != EOF ) {
    buffer1[i++] = ch;
  }
  i = 0;
  while ( (ch = fgetc(in2)) != EOF ) {
    buffer2[i++] = ch;
  }

  bin1 = (buffer1[0] << 24 | buffer1[1] << 16 | buffer1[2] << 8 | buffer1[3]);

  bin2 = (buffer2[0] << 24 | buffer2[1] << 16 | buffer2[2] << 8 | buffer2[3]);

  printf("%d(%#x) + %d(%#x) = %d(%#x)\n", bin1,bin1,bin2,bin2,(bin1 + bin2),(bin1 + bin2)); 

  fclose(in1); // 파일 닫기
  fclose(in2); // 파일 닫기
  return 0;
}

