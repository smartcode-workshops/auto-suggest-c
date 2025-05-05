# SmartCode Workshop 自动推荐系统示例应用（C语言版）

## 概述

在此示例项目中，你将使用C语言开发一个应用程序，该应用程序使用字典树(Trie)实现单词自动完成和拼写建议功能。项目包含完整的Trie数据结构的C语言实现。

## 项目背景

这个自动推荐系统(auto-suggestion)项目使用字典树(trie)数据结构来存储大量单词，实现快速搜索与给定前缀匹配的字词，以提供自动完成功能。项目采用纯C语言实现，具有高效的内存管理和简洁的API接口。

## 项目结构

```
auto-suggest-c/
├── trie_node.h    # Trie节点头文件
├── trie_node.c    # Trie节点实现
├── trie.h         # Trie数据结构头文件
├── trie.c         # Trie数据结构实现
├── main.c         # 测试程序
├── Makefile       # 构建文件
└── .gitignore     # Git忽略规则
```

## 有关字典树(Trie)数据结构

在计算机科学中，trie，又称前缀树或字典树，是一种有序树，用于保存关联数组，其中的键通常是字符串。与二叉查找树不同，键不是直接保存在节点中，而是由节点在树中的位置决定。一个节点的所有子孙都有相同的前缀，也就是这个节点对应的字符串，而根节点对应空字符串。

![](../auto-suggest-java/trie.png)

## 构建与运行

1. 编译项目：
```bash
make
```

2. 运行测试程序：
```bash
./auto_suggest
```

3. 清理构建文件：
```bash
make clean
```

## 环境需求

- GCC编译器
- GNU Make
- Git (可选)

## 示例输出

程序运行后会展示自动补全功能：
```
Inserting words into trie...

Testing auto-suggest:
Words starting with 'pl':
place
plan
planet
planets
plans

Words starting with 'ca':
cat
cars
cares
careful
carefully
```

## 联系我们

如果您有任何问题或建议，请通过以下方式联系我们：

- 网址 https://leansoftx.com
- 电子邮件 info@leansoftx.com
