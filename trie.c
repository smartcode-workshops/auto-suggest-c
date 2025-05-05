#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Trie* trie_create() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (!trie) return NULL;
    
    trie->root = trie_node_create(' ');
    if (!trie->root) {
        free(trie);
        return NULL;
    }
    
    return trie;
}

void trie_destroy(Trie* trie) {
    if (!trie) return;
    trie_node_destroy(trie->root);
    free(trie);
}

int trie_insert(Trie* trie, const char* word) {
    if (!trie || !word) return 0;
    
    TrieNode* current = trie->root;
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        TrieNode* child = trie_node_get_child(current, c);
        
        if (!child) {
            child = trie_node_create(c);
            if (!child) return 0;
            trie_node_add_child(current, child);
        }
        current = child;
    }
    
    if (current->is_end_of_word) {
        return 0; // 单词已存在
    }
    
    current->is_end_of_word = 1;
    return 1;
}

// 辅助函数：收集所有单词
static void collect_words(TrieNode* node, char* prefix, int prefix_len, char*** words, int* count, int* capacity) {
    if (!node) return;
    
    // 如果当前节点是单词结尾，添加到结果数组
    if (node->is_end_of_word) {
        // 检查是否需要扩容
        if (*count >= *capacity) {
            *capacity *= 2;
            *words = (char**)realloc(*words, *capacity * sizeof(char*));
        }
        
        // 复制当前前缀作为单词
        (*words)[*count] = (char*)malloc(prefix_len + 1);
        strncpy((*words)[*count], prefix, prefix_len);
        (*words)[*count][prefix_len] = '\0';
        (*count)++;
    }
    
    // 递归处理所有子节点
    for (int i = 0; i < node->child_count; i++) {
        prefix[prefix_len] = node->children[i]->value;
        collect_words(node->children[i], prefix, prefix_len + 1, words, count, capacity);
    }
    prefix[prefix_len] = '\0';
}

char** trie_auto_suggest(Trie* trie, const char* prefix) {
    if (!trie || !prefix) return NULL;
    
    // 找到前缀对应的节点
    TrieNode* current = trie->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        current = trie_node_get_child(current, prefix[i]);
        if (!current) return NULL; // 前缀不存在
    }
    
    // 准备收集单词
    int capacity = 10;
    int count = 0;
    char** words = (char**)malloc(capacity * sizeof(char*));
    char* buffer = (char*)malloc(strlen(prefix) + 100); // 足够大的缓冲区
    strcpy(buffer, prefix);
    
    collect_words(current, buffer, strlen(prefix), &words, &count, &capacity);
    
    free(buffer);
    
    // 调整数组大小为实际大小
    words = (char**)realloc(words, (count + 1) * sizeof(char*));
    words[count] = NULL; // 以NULL结尾
    
    return words;
}

// 其他函数实现...
