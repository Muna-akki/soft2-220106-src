#include <stdio.h>
#include <stdlib.h>
float calc_magicnumber(int i);

int main(void){
    //float f[4];
    float f[4];
    // 以下に適切な値を設定する
    for(int i=0 ; i<4 ; i++){
        f[i] = calc_magicnumber(i);
        //printf("%f\n",f[i]);
    }
    // "Hello,World\n" と出力してほしい
    printf("%s",(char*)f);
    return 0;
}


//実行環境
/*
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 11.0.3 (clang-1103.0.32.29)
Target: x86_64-apple-darwin20.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
*/