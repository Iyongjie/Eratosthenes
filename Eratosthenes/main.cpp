//
//  main.cpp
//  Eratosthenes
//
//  Created by mac on 2023/9/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool *prime = (bool *)malloc((n + 1) * sizeof(bool));
    
    // 初始化默认所有数都是质数
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    for (int p = 2; p * p <= n; p++) {
        // 如果 prime[p] 为 true，则它是质数
        if (prime[p] == true) {
            // 将 p 的倍数标记为非质数
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    // 输出所有质数
    printf("质数列表：\n");
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    
    // 释放内存
    free(prime);
}

int main() {
    int n;
    printf("请输入一个正整数 n：");
    scanf("%d", &n);
    
    sieveOfEratosthenes(n);
    
    return 0;
}


