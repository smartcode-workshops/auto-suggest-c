#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    char value;
    int is_end_of_word;
    struct TrieNode** children;  // 子节点指针数组
    int child_count;            // 当前子节点数量
    int capacity;               // 数组容量
} TrieNode;

// 创建新节点
TrieNode* trie_node_create(char value);

// 销毁节点及其所有子节点
void trie_node_destroy(TrieNode* node);

// 检查是否有指定字符的子节点
int trie_node_has_child(TrieNode* node, char c);

// 获取指定字符的子节点
TrieNode* trie_node_get_child(TrieNode* node, char c);

// 添加子节点
void trie_node_add_child(TrieNode* node, TrieNode* child);

#endif // TRIE_NODE_H
