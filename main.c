#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 测试单词数组
const char* test_words[] = {
    "as", "astronaut", "asteroid", "are", "around",
    "cat", "cars", "cares", "careful", "carefully",
    "for", "follows", "forgot", "from", "front",
    "mellow", "mean", "money", "monday", "monster",
    "place", "plan", "planet", "planets", "plans",
    "the", "their", "they", "there", "towards",
    NULL
};

// 打印字符串数组
void print_string_array(char** array) {
    if (!array) {
        printf("No results\n");
        return;
    }
    
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
}

// 释放字符串数组
void free_string_array(char** array) {
    if (!array) return;
    
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    // 创建Trie并插入测试单词
    Trie* trie = trie_create();
    if (!trie) {
        fprintf(stderr, "Failed to create trie\n");
        return 1;
    }
    
    printf("Inserting words into trie...\n");
    for (int i = 0; test_words[i] != NULL; i++) {
        if (!trie_insert(trie, test_words[i])) {
            printf("Failed to insert word: %s\n", test_words[i]);
        }
    }
    
    // 测试自动补全
    printf("\nTesting auto-suggest:\n");
    printf("Words starting with 'pl':\n");
    char** suggestions = trie_auto_suggest(trie, "pl");
    print_string_array(suggestions);
    free_string_array(suggestions);
    
    printf("\nWords starting with 'ca':\n");
    suggestions = trie_auto_suggest(trie, "ca");
    print_string_array(suggestions);
    free_string_array(suggestions);
    
    // 清理
    trie_destroy(trie);
    return 0;
}
