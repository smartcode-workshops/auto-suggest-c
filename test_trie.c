#include "trie.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_insert_empty_string() {
    Trie* trie = trie_create();
    assert(trie != NULL);
    
    // 测试插入空字符串
    int result = trie_insert(trie, "");
    assert(result == 1); // 当前实现允许空字符串
    
    trie_destroy(trie);
    printf("test_insert_empty_string: PASSED\n");
}

void test_insert_single_word() {
    Trie* trie = trie_create();
    assert(trie != NULL);
    
    // 测试插入单个单词
    int result = trie_insert(trie, "hello");
    assert(result == 1); // 应该成功
    
    // 验证单词确实存在
    char** suggestions = trie_auto_suggest(trie, "hello");
    assert(suggestions != NULL);
    assert(strcmp(suggestions[0], "hello") == 0);
    assert(suggestions[1] == NULL);
    
    // 释放内存
    for (int i = 0; suggestions[i] != NULL; i++) {
        free(suggestions[i]);
    }
    free(suggestions);
    
    trie_destroy(trie);
    printf("test_insert_single_word: PASSED\n");
}

void test_insert_duplicate_word() {
    Trie* trie = trie_create();
    assert(trie != NULL);
    
    // 第一次插入
    int result = trie_insert(trie, "world");
    assert(result == 1);
    
    // 第二次插入相同单词
    result = trie_insert(trie, "world");
    assert(result == 0); // 应该失败
    
    trie_destroy(trie);
    printf("test_insert_duplicate_word: PASSED\n");
}

void test_insert_multiple_words() {
    Trie* trie = trie_create();
    assert(trie != NULL);
    
    const char* words[] = {"apple", "app", "application", "banana", "band"};
    int word_count = sizeof(words) / sizeof(words[0]);
    
    // 插入多个单词
    for (int i = 0; i < word_count; i++) {
        int result = trie_insert(trie, words[i]);
        assert(result == 1);
    }
    
    // 验证所有单词都存在
    for (int i = 0; i < word_count; i++) {
        char** suggestions = trie_auto_suggest(trie, words[i]);
        assert(suggestions != NULL);
        assert(strcmp(suggestions[0], words[i]) == 0);
        
        // 释放内存
        for (int j = 0; suggestions[j] != NULL; j++) {
            free(suggestions[j]);
        }
        free(suggestions);
    }
    
    trie_destroy(trie);
    printf("test_insert_multiple_words: PASSED\n");
}

int main() {
    test_insert_empty_string();
    test_insert_single_word();
    test_insert_duplicate_word();
    test_insert_multiple_words();
    
    printf("All tests passed!\n");
    return 0;
}
