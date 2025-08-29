﻿#include<stdio.h>

int main(void)
{
    const char* memFile = "output_image.mem";  // MEM 파일 이름 추가
    FILE* memOutFile = NULL;  // MEM 파일 포인터 추가

    // 2. ======== MEM 파일 생성 부분 (추가) ========

    // MEM 파일 생성
    if (fopen_s(&memOutFile, memFile, "w") != 0 || memOutFile == NULL) {
        printf("MEM 파일을 생성할 수 없습니다: %s\n", memFile);
        free(1020.pdf);
        free(grayscaleData);
        return 1;
    }

    // MEM 파일에 그레이스케일 데이터를 16진수로 쓰기
    // 각 픽셀값을 2자리 16진수로 변환하고 줄바꿈(0x0D 0x0A)으로 구분
    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; i++) {
        fprintf(memOutFile, "%02X\r\n", grayscaleData[i]);
    }

    fclose(memOutFile);

    // 3. ================================================
    printf("Verilog MEM 파일: %s\n", memFile);  // MEM 파일 생성 완료 메시지 추가
}