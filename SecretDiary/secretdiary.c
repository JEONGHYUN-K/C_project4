#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "secret123"         // �p�X���[�h
#define DIARY_FILE "secret_diary.txt"// ���L�t�@�C����
#define MAX_LINE 256                 // 1�s�̍ő啶����

int main(void) {
    char inputPassword[100];
    FILE* fp;
    char line[MAX_LINE];

    // �p�X���[�h���͂𑣂�
    printf("�p�X���[�h����͂��Ă�������: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = 0; // ���s������

    // �p�X���[�h���`�F�b�N
    if (strcmp(inputPassword, PASSWORD) != 0) {
        printf("�p�X���[�h���Ⴂ�܂��I�v���O�������I�����܂��B\n");
        return 1;
    }

    // �t�@�C����ǂݏ������[�h�ŊJ��
    fp = fopen(DIARY_FILE, "a+");
    if (fp == NULL) {
        printf("���L�t�@�C�����J���܂���ł����B\n");
        return 1;
    }

    printf("\n=== �閧�̓��L ===\n");

    rewind(fp); // �t�@�C���|�C���^��擪�ɖ߂�

    // fscanf���g����1�s���ǂݍ��ݕ\��
    while (fscanf(fp, " %[^\n]", line) != EOF) {
        printf("%s\n", line);
    }

    printf("\n���L�ɒǋL���Ă��������B�i�I���� Ctrl+D �܂��� Ctrl+Z + Enter�j\n");

    // �ǋL���[�h�Ȃ̂Ńt�@�C�������ɏ�������
    while (fgets(line, sizeof(line), stdin) != NULL) {
        fputs(line, fp);
    }

    printf("���L��ۑ����ďI�����܂��B\n");
    fclose(fp);

    return 0;
}
