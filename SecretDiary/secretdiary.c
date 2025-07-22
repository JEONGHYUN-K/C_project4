#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "secret123"         // パスワード
#define DIARY_FILE "secret_diary.txt"// 日記ファイル名
#define MAX_LINE 256                 // 1行の最大文字数

int main(void) {
    char inputPassword[100];
    FILE* fp;
    char line[MAX_LINE];

    // パスワード入力を促す
    printf("パスワードを入力してください: ");
    fgets(inputPassword, sizeof(inputPassword), stdin);
    inputPassword[strcspn(inputPassword, "\n")] = 0; // 改行を除去

    // パスワードをチェック
    if (strcmp(inputPassword, PASSWORD) != 0) {
        printf("パスワードが違います！プログラムを終了します。\n");
        return 1;
    }

    // ファイルを読み書きモードで開く
    fp = fopen(DIARY_FILE, "a+");
    if (fp == NULL) {
        printf("日記ファイルを開けませんでした。\n");
        return 1;
    }

    printf("\n=== 秘密の日記 ===\n");

    rewind(fp); // ファイルポインタを先頭に戻す

    // fscanfを使って1行ずつ読み込み表示
    while (fscanf(fp, " %[^\n]", line) != EOF) {
        printf("%s\n", line);
    }

    printf("\n日記に追記してください。（終了は Ctrl+D または Ctrl+Z + Enter）\n");

    // 追記モードなのでファイル末尾に書き込み
    while (fgets(line, sizeof(line), stdin) != NULL) {
        fputs(line, fp);
    }

    printf("日記を保存して終了します。\n");
    fclose(fp);

    return 0;
}
