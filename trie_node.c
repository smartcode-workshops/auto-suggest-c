#include "trie_node.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 4

TrieNode* trie_node_create(char value) {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (!node) return NULL;
    
    node->value = value;
    node->is_end_of_word = 0;
    node->child_count = 0;
    node->capacity = INITIAL_CAPACITY;
    node->children = (TrieNode**)malloc(node->capacity * sizeof(TrieNode*));
    
    if (!node->children) {
        free(node);
        return NULL;
    }
    
    memset(node->children, 0, node->capacity * sizeof(TrieNode*));
    return node;
}

void trie_node_destroy(TrieNode* node) {
    if (!node) return;
    
    for (int i = 0; i < node->child_count; i++) {
        trie_node_destroy(node->children[i]);
    }
    
    free(node->children);
    free(node);
}

int trie_node_has_child(TrieNode* node, char c) {
    if (!node) return 0;
    
    for (int i = 0; i < node->child_count; i++) {
        if (node->children[i]->value == c) {
            return 1;
        }
    }
    return 0;
}

TrieNode* trie_node_get_child(TrieNode* node, char c) {
    if (!node) return NULL;
    
    for (int i = 0; i < node->child_count; i++) {
        if (node->children[i]->value == c) {
            return node->children[i];
        }
    }
    return NULL;
}

void trie_node_add_child(TrieNode* node, TrieNode* child) {
    if (!node || !child) return;
    
    // 检查是否需要扩容
    if (node->child_count >= node->capacity) {
        int new_capacity = node->capacity * 2;
        TrieNode** new_children = (TrieNode**)realloc(node->children, new_capacity * sizeof(TrieNode*));
        if (!new_children) return;
        
        node->children = new_children;
        node->capacity = new_capacity;
    }
    
    // 添加新子节点
    node->children[node->child_count++] = child;
}
