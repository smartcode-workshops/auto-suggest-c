#ifndef TRIE_H
#define TRIE_H

#include "trie_node.h"

typedef struct Trie {
    TrieNode* root;
} Trie;

// 创建Trie
Trie* trie_create();

// 销毁Trie
void trie_destroy(Trie* trie);

// 插入单词
int trie_insert(Trie* trie, const char* word);

// 自动补全
char** trie_auto_suggest(Trie* trie, const char* prefix);

// 获取所有单词
char** trie_get_all_words(Trie* trie);

// 打印Trie结构
void trie_print_structure(Trie* trie);

// 获取拼写建议
char** trie_get_spelling_suggestions(Trie* trie, const char* word);

#endif // TRIE_H
